#ifndef SPACE_INVADERS_MUSIC_H
#define SPACE_INVADERS_MUSIC_H

#include "psg.h"
#include "types.h"

#define NOTE_C_FLAT 478
#define NOTE_C 451
#define NOTE_D_FLAT 428 
#define NOTE_D 402
#define NOTE_E_FLAT 379
#define NOTE_F_FLAT 358
#define NOTE_F 338
#define NOTE_G_FLAT 319
#define NOTE_G 301
#define NOTE_A_FLAT 284
#define NOTE_A 268
#define NOTE_B_FLAT 253

#define NOTES_SZ 168


typedef struct {
  int freq;
  int duration;
} note_t;

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
bool update_music(uint32 time_elapsed);

#endif /* SPACE_INVADERS_MUSIC_H */
