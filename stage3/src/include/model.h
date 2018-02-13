#ifndef SPACE_INVADERS_MODEL_H
#define SPACE_INVADERS_MODEL_H

#include "const.h"
#include "types.h"

const uint16 *SPACESHIP_BMP;
const uint16 *ALIEN_A_BMP; /* 10 point alien */
const uint16 *ALIEN_B_BMP; /* 20 point alien */
const uint16 *ALIEN_C_BMP; /* 30 point alien */

typedef struct Shot {
  uint16 x;
  uint16 y;
  shot_t type;
  bool is_active;
  bool is_out_of_bounds;
} Shot;

typedef struct Spaceship {
  int x;
  int y;
  direction_t direction;
  hitbox_t hitbox;
  Shot shots[SPACESHIP_MAX_LASERS];
  int shot_count;
  bool is_alive;
} Spaceship;

typedef struct Alien {
  uint16 row;
  uint16 col;
  uint16 x;
  uint16 y;
  uint16 score_val;
  bool is_alive;
} Alien;

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

typedef struct Scorebox {
  int x;
  int y;
  uint32 score;
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
void set_spaceship_x(Spaceship* spaceship, uint16 x);


/* alien functions */
void alien_collide(Alien *alien);

/* armada functions */
void move_armada(Armada *armada);
void alien_shoot(Armada *armada);
void init_armada(Armada *armada);

/* shot functions */
void move_shot(Shot* shot);
void shot_hit_alien(Shot* player_shot, Alien* alien);
void shot_hit_player(Shot* player_shot, Spaceship* alien);
void init_shots(Shot shots[], shot_t type, int max_shots);

bool laser_collides_with(Alien* alien, Shot* laser);
bool bomb_collides_with(Alien* alien, Shot* laser);

/* scorebox functions */
void set_score(Scorebox* scorebox, uint32 score);
uint32 get_score(Scorebox* scorebox);
void _update_score_text(Scorebox* scorebox);

/* model functions */
void init_model(Model* model);
void stop_game(Model *model); 
void pause_game(Model* model);

void _log_model(cosnt char* model_name, const char* message);

#endif /* SPACE_INVADERS_MODEL_H */
