#ifndef TYPES_H
#define TYPES_H

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400
#define NULL_CH '\0'

#define in_bounds(x, y) (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)

typedef unsigned char uint8;
typedef unsigned int  uint16;
typedef unsigned long uint32;

typedef uint8 shot_type;
typedef uint8 bool;

#endif
