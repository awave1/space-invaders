#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "types.h"

/* event constants */
const bool EVENT_DEBUG = true;
const unsigned long LEFT_KEY = 0x4b;
const unsigned long RIGHT_KEY = 0x4d;
const unsigned long SPACE_KEY = 0x39;


/* model constants */
const bool MODEL_DEBUG = true;

/* 
 * Spaceship / Player constants
 */
#define SPACESHIP_START_X 312
#define SPACESHIP_START_Y 368
#define SPACESHIP_LASER_SPEED 4
#define SPACESHIP_MOVE_SPEED 5
#define SPACESHIP_MAX_LASERS 1

/*
 * Aliens constants
 */
#define ALIENS_ROWS 5
#define ALIENS_COLS 8
#define ALIENS_NUM_OF_ALIENS ALIENS_COLS * ALIENS_ROWS
#define ALIEN_A_SCORE 10
#define ALIEN_B_SCORE 20
#define ALIEN_C_SCORE 30
#define ALIEN_BOMB_SPEED 6
#define ALIEN_MAX_BOMBS 3

/* alien box size (not hitbox but space box) */
#define ALIEN_BOX_SIZE 32

#define ALIENS_START_X 195
#define ALIENS_START_Y 40

/*
 * Scorebox constants
 */
#define SCOREBOX_P1_X 549
#define SCOREBOX_P2_X 89
#define SCOREBOX_Y 40

const uint32 MAX_SCORE = 9999;

#endif /* CONSTANTS_H */

