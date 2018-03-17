#include "include/psg.h"

void write_psg(int reg, uint8 val) {
  long old_ssp;
  if (reg_is_valid(reg)) {
    old_ssp = Super(0);

    *psg_reg_select = reg;
    *psg_reg_write = val;

    Super(old_ssp);
  }
}

uint8 read_psg(int reg) {
  return 0;
}

void set_tone(channel_t channel, int tuning) {

}

void set_noise(int tuning) {

}

void set_envelope() {

}

void set_volume(channel_t channel, int vol) {

}

void enable_channel(channel_t channel, bool tone_on, bool noise_on) {

}

void stop_sound() {

}
