#ifndef SPACE_INVADERS_INTERRUPTS
#define SPACE_INVADERS_INTERRUPTS

#include "vector.h"
#include "vbl.h"
#include "music.h"
#include "types.h"

extern int G_MUSIC_TIMER;
extern int G_GAME_TIMER;
extern bool render_request;

void vbl_isr_request();

#endif /* SPACE_INVADERS_INTERRUPTS */

