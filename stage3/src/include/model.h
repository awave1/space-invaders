#ifndef SPACE_INVADERS_MODEL_H
#define SPACE_INVADERS_MODEL_H

#include "types.h"

const bool MODEL_DEBUG = true;

/* 
 * Spaceship / Player constants
 */
#define SPACESHIP_START_X 312
#define SPACESHIP_START_Y 368
#define SPACESHIP_LASER_SPEED 4
#define SPACESHIP_MAX_LASERS 1


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
#define ALIEN_BOMB_SPEED 6
#define ALIEN_MAX_BOMBS 3

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


typedef struct Shot {
  uint16 x;
  uint16 y;
  shot_t type; /* can be 0 or 1 (player or alien) */
  bool is_active;
  bool is_out_of_bounds;
} Shot;

typedef struct Spaceship {
  int x;
  direction_t direction;
  hitbox_t hitbox;
  Shot shots[SPACESHIP_MAX_LASERS];
  int shot_count;
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
  bool is_alive;
} Alien;

/* single alien specific functions */
void alien_collide(Alien *alien);

/* ******************************* */


typedef struct Armada {
  Alien aliens[ALIENS_ROWS][ALIENS_COLS];
  int top_left_x;
  int top_left_y;
  int bottom_right_x;
  int bottom_right_y;
  direction_t move_direction;
  Shot shots[ALIEN_MAX_BOMBS];
  int shot_count;
} Armada;

/* armada specific functions */
void move_armada(Armada *armada);
void alien_shoot(Armada *armada);
void init_armada(Armada *armada);

/* ************************* */

/* shot specific functions */
void move_shot(Shot* shot);
void shot_hit_alien(Shot* player_shot, Alien* alien);
void shot_hit_player(Shot* player_shot, Spaceship* alien);
void init_shots(Shot shots[], shot_t type, int max_shots);
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
/* ************************ */


#endif /* SPACE_INVADERS_MODEL_H */
