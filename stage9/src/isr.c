#include "include/isr.h"

int G_MUSIC_TIMER = 0;
int G_GAME_TIMER = 0;
int G_SHOT_TIMER = 0;
int G_SHOT_MOVE_TIMER = 0;
int G_ARMADA_MOVE_TIMER = 0;
int G_KEY_REPEAT_TICKS = 0;
bool G_RENDER_REQUEST = true;

Vector vbl_vector;
Vector ikbd_vector;

volatile uint8* const ikbd_control = 0xfffc00;
volatile uint8* const ikbd_status = 0xfffc00;
volatile uint8* const ikbd_reader = 0xfffc02;
volatile uint8* const isrb_mfp_register = 0xfffa11;

volatile uint8* const ascii_table = 0xFFFE829C;

uint8 G_IKBD_BUFFER[256];

unsigned int G_IKBD_BUFF_HEAD = 0;
unsigned int G_IKBD_BUFF_TAIL = 0;

int mouse_state = 0;
uint8 mouse_button;
uint8 mouse_delta_x;
uint8 mouse_delta_y;
bool key_repeat = false;

void vbl_req() {
  G_MUSIC_TIMER++;
  G_KEY_REPEAT_TICKS++;
  
  G_GAME_TIMER++;
  G_SHOT_TIMER++;
  G_ARMADA_MOVE_TIMER++;
  G_SHOT_MOVE_TIMER++;

  G_RENDER_REQUEST = true;
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
        mouse_state = 1;
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
  return G_IKBD_BUFF_HEAD != G_IKBD_BUFF_TAIL;
}

void write_to_ikbd_buffer(uint8 scancode) {
  G_IKBD_BUFFER[G_IKBD_BUFF_TAIL] = scancode;
  G_IKBD_BUFF_TAIL++;
}

unsigned long read_from_ikbd_buffer() {
  unsigned long ch;
  long old_ssp = Super(0);

  *isrb_mfp_register &= 0xbf;

  ch = G_IKBD_BUFFER[G_IKBD_BUFF_HEAD];
  ch = ch << 16;
  ch = ch + *(ascii_table + G_IKBD_BUFFER[G_IKBD_BUFF_HEAD++]);

  *isrb_mfp_register |= 0x40; /* turn bit 6 back on */

  Super(old_ssp);
  return ch;
}

void clear_ikbd_buffer() {
  while(ikbd_is_waiting()) {
    G_IKBD_BUFF_HEAD++;
  }
  
  G_IKBD_BUFFER[G_IKBD_BUFF_TAIL] = 0x00;
}
