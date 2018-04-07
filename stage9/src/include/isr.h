#ifndef SPACE_INVADERS_INTERRUPTS
#define SPACE_INVADERS_INTERRUPTS

#include "vector.h"
#include "vbl.h"
#include "music.h"
#include "types.h"

extern int G_MUSIC_TIMER;
extern int G_GAME_TIMER;
extern bool G_RENDER_REQUEST;

extern Vector vbl_vector;

void vbl_isr_request();

void install_vectors();

void remove_vectors();

#endif /* SPACE_INVADERS_INTERRUPTS */

