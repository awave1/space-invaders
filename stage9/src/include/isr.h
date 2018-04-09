/*
 *  File: isr.h
 *  Authors: Artem Golovin, Daniel Artuso
 */
#ifndef SPACE_INVADERS_INTERRUPTS
#define SPACE_INVADERS_INTERRUPTS

#include "vbl.h"
#include "ikbd.h"
#include "music.h"
#include "render.h"
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
extern bool G_RENDER_MOUSE_REQUEST;

extern uint8 mouse_button;
extern uint8 mouse_delta_y;
extern uint8 mouse_delta_x;
extern bool key_repeat;
extern bool mouse_moved;

extern uint8 ikbd_buffer[IKBD_BUFFER_SIZE];
extern unsigned int buff_head;
extern unsigned int buff_tail;

extern Vector vbl_vector;
extern Vector ikbd_vector;

extern int G_MOUSE_X;
extern int G_MOUSE_Y;
extern bool G_MOUSE_LEFT_CLICK;

extern int prev_mouse_x;
extern int prev_mouse_y;


/**
 * Updates timer
 */
void vbl_req();

/**
 * Processes keyboard and mouse input
 */
void ikbd_req();

/**
 * @brief
 */
void init_mouse(uint16* base);

/**
 * Update the mouse position, and draws cursor
 */
void upd_mouse_events(uint16* base);

/**
 * Installs or remove single vector
 */
Vector install_vector(int num, Vector vector);

/**
 * Installs vector vbl and ikbd vectors
 */
void install_vectors();

/**
 * Removes vector
 */
void remove_vectors();

/**
 * Check if keyboard is waiting for input
 */
bool ikbd_is_waiting();

/**
 * @brief
 */
bool ikbd_mouse_moved();

/**
 * Write keyboard value to keyboard buffer
 * @param: uint8 scancode - key code
 */
void write_to_ikbd_buffer(uint8 scancode);

/**
 * Read keyboard value from keyboard buffer
 */
unsigned long read_from_ikbd_buffer();

/**
 * Clears keyboard buffer
 */
void clear_ikbd_buffer();

#endif /* SPACE_INVADERS_INTERRUPTS */
