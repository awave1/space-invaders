#ifndef SPACE_INVADERS_MUSIC_H
#define SPACE_INVADERS_MUSIC_H

#include "types.h"

/**
 * Starts playing the song by loading the data for the first note into the PSG
 */
void start_music();

/**
 * Advances to the next note of the song as determined by the amount of time
 * elapsed since the prev. call. The time elapsed is determined by the caller.
 * It is intended that this value is equal to the current value of the vertical blank
 * clock, minus its value when the function was last called.
 * 
 * @param time_elapsed - time elapsed since the prev. call
 */
void update_music(uint32 time_elapsed);

#endif /* SPACE_INVADERS_MUSIC_H */
