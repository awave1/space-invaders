#ifndef SPACE_INVADERS_PSG_H
#define SPACE_INVADERS_PSG_H

#include <osbind.h>
#include "types.h"

#define CH_A_FINE_TUNE 0
#define CH_A_COARSE_TUNE 1
#define CH_A_MIXER 7
#define CH_A_VOL 8

#define reg_is_valid(reg) (reg >= 0 && reg <= 12)

volatile char* psg_reg_select = 0xFF8800;
volatile char* psg_reg_write  = 0xFF8802;

/**
 * The usual order of writing data to the registers of SSG:
 *    1. Setting music frequency
 *    2. Setting noise frequency
 *    3. Setting mixer
 *    4. Setting volume
 *    5. Envelope control
 */

/**
 * Writes the given byte value (0-255) to the given PSG register (0-15)
 * This helper function used by other functions in psg module
 * 
 * @param reg - PSG reguster (0-15)
 * @param val - value to write
 */
void write_psg(int reg, uint8 val);

/**
 * Read value of a register
 * 
 * @param reg - register
 * @return uint8 - value stored in register
 */
uint8 read_psg(int reg);

/**
 * Loads the tone registers (coarse and fine) for the given channel
 * (0 = A, 1 = B, 2 = C) with the given 12-bin tuning
 * 
 * @param channel
 * @param tuning
 */
void set_tone(channel_t channel, int tuning);

/**
 * Load the noise register with the given tuning
 * 
 * @param tuning 
 */
void set_noise(int tuning);

/**
 * Loads the PSG envelope control registers with the given envelope
 * shape and 16-bit sustain
 */
void set_envelope();

/**
 * Loads the volume register for the given channel
 * 
 * @param channel - given channel
 * @param vol - volume amount
 */
void set_volume(channel_t channel, int vol);

/**
 * Turns the given channel's tone/noise signals on/off
 * 
 * @param channel - given channel
 * @param tone_on - true, to turn on
 * @param noise_on - true, to turn on
 */
void enable_channel(channel_t channel, bool tone_on, bool noise_on);

/**
 * Silences all PSG sound
 */
void stop_sound();

#endif /* SPACE_INVADERS_PSG_H */
