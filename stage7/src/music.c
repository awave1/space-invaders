#include "include/music.h"

static int current_note = 0;

const int notes[] = { 268, 301, 338, 379 };
const int note_durations[] = { 24, 14, 24, 14 };

void start_music() {
  music_t music;

	set_tone(ch_c, 268);
	enable_channel(ch_c, true, false);
	set_volume(ch_c, 11);
}

bool update_music(uint32 time_elapsed) {
  bool updated = false;

  if (time_elapsed >= note_durations[current_note]) {
    current_note++;
    updated = true;
  }

  if (current_note > (NOTES_SZ - 1))
    current_note = 0;
  
  set_tone(ch_c, notes[current_note]);

  return updated;
}

void _init_music(music_t* music) {
  int i = 0;
  note_t note;
  const int freqs[] = { 268, 301, 338, 379 };
  const int durations[] = { 54, 54, 54, 54 };

  for (i = 0; i < NOTES_SZ; i++) {
    note.duration = durations[i];
    note.freq = freqs[i];
    music->notes[i] = note;
  }
}
