/*
 *  Authors: Artem Golovin, Daniel Artuso 
 *  Description:
 *      model.h contains game specific structs and functions to control those
 *      structures. All model functions should be called in events.
 * 
 *      struct Model     - top level game model that contains all elements of the game
 *                         and controls game state.
 *      struct Spaceship - contains elements that needed for spaceship
 *      struct Armada    - contains 2d array of Aliens
 *      struct Alien     - contains aliens that needed for aliens
 *      struct Scorebox  - contains string and int score
 *      struct hitbox_t  - helper hitbox, used for collision detection
 */

#ifndef SPACE_INVADERS_MODEL_H
#define SPACE_INVADERS_MODEL_H

#include <stdio.h>
#include <osbind.h>
#include "const.h"
#include "types.h"
#include "effects.h"


typedef struct {
    uint16 top_left_x;
    uint16 top_left_y;
    uint16 bottom_right_x;
    uint16 bottom_right_y;
    uint16 width;
    uint16 height;
    bool active;          /* only used for aliens */
} hitbox_t;

typedef struct Shot {
    int x;
    int y;
    shot_t type;
    bool is_active;
    bool is_out_of_bounds;
    hitbox_t hitbox;
} Shot;

typedef struct Spaceship {
    int x;
    int y;
    direction_t direction;
    Shot shots[SPACESHIP_MAX_LASERS];
    int shot_count;
    bool is_alive;
    hitbox_t hitbox;
} Spaceship;

typedef struct Alien {
    int row;
    int col;
    int x;
    int y;
    int score_val;
    bool is_alive;
    hitbox_t hitbox;
} Alien;

typedef struct Armada {
    Alien aliens[ALIENS_ROWS][ALIENS_COLS];
    direction_t move_direction;
    Shot shots[ALIEN_MAX_BOMBS];
    int alive_count;
    int shot_count;
    hitbox_t hitbox;
} Armada;

typedef struct Scorebox {
    int x;
    int y;
    int score;
} Scorebox;

typedef struct Model {
    bool is_playing;
    bool is_game_over;
    Spaceship player;
    Armada armada;
    Scorebox scorebox;
    Scorebox scorebox2;
} Model;

/* spaceship functions */
/**
 * Moves the spaceship to the left or to the right, depending on direction
 * 
 * @param spaceship - Spaceship 
 * @param direction - direction
 */
void move_spaceship(Spaceship* spaceship, direction_t direction);

/**
 * Shoot laser
 * 
 * @param spaceship - Spaceship
 */
void spaceship_shoot(Spaceship* spaceship);

/**
 * Initialize spaceship model
 * 
 * @param spaceship - Spaceship
 */
void init_spaceship(Spaceship* spaceship);

/* alien functions */
/**
 * Destroys a single alien from the armada
 * 
 * @param alien  - Alien to destroy
 * @param shot   - laser that destroyed the alien
 * @param armada - Armada
 */
void destroy_alien(Alien* alien, Shot* shot, Armada* armada);

/* armada functions */
/**
 * Moves armada of alien in snaking way. 
 * It starts moving to the right, as soon as it hits the screen boundary, it
 * drops down and starts moving to the left. Movement is repeated until armada reaches the ground
 * 
 * @param model - Game model
 */
void move_armada(Model* model);

/**
 * Random alien from the armada shoots a bomb.
 * 
 * @param armada - Armada
 */
void alien_shoot(Armada* armada);

/**
 * Initialize aliens, their starting position and shots
 * 
 * @param armada - Armada
 */
void init_armada(Armada* armada);

/* shot functions */
/**
 * Moves a shot (either laser or bomb)
 * 
 * @param shot  - Shot to move
 * @param model - Game model
 */
void move_shot(Shot* shot, Model* model);

/**
 * Check if laser collides with a single alien
 * 
 * @param alien - Alien (target)
 * @param laser - Spaceship's laser
 * @return true, if collision was successful
 */
bool laser_collides_with_alien(Alien* alien, Shot* laser);

/**
 * Check if bomb collides with the spaceship
 * 
 * @param spaceship - Spaceship (target)
 * @param bomb      - Alien's bomb
 * @return true, if collision was successful
 */
bool bomb_collides_with_spaceship(Spaceship* spaceship, Shot* bomb);

/**
 * Reset given shot to its initial position and state
 * 
 * @param shot  - Shot to reset
 * @param model - Game model
 */
void reset_shot(Shot* shot, Model* model);


/* scorebox functions */
/**
 * Update scorebox score
 * 
 * @param scorebox    - Scorebox
 * @param alien_score - score of destroyed alien
 */
void update_scorebox(Scorebox* scorebox, int alien_score);

void init_scorebox(Model* model, int player_count);

/* model functions */
/**
 * Initialize the whole game model. This function calls other init functions
 * 
 * @param model - Game model
 */
void init_model(Model* model, int player_count);

/**
 * Set game state to "game over"
 * 
 * @param model - Game model
 */
void game_over(Model* model);

/**
 * Helper function that checks if two given hitboxes collide with each other
 * 
 * @param box1 - First hitbox
 * @param box2 - Second hitbox
 * @return true, if collision happened
 */
bool collides(hitbox_t box1, hitbox_t box2);

/* Helpers */
/**
 * Initialize a single alien and a hitbox for it
 * 
 * @param alien - Alien to initialize
 * @param x     - Alien's x position on the screen
 * @param y     - Alien's y position on the screen
 * @param row   - Alien's row position in 2d array
 * @param col   - Alien's col position in 2d array
 * @param score - Alien's score value
 */
void _init_alien(Alien* alien, int x, int y, int row, int col, int score);

/**
 * Initialize hitbox for the entire armada.
 * 
 * @param armada - Armada
 */
void _init_armada_hitbox(Armada* armada);

/**
 * Initialize shot position and count for aliens and player
 * 
 * @param shots     - Shots to initialize
 * @param armada    - Armada
 * @param type      - shot type
 * @param max_shots - maximum number of shots
 */
void _init_shots(Shot shots[], Armada* armada, shot_t type, int max_shots);

/**
 * Change x and y position of aliens
 * 
 * @param armada    - Armada
 * @param direction - direction
 */
void _move_aliens(Armada* armada, direction_t direction);

/**
 * Move a single alien
 * 
 * @param alien     - Alien to move
 * @param direction - direction
 */
void _move_alien(Alien* alien, direction_t direction);

/**
 * Update hitbox for a given shot
 * 
 * @param hitbox - hitbox to update
 * @param dy     - change in y position
 */
void _update_shot_hitbox(hitbox_t* hitbox, int dy);

#endif /* SPACE_INVADERS_MODEL_H */
