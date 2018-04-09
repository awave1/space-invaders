#ifndef SPACE_INVADERS_INTERRUPTS
#define SPACE_INVADERS_INTERRUPTS

#include "vbl.h"
#include "ikbd.h"
#include "music.h"
#include "types.h"

#define VBL_ISR 28
#define IKBD_ISR 70

#define IKBD_RX_DEFAULT 0xfffc96
#define IKBD_RX_INTERRUPT_OFF 0xfffc16

#define MOUSE_STATE_FIRST_PACKET 0
#define MOUSE_STATE_DELTA_X 1
#define MOUSE_STATE_DELTA_Y 2

#define IKBD_BUFFER_SIZE 256



typedef void (*Vector) ();

extern int G_MUSIC_TIMER;
extern int G_GAME_TIMER;
extern int G_SHOT_TIMER;
extern int G_SHOT_MOVE_TIMER;
extern int G_ARMADA_MOVE_TIMER;
extern int G_KEY_REPEAT_TICKS;
extern bool G_RENDER_REQUEST;

extern bool key_repeat;

extern uint8 ikbd_buffer[IKBD_BUFFER_SIZE];
extern unsigned int buff_head;
extern unsigned int buff_tail;

extern Vector vbl_vector;
extern Vector ikbd_vector;


void vbl_req();

void ikbd_req();

Vector install_vector(int num, Vector vector);

void install_vectors();

void install_vectors();

void remove_vectors();

bool ikbd_is_waiting();

void write_to_ikbd_buffer(uint8 scancode);

unsigned long read_from_ikbd_buffer();

void clear_ikbd_buffer();

#endif /* SPACE_INVADERS_INTERRUPTS */
