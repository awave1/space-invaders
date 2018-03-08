#ifndef SPACE_INVADERS_MODEL_H
#define SPACE_INVADERS_MODEL_H

#include <stdio.h>
#include "const.h"
#include "types.h"

#define for_row for (row = 0; row < ALIENS_ROWS; row++)
#define for_col for (col = 0; col < ALIENS_COLS; col++)
#define iterate_aliens for_row for_col

typedef struct {
  uint16 top_left_x;
  uint16 top_left_y;
  uint16 bottom_right_x;
  uint16 bottom_right_y;
  uint16 width;
  uint16 height;
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
  hitbox_t hitbox;
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
  uint16* bitmap[SPRITE_HEIGHT];
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

} Model;

/* spaceship functions */
void move_spaceship(Spaceship* spaceship, direction_t direction);
void spaceship_shoot(Spaceship* spaceship);
void init_spaceship(Spaceship* spaceship);

/* alien functions */
void alien_collide(Alien *alien);
void destroy_alien(Alien* alien, Shot* shot, Armada* armada);

/* armada functions */
void move_armada(Model* model);
void alien_shoot(Armada* armada);
void init_armada(Armada* armada);

/* shot functions */
void move_shot(Shot* shot, Model* model);
void shot_hit_alien(Shot* player_shot, Alien* alien);
void shot_hit_player(Shot* player_shot, Spaceship* alien);

bool laser_collides_with_alien(Alien* alien, Shot* laser);
bool bomb_collides_with_spaceship(Spaceship* alien, Shot* laser);

/* scorebox functions */
void set_score(Scorebox* scorebox, uint32 score);
uint32 get_score(Scorebox* scorebox);

/* model functions */
void init_model(Model* model);
void game_over(Model* model);
void pause_game(Model* model);
void resume_game(Model* model);

/* Helpers */
void _init_alien(Alien* alien, int x, int y, int row, int col, int score);
void _init_armada_hitbox(Armada* armada);
void _init_shots(Shot shots[], Armada* armada, shot_t type, int max_shots);
void _move_aliens(Armada* armada, direction_t direction);
void _move_alien(Alien* alien, direction_t direction);
void _update_shot_hitbox(hitbox_t* hitbox, int dy);
bool _in_range(unsigned int low, unsigned int high, unsigned int x);

#endif /* SPACE_INVADERS_MODEL_H */
