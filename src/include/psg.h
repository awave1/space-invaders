/**
 *  Authors: Artem Golovin, Daniel Artuso
 */
#ifndef SPACE_INVADERS_PSG_H
#define SPACE_INVADERS_PSG_H

#include <osbind.h>
#include "types.h"

#define CH_A_TONE 0x0
#define CH_B_TONE 0x2
#define CH_C_TONE 0x4

#define CH_A_ROUGH_TONE 0x1
#define CH_B_ROUGH_TONE 0x3
#define CH_C_ROUGH_TONE 0x5

#define CH_A_VOL 0x8
#define CH_B_VOL 0x9
#define CH_C_VOL 0xa

/**
 * To combine channels, just '&' them
 */
#define MIXER_ALL_OFF 0xff
#define MIXER_TONE_CH_A 0x3e
#define MIXER_TONE_CH_B 0x3d
#define MIXER_TONE_CH_C 0x3b
#define MIXER_NOISE_CH_A 0x37
#define MIXER_NOISE_CH_B 0x2f
#define MIXER_NOISE_CH_C 0x1f

#define NOISE_FREQUENCY_REG 0x6
#define MIXER_REG 0x7

#define ENVELOPE_FINE_REG 0xb
#define ENVELOPE_ROUGH_REG 0xc
#define ENVELOPE_SHAPE_CONTROL_REG 0xd

#define ENV_SAW_SHAPE 0xc
#define ENV_SAW_SHAPE_INV 0x8
#define ENV_SAW_PERIOD_SHAPE  0xf
#define ENV_TRIANGLE_SHAPE 0xe
#define ENV_TRIANGLE_INV_SHAPE 0xa
#define ENV_TRIANGLE_PERIOD_SHAPE  0xd
#define ENV_TRIANGLE_INV_PERIOD_SHAPE 0x00


#define reg_is_valid(reg) (reg >= 0 && reg <= 15)

extern volatile char* psg_reg_select = 0xFF8800;
extern volatile char* psg_reg_write  = 0xFF8802;

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
int read_psg(int reg);

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
void set_envelope(env_shape_t shape, uint16 sustain);

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
void enable_channel_(int channel, bool tone_on, bool noise_on);

/**
 * Silences all PSG sound
 */
void stop_sound();

#endif /* SPACE_INVADERS_PSG_H */
