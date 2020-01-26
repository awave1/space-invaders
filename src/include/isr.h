/*
 *  Authors: Artem Golovin, Daniel Artuso
 * 
 *  Note: this file defines number of global variables. To make it
 *        easier to notice them in code, all globals are prefixed with "G",
 *        for example: G_MUSIC_TIMER
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

#define MFB_BIT_6_MASK_ON 0x40
#define MFB_BIT_6_MASK_OFF 0xbf

#define MOUSE_STATE_FIRST_PACKET 0
#define MOUSE_STATE_DELTA_X 1
#define MOUSE_STATE_DELTA_Y 2

#define MOUSE_MOVE_CODE 0xf8
#define MOUSE_LEFT_BUTTON_CODE 0xfa

#define IKBD_BUFFER_SIZE 256

typedef void (*Vector) ();

/*
 * Timers, used by VBL
 */
extern int G_MUSIC_TIMER;
extern int G_GAME_TIMER;
extern int G_SHOT_TIMER;
extern int G_SHOT_MOVE_TIMER;
extern int G_ARMADA_MOVE_TIMER;
extern int G_KEY_REPEAT_TICKS;

/*
 * Render, if followind flags set to true
 */
extern bool G_RENDER_REQUEST;
extern bool G_RENDER_MOUSE_REQUEST;

/*
 * Mouse globals
 */
extern int G_MOUSE_X;
extern int G_MOUSE_Y;

/*
 * true, if left click happened
 */
extern bool G_MOUSE_LEFT_CLICK;

extern uint8 mouse_button;
extern uint8 mouse_delta_y;
extern uint8 mouse_delta_x;
extern int prev_mouse_x;
extern int prev_mouse_y;
extern bool key_repeat;
extern bool mouse_moved;

extern uint8 ikbd_buffer[IKBD_BUFFER_SIZE];
extern unsigned int buff_head;
extern unsigned int buff_tail;
extern uint8 repeated_key;

extern Vector vbl_vector;
extern Vector ikbd_vector;


/**
 * Updates timer on VBL IRQ
 * VBL ISR does following:
 *    - time the page flipping for double buffered graphics;
 *    - time the playing of music;
 *    - time any other synchronous events needed by your game3.
 */
void vbl_req();

/**
 * Processes keyboard and mouse input on IKBD IRQ :
 *    - handles key scancodes
 *    - handles incoming mouse packes
 */
void ikbd_req();

/**
 * Initialize mouse, save background, and plot mouse pointer 
 * 
 * @param base - screen
 */
void init_mouse(uint16* base);

/**
 * Update the mouse position, and draws cursor
 * 
 * @param base - screen
 */
void upd_mouse_events(uint16* base);

/**
 * Installs single vector
 * 
 * @param num - trap number
 * @param vector - vector to install for given trap number
 * 
 * @return original vector
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
 * Check, if keyboard is waiting for input
 */
bool ikbd_is_waiting();

/**
 * Check, if mouse was moved
 */
bool ikbd_mouse_moved();

/**
 * Write keyboard value to keyboard buffer.
 * 
 * @param scancode - key code
 */
void write_to_ikbd_buffer(uint8 scancode);

/**
 * Read keyboard value from keyboard buffer
 * 
 * @return keyboard scancode
 */
unsigned long read_from_ikbd_buffer();

/**
 * Clears keyboard buffer
 */
void clear_ikbd_buffer();

#endif /* SPACE_INVADERS_INTERRUPTS */
