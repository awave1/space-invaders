#include "include/music.h"

static int current_note = 0;

const int notes[NOTES_SZ] =          { 168, 0, 201, 0, 238, 0, 148, 0 };
const int note_durations[NOTES_SZ] = { 20, 20, 20, 20, 20, 20, 20, 20 };

void start_music() {
  music_t music;

  set_envelope(triangle_inv_period, 10);
  enable_channel_(MIXER_TONE_CH_C, false, false);
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
