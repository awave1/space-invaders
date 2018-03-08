#ifndef TYPES_H
#define TYPES_H

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

#endif
