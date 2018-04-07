#ifndef SPACE_INVADERS_INTERRUPTS
#define SPACE_INVADERS_INTERRUPTS

#include "vbl.h"
#include "music.h"
#include "types.h"

#define VBL_ISR 28

typedef void (*Vector) ();

extern int G_MUSIC_TIMER;
extern int G_GAME_TIMER;
extern int G_SHOT_TIMER;
extern bool G_RENDER_REQUEST;

extern Vector vbl_vector;


void vbl_req();

Vector install_vector(int num, Vector vector);

void install_vectors();

void install_vectors();

void remove_vectors();

#endif /* SPACE_INVADERS_INTERRUPTS */

