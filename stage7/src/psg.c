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
  switch (channel) {
    case ch_a:
      write_psg(CH_A_TONE, tuning);
      break;
    case ch_b:
      write_psg(CH_B_TONE, tuning);
      break;
    case ch_c:
      write_psg(CH_C_TONE, tuning);
      break;
  }
}

void set_noise(int tuning) {

}

void set_envelope() {

}

void set_volume(channel_t channel, int vol) {
  switch(channel) {
    case ch_a:
      write_psg(CH_A_VOL, vol);
      break;
    case ch_b:
      write_psg(CH_B_VOL, vol);
      break;
    case ch_c:
      write_psg(CH_C_VOL, vol);
      break;
  }
}

void enable_channel(channel_t channel, bool tone_on, bool noise_on) {
  bool tone_only = tone_on && !noise_on;
  bool noise_only = !tone_on && noise_on;
  bool tone_and_noise = tone_on && noise_on;

  switch(channel) {
    case ch_a:
      if (tone_only)
        write_psg(MIXER_REG, MIXER_TONE_CH_A);
      else if (noise_only)
        write_psg(MIXER_REG, MIXER_NOISE_CH_A);
      else if (tone_and_noise)
        write_psg(MIXER_REG, MIXER_TONE_CH_A & MIXER_NOISE_CH_A);
      break;
    case ch_b:
      if (tone_only)
        write_psg(MIXER_REG, MIXER_TONE_CH_B);
      else if (noise_only)
        write_psg(MIXER_REG, MIXER_NOISE_CH_B);
      else if (tone_and_noise)
        write_psg(MIXER_REG, MIXER_TONE_CH_B & MIXER_NOISE_CH_B);
      break;
    case ch_c:
      if (tone_only)
        write_psg(MIXER_REG, MIXER_TONE_CH_C);
      else if (noise_only)
        write_psg(MIXER_REG, MIXER_NOISE_CH_C);
      else if (tone_and_noise)
        write_psg(MIXER_REG, MIXER_TONE_CH_C & MIXER_NOISE_CH_C);
      break;
  }
}

void stop_sound() {
  set_volume(ch_a, 0);
  set_volume(ch_b, 0);
  set_volume(ch_c, 0);
}
