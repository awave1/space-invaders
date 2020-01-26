/*
 *  Authors: Artem Golovin, Daniel Artuso
 *
 *  Description:
 *      Contains functions for sound effects
 */
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
 * 
 * @param is_alien - true, if want to play effect for alien explosion
 */
void explosion_effect(bool is_alien);

#endif /* SPACE_INVADERS_EFFECTS_H */
