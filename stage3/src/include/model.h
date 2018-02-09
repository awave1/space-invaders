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
const shot_type SPACESHIP_LASER = 0;

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
const shot_type ALIEN_BOMB = 1;

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
    uint16 x;
    uint16 direction;
} Spaceship;

/* spaceship specific functions */
void spaceship_shoot(Spaceship* spaceship);
void move_spaceship(Spaceship* spaceship);


/* **************************** */

typedef struct Alien {
    uint16 row;
    uint16 col;
    uint16 score_val;
} Alien;

/* single alien specific functions */
void alien_shoot(Alien *alien);
void alien_collide(Alien *alien);

/* ******************************* */


typedef struct Armada {
    Alien aliens[ALIENS_ROWS][ALIENS_COLS];
} Armada;

/* armada specific functions */
void move_armada(Armada *armada);

/* ************************* */

typedef struct Shot {
    uint16 x;
    uint16 y;
    shot_type isAlien; /* can be 0 or 1 (player or alien) */
    bool isActive;
} Shot;

/* shot specific functions */
void move_shot(Shot* shot);
void shot_hit_alien(Shot* player_shot, Alien* alien);
void shot_hit_player(Shot* player_shot, Spaceship* alien);

/* *********************** */

typedef struct Scorebox {
    uint32 score;
    char* scoreString;
} Scorebox;

/* model specific functions */
void update_scorebox(Scorebox* score);

/* ************************ */


typedef struct Model {
    Spaceship player;
    Armada armada;
} Model;

/* model specific functions */
/* todo */
/* ************************ */


#endif /* SPACE_INVADERS_MODEL_H */
