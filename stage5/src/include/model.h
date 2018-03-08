#ifndef SPACE_INVADERS_MODEL_H
#define SPACE_INVADERS_MODEL_H

#include <stdio.h>
#include "const.h"
#include "types.h"


typedef struct {
    uint16 x;
    uint16 y;
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
  int width;
  int height;
  int top_left_x;
  int top_left_y;
  int bottom_right_x;
  int bottom_right_y;
  direction_t move_direction;
  Shot shots[ALIEN_MAX_BOMBS];
  int alive_count;
  int shot_count;
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
void set_spaceship_x(Spaceship* spaceship, uint16 x);


/* alien functions */
void alien_collide(Alien *alien);
void destroy_alien(Alien* alien, Shot* shot, Armada* armada);

/* armada functions */
void move_armada(Model* model);
void alien_shoot(Armada *armada);
void init_armada(Armada *armada);

/* shot functions */
void move_shot(Shot* shot, Model* model);
void shot_hit_alien(Shot* player_shot, Alien* alien);
void shot_hit_player(Shot* player_shot, Spaceship* alien);
void init_shots(Shot shots[], Armada* armada, shot_t type, int max_shots);

bool laser_collides_with_alien(Alien* alien, Shot* laser);
bool bomb_collides_with_spaceship(Spaceship* alien, Shot* laser);

/* scorebox functions */
void set_score(Scorebox* scorebox, uint32 score);
uint32 get_score(Scorebox* scorebox);
void _update_score_text(Scorebox* scorebox);

/* model functions */
void init_model(Model* model);
void game_over(Model* model);
void pause_game(Model* model);
void resume_game(Model* model);

bool in_range(unsigned int low, unsigned int high, unsigned int x);

#endif /* SPACE_INVADERS_MODEL_H */
