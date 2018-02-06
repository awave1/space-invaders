#ifndef SPACE_INVADERS_MODEL_H
#define SPACE_INVADERS_MODEL_H

#include "types.h"

/* 
 * Spaceship / Player constants
 */
#define SPACESHIP_Y_POS 40
#define SPACESHIP_MOVE_LEFT -1
#define SPACESHIP_MOVE_STOP 0
#define SPACESHIP_MOVE_RIGHT 1
#define SPACESHIP_LASER 0

const uint16* SPACESHIP_BMP;

/*
 * Aliens constants
 */
#define ALIENS_ROWS 5
#define ALIENS_COLS 8
#define ALIENS_NUM_OF_ALIENS ALIENS_COLS * ALIENS_ROWS
#define ALIEN_A_SCORE 10
#define ALIEN_B_SCORE 20
#define ALIEN_C_SCORE 30
#define ALIEN_BOMB 1

const uint16* ALIEN_A_BMP; /* 10 point alien */
const uint16* ALIEN_B_BMP; /* 20 point alien */
const uint16* ALIEN_C_BMP; /* 30 point alien */


typedef struct {
  uint16 x;
} spaceship;

/* spaceship specific functions */
/* todo */
/* **************************** */

typedef struct {
  uint16 row;
  uint16 col;
  uint16 score_val;
} alien;

/* single alien specific functions */
/* todo */
/* ******************************* */


typedef struct {
  alien aliens[ALIENS_ROWS][ALIENS_COLS];
} armada;

/* armada specific functions */
/* todo */
/* ************************* */

typedef struct {
  uint16 x;
  uint16 y;
  int shot_type; /* can be 0 or 1 (player or alien) */
} shot;

/* shot specific functions */
/* todo */
/* *********************** */

typedef struct {
  spaceship player;
  armada armada;
} Model;

/* model specific functions */
/* todo */
/* ************************ */

#endif /* SPACE_INVADERS_MODEL_H */
