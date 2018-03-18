#include "include/effects.h"

void laser_shot_effect() {

}

void explosion_effect() {
  set_noise(EXPLOSION_NOISE_TUNE);
  enable_channel(ch_a, false, true);
  set_volume(ch_a, 11);
}
