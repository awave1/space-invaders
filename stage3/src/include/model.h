#ifndef SPACE_INVADERS_MODEL_H
#define SPACE_INVADERS_MODEL_H

#include "types.h"

const bool MODEL_DEBUG = true;

/* 
 * Spaceship / Player constants
 */
#define SPACESHIP_Y_POS 40

const uint16 *SPACESHIP_BMP;

/*
 * Aliens constants
 */
#define ALIENS_ROWS 5
#define ALIENS_COLS 8
#define ALIENS_NUM_OF_ALIENS ALIENS_COLS * ALIENS_ROWS
#define ALIEN_A_SCORE 10
#define ALIEN_B_SCORE 20
#define ALIEN_C_SCORE 30

/* alien box size (not hitbox but space box) */
#define ALIEN_BOX_SIZE 32

#define ALIENS_START_X 195
#define ALIENS_START_Y 40


const uint16 *ALIEN_A_BMP; /* 10 point alien */
const uint16 *ALIEN_B_BMP; /* 20 point alien */
const uint16 *ALIEN_C_BMP; /* 30 point alien */

/*
 * Scorebox constants
 */
#define SCOREBOX_X 0
#define SCOREBOX_Y 40

const uint32 MAX_SCORE = 9999;


typedef struct Spaceship {
  int x;
  direction_t direction;
  hitbox_t hitbox;
} Spaceship;

/* spaceship specific functions */
void spaceship_shoot(Spaceship* spaceship);
void move_spaceship(Spaceship* spaceship, direction_t direction);


/* **************************** */

typedef struct Alien {
  uint16 row;
  uint16 col;
  uint16 x;
  uint16 y;
  uint16 score_val;
  bool isAlive;
} Alien;

/* single alien specific functions */
void alien_shoot(Alien *alien);
void alien_collide(Alien *alien);

/* ******************************* */


typedef struct Armada {
  Alien aliens[ALIENS_ROWS][ALIENS_COLS];
  int top_left_x;
  int top_left_y;
  int bottom_right_x;
  int bottom_right_y;
  direction_t move_direction;
} Armada;

/* armada specific functions */
void move_armada(Armada *armada);
void populate_armada(Armada *armada);

/* ************************* */

typedef struct Shot {
  uint16 x;
  uint16 y;
  shot_t isAlien; /* can be 0 or 1 (player or alien) */
  bool isActive;
} Shot;

/* shot specific functions */
void move_shot(Shot* shot);
void shot_hit_alien(Shot* player_shot, Alien* alien);
void shot_hit_player(Shot* player_shot, Spaceship* alien);

/* *********************** */

typedef struct Scorebox {
  uint32 score;
  string score_str;
} Scorebox;

/* model specific functions */
void update_scorebox(Scorebox *scorebox, int alien_score);
/* ************************ */


typedef struct Model {
  Spaceship player;
  Armada armada;
  Scorebox scorebox;
} Model;

/* model specific functions */
/* todo */
/* ************************ */


#endif /* SPACE_INVADERS_MODEL_H */
