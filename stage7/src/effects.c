#include "include/effects.h"

void laser_shot_effect() {
  int vol = 16;
  int noise_tone = 31;
  int sustain = 10;

  set_tone(ch_a, 248);
  enable_channel_(MIXER_TONE_CH_A & MIXER_TONE_CH_C, false, false);
  set_volume(ch_a, vol);
  set_envelope(triangle_inv_period, sustain);
}

void explosion_effect(bool is_alien) {
  int vol = 16;
  int noise_tone = 31;
  int sustain = is_alien ? 10 : 30;

  set_noise(noise_tone);
  /*enable_channel(ch_a, false, true);*/
  enable_channel_(MIXER_NOISE_CH_A & MIXER_TONE_CH_C, false, false);
  set_volume(ch_a, vol);
  set_envelope(triangle_inv_period, sustain);
}
