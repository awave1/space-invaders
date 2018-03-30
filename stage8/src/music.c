#include "include/music.h"

/**
 * checks which note to play. must be osed ONLY within this file, inside
 * update_music function.
 */
static int current_note = 0;

const note_t main_song[] = {
  { 168, 20 },
  { 0,   20 },
  { 201, 20 },
  { 0,   20 },
  { 238, 20 },
  { 0,   20 },
  { 148, 20 },
  { 0,   20 }
};

void start_music() {
  set_envelope(triangle_inv_period, 10);
  enable_channel(ch_c, true, false);
	set_volume(ch_c, 11);
}

bool update_music(uint32 time_elapsed) {
  bool updated = false;

  if (time_elapsed >= main_song[current_note].duration) {
    current_note++;
    updated = true;
  }

  if (current_note > (NOTES_SZ - 1))
    current_note = 0;
  
  set_tone(ch_c, main_song[current_note].freq);

  return updated;
}
