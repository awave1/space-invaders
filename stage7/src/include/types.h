/*
 *  File: types.h 
 *  Authors: Artem Golovin, Daniel Artuso 
 */

#ifndef SPACE_INVADERS_TYPES_H
#define SPACE_INVADERS_TYPES_H

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400
#define NULL_CH '\0'

#define pos_in_bounds(x, y) (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)

typedef unsigned char uint8;
typedef unsigned int uint16;
typedef unsigned long uint32;

typedef char *string;

typedef int bool;
#define true 1
#define false 0

typedef enum {
  left, right, down, stop
} direction_t;

typedef enum {
  alien_bomb, spaceship_laser
} shot_t;

typedef enum {
  ch_a, ch_b, ch_c
} channel_t;

typedef enum {
  saw, saw_inv, saw_period, saw_inv_period, 
  triangle, triangle_inv, triangle_period, triangle_inv_period
} env_shape_t;

#endif /* SPACE_INVADERS_TYPES_H */
