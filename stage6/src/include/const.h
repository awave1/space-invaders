#ifndef SPACE_INVADERS_CONSTANTS_H
#define SPACE_INVADERS_CONSTANTS_H

#include "types.h"

/* event constants */
#define EVENT_DEBUG false
#define LEFT_KEY 0x4b
#define RIGHT_KEY 0x4D
#define SPACE_KEY 0x39


/* model constants */
#define MODEL_DEBUG false


/* 
 * Spaceship / Player constants
 */
#define SPACESHIP_START_X 312
#define SPACESHIP_START_Y 368
#define SPACESHIP_LASER_SPEED 32
#define SPACESHIP_MOVE_SPEED 16
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
#define ALIEN_BOMB_SPEED 32
#define ALIEN_MAX_BOMBS 3
#define ALIEN_SPEED_X 2
#define ALIEN_SPEED_Y 4

/* alien box size (not hitbox but space box) */
#define ALIEN_BOX_SIZE 32
#define ALIENS_START_X 195
#define ALIENS_START_Y 40

#define SPRITE_SIZE 16
#define SPRITE_HEIGHT 16

/*TODO: Replace, when proper plotting implemented*/
#define SHOT_WIDTH 8
#define SHOT_HEIGHT 8

/*
 * Scorebox constants
 */
#define SCOREBOX_P1_X 559
#define SCOREBOX_P2_X 89
#define SCOREBOX_Y 13

#define MAX_SCORE 9999

/* System Constants */
#define SYSTEM_CLOCK 0x462
#define SCREEN_BUFFER_SIZE 32825

#endif /* SPACE_INVADERS_CONSTANTS_H */
