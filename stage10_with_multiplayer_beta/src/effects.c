/**
 *  File: effects.c
 *  Authors: Artem Golovin, Daniel Artuso
 */
#include "include/effects.h"

void laser_shot_effect() {
  int vol = 16;
  int noise_tone = 25;
  int sustain = 10;

  set_tone(ch_a, 248);
  enable_channel(ch_a, true, false);
  set_volume(ch_a, vol);
  set_envelope(triangle_inv_period, sustain);
}

void explosion_effect(bool is_alien) {
  int vol = 16;
  int noise_tone = 25;
  int sustain = is_alien ? 10 : 30;

  enable_channel(ch_a, false, true);
  set_volume(ch_a, vol);
  set_envelope(triangle_inv_period, sustain);
}
