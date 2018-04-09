/*
 *  File: isr.c
 *  Authors: Artem Golovin, Daniel Artuso
 */
#include "include/isr.h"

int G_MUSIC_TIMER = 0;
int G_GAME_TIMER = 0;
int G_SHOT_TIMER = 0;
int G_SHOT_MOVE_TIMER = 0;
int G_ARMADA_MOVE_TIMER = 0;
int G_KEY_REPEAT_TICKS = 0;
bool G_RENDER_REQUEST = true;
bool G_RENDER_MOUSE_REQUEST = false;

Vector vbl_vector;
Vector ikbd_vector;

volatile uint8* const ikbd_control = 0xfffc00;
volatile uint8* const ikbd_status = 0xfffc00;
volatile uint8* const ikbd_reader = 0xfffc02;
volatile uint8* const isrb_mfp_register = 0xfffa11;

volatile uint8* const ascii_table = 0xFFFE829C;

uint8 ikbd_buffer[IKBD_BUFFER_SIZE];
unsigned int buff_head = 0;
unsigned int buff_tail = 0;

int mouse_state = 0;
uint8 mouse_button;
uint8 mouse_delta_x;
uint8 mouse_delta_y;
bool key_repeat = false;
bool mouse_moved = false;

int G_MOUSE_X = 0;
int G_MOUSE_Y = 0;
bool G_MOUSE_LEFT_CLICK = false;
int prev_mouse_x = 0;
int prev_mouse_y = 0;

void vbl_req() {
  G_MUSIC_TIMER++;
  G_KEY_REPEAT_TICKS++;

  G_GAME_TIMER++;
  G_SHOT_TIMER++;
  G_ARMADA_MOVE_TIMER++;
  G_SHOT_MOVE_TIMER++;

  G_RENDER_REQUEST = true;
  G_RENDER_MOUSE_REQUEST = true;
}

void ikbd_req() {
  uint8 scancode;

  *ikbd_control = 0x16;
  /* check if data was recieved */
  if (*ikbd_status & 0x1) {
    scancode = *ikbd_reader;
    if (mouse_state == MOUSE_STATE_FIRST_PACKET) {
      /*
        check if scancode is mouse event 
      */
      if (scancode >= 0xf8) {
        mouse_button = scancode;
        mouse_state = MOUSE_STATE_DELTA_X;

        mouse_moved = scancode == 0xf8;
      } else if ((scancode & 0x80) == 0x00) { /* check if it's a make code */
        write_to_ikbd_buffer(scancode);
        key_repeat = true;
      } else if ((scancode & 0x80) == 0x80) { /* check if it's a break code */
        key_repeat = false;
      }
    } else if (mouse_state == MOUSE_STATE_DELTA_X) { /* delta_x */
      mouse_state = MOUSE_STATE_DELTA_Y;
      mouse_delta_x = scancode;
    } else if (mouse_state == MOUSE_STATE_DELTA_Y) { /* delta_x */
      mouse_state = MOUSE_STATE_FIRST_PACKET;
      mouse_delta_y = scancode;
    }

    *isrb_mfp_register &= 0xbf; /* clear bit 6 */
  }

  *ikbd_control = 0x96;
}

void init_mouse(uint16* base) {
  G_MOUSE_X = 320;
  G_MOUSE_Y = 200;
  prev_mouse_x = G_MOUSE_X;
  prev_mouse_y = G_MOUSE_Y;
  save_mouse_bg(base, G_MOUSE_X, G_MOUSE_Y);
  render_mouse_ptr(base, G_MOUSE_X, G_MOUSE_Y);
}

void upd_mouse_events(uint16* base) {

  G_MOUSE_X += (int) ((char) mouse_delta_x);
  G_MOUSE_Y += (int) ((char) mouse_delta_y);

  if (G_MOUSE_X < 0)
    G_MOUSE_X = 0;
  else if (G_MOUSE_X > 600)
    G_MOUSE_X = 600;

  if (G_MOUSE_Y < 0)
    G_MOUSE_Y = 0;
  else if (G_MOUSE_Y > 380)
    G_MOUSE_Y = 380;

  G_MOUSE_LEFT_CLICK = mouse_button == 0xfa;

  mouse_delta_x = 0;
  mouse_delta_y = 0;

  if (G_RENDER_MOUSE_REQUEST) {
    clear_region(base, prev_mouse_x, prev_mouse_y, 8, 8);
    restore_mouse_bg(base, prev_mouse_x, prev_mouse_y);
    save_mouse_bg(base, G_MOUSE_X, G_MOUSE_Y);
    render_mouse_ptr(base, G_MOUSE_X, G_MOUSE_Y);

    prev_mouse_x = G_MOUSE_X;
    prev_mouse_y = G_MOUSE_Y;

    G_RENDER_MOUSE_REQUEST = false;
  }
}

void install_vectors() {
  vbl_vector = install_vector(VBL_ISR, vbl_isr);
  ikbd_vector = install_vector(IKBD_ISR, ikbd_isr);
}

void remove_vectors() {
  install_vector(VBL_ISR, vbl_vector);
  install_vector(IKBD_ISR, ikbd_vector);
}

Vector install_vector(int num, Vector vector) {
  Vector* vectp = (Vector *) ((long) num << 2);
  Vector orig;
  long old_ssp = Super(0);

  orig = *vectp;
  *vectp = vector;

  Super(old_ssp);
  return orig;
}

bool ikbd_is_waiting() {
  return buff_head != buff_tail;
}

bool ikbd_mouse_moved() {
  return mouse_moved;
}

void write_to_ikbd_buffer(uint8 scancode) {
  if (buff_tail == IKBD_BUFFER_SIZE - 1)
    buff_tail = 0;

  ikbd_buffer[buff_tail] = scancode;
  buff_tail++;
}

unsigned long read_from_ikbd_buffer() {
  unsigned long ch;
  long old_ssp = Super(0);

  if (buff_head == IKBD_BUFFER_SIZE - 1)
    buff_head = 0;


  *isrb_mfp_register &= 0xbf;

  ch = ikbd_buffer[buff_head];
  ch = ch << 16;
  ch = ch + *(ascii_table + ikbd_buffer[buff_head++]);

  *isrb_mfp_register |= 0x40; /* turn bit 6 back on */

  Super(old_ssp);
  return ch;
}

void clear_ikbd_buffer() {
  while(ikbd_is_waiting()) {
    buff_head++;
  }

  ikbd_buffer[buff_tail] = 0x00;
}
