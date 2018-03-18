#ifndef SPACE_INVADERS_EFFECTS_H
#define SPACE_INVADERS_EFFECTS_H

#include "psg.h"
#include "types.h"

#define EXPLOSION_NOISE_TUNE 0x11

/**
 * Plays shot effect when called
 */
void laser_shot_effect();

/**
 * Plays an explosion effect when called
 */
void explosion_effect();

#endif /* SPACE_INVADERS_EFFECTS_H */
