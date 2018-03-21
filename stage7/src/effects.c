#include "include/effects.h"

void laser_shot_effect() {
  set_tone(ch_a, 250);
  enable_channel(ch_a, true, false);
  set_volume(ch_a, 11);
}

void explosion_effect() {
  int vol = 16;
  int noise_tone = 31;
  int sustain = 30;

  set_noise(noise_tone);
  enable_channel(ch_a, false, true);
  set_volume(ch_a, vol);
  set_envelope(triangle_inv_period, sustain);
}
