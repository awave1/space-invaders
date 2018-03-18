#include "include/effects.h"

void laser_shot_effect() {
  set_tone(ch_a, 250);
  enable_channel(ch_a, true, false);
  set_volume(ch_a, 11);
}

void explosion_effect() {
  set_noise(EXPLOSION_NOISE_TUNE);
  enable_channel(ch_a, false, true);
  set_volume(ch_a, 11);
}
