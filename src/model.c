/**
 *  Authors: Artem Golovin, Daniel Artuso
 */
#include "include/model.h"

/*
 * Spaceship functions
 */
void move_spaceship(Spaceship *spaceship, direction_t direction) {
  switch (direction) {
    case left:
      if (pos_in_bounds(spaceship->x - SPACESHIP_MOVE_SPEED, SPACESHIP_START_Y))
        spaceship->x -= SPACESHIP_MOVE_SPEED;
          break;
    case right:
      if (pos_in_bounds(spaceship->x + SPACESHIP_MOVE_SPEED, SPACESHIP_START_Y))
        spaceship->x += SPACESHIP_MOVE_SPEED;
          break;
    default:
      break;
  }

  spaceship->hitbox.top_left_x = spaceship->x;
  spaceship->hitbox.bottom_right_x = spaceship->x + SPRITE_SIZE;
}

void spaceship_shoot(Spaceship* spaceship) {
  int i;
  for (i = 0; i < SPACESHIP_MAX_LASERS; i++) {
    if (spaceship->shot_count == 0 &&
      spaceship->shot_count < SPACESHIP_MAX_LASERS) {
      if (!spaceship->shots[i].is_active) {
        spaceship->shots[i].x = spaceship->x - 2;
        spaceship->shots[i].y = spaceship->y - 8;
        spaceship->shots[i].is_active = true;

        spaceship->shots[i].hitbox.top_left_x = spaceship->shots[i].x;
        spaceship->shots[i].hitbox.top_left_y = spaceship->shots[i].y;
        spaceship->shots[i].hitbox.bottom_right_x =
          spaceship->shots[i].x + SHOT_WIDTH;
        spaceship->shots[i].hitbox.bottom_right_y =
          spaceship->shots[i].y + SHOT_HEIGHT;

        spaceship->shot_count++;

        laser_shot_effect();
      }
    }
  }
}

void init_spaceship(Spaceship *spaceship) {
  spaceship->x = SPACESHIP_START_X;
  spaceship->y = SPACESHIP_START_Y;
  spaceship->shot_count = 0;
  spaceship->is_alive = true;

  spaceship->hitbox.top_left_x = spaceship->x;
  spaceship->hitbox.top_left_y = spaceship->y;
  spaceship->hitbox.bottom_right_x = spaceship->x + SPRITE_SIZE;
  spaceship->hitbox.bottom_right_y = spaceship->y + SPRITE_SIZE;
  spaceship->hitbox.width = SPRITE_SIZE;
  spaceship->hitbox.height = SPRITE_SIZE;
  spaceship->hitbox.active = true;

  _init_shots(spaceship->shots, NULL, spaceship_laser, SPACESHIP_MAX_LASERS);
}


/*
 * Alien functions
 */
void alien_shoot(Armada *armada) {
  int i;
  int rand_row = Random() % ALIENS_ROWS;
  int rand_col = Random() % ALIENS_COLS;

  if (armada->aliens[rand_row][rand_col].is_alive) {
    for (i = 0; i < ALIEN_MAX_BOMBS; i++) {
      if (armada->shot_count == 0 && armada->shot_count < ALIEN_MAX_BOMBS) {
        if (!armada->shots[i].is_active) {
          armada->shots[i].x = armada->aliens[rand_row][rand_col].x - 2;
          armada->shots[i].y = armada->aliens[rand_row][rand_col].y + 4;
          armada->shots[i].is_active = true;

          armada->shots[i].hitbox.top_left_x = armada->shots[i].x;
          armada->shots[i].hitbox.top_left_y = armada->shots[i].y;
          armada->shots[i].hitbox.bottom_right_x =
            armada->shots[i].x + SHOT_WIDTH;
          armada->shots[i].hitbox.bottom_right_y =
            armada->shots[i].y + SHOT_HEIGHT;

          armada->shot_count++;
        }
      }
    }
  }
}

void destroy_alien(Alien *alien, Shot *shot, Armada *armada) {
  if (shot->type == spaceship_laser) {
    shot->is_active = false;
    alien->is_alive = false;
    alien->hitbox.active = false;
    armada->alive_count -= 1;
  }
}

/*
 * Armada functions
 */

/*
 * Moves armada as a single entity
 */
void move_armada(Model *model) {
  Armada *armada = &model->armada;
  hitbox_t *hitbox = &armada->hitbox;

  int new_bottom_right_x__right = hitbox->bottom_right_x + ALIEN_SPEED_X;
  int new_top_left_x__right = hitbox->top_left_x + ALIEN_SPEED_X;

  int new_bottom_right_x__left = hitbox->bottom_right_x - ALIEN_SPEED_X;
  int new_top_left_x__left = hitbox->top_left_x - ALIEN_SPEED_X;

  int new_bottom_right_y = hitbox->bottom_right_y + ALIEN_SPEED_Y;
  int new_top_left_y = hitbox->top_left_y + ALIEN_SPEED_Y;

  switch (armada->move_direction) {
    case right:
      if (new_bottom_right_x__right < SCREEN_WIDTH) {
        _move_aliens(&model->armada, right);
        hitbox->bottom_right_x = new_bottom_right_x__right;
        hitbox->top_left_x = new_top_left_x__right;
      } else {
        _move_aliens(&model->armada, down);
        hitbox->bottom_right_y = new_bottom_right_y;
        hitbox->top_left_y = new_top_left_y;

        armada->move_direction = left;
      }
      break;
    case left:
      if (new_top_left_x__left >= 0) {
        _move_aliens(&model->armada, left);
        hitbox->bottom_right_x = new_bottom_right_x__left;
        hitbox->top_left_x = new_top_left_x__left;
      } else {
        _move_aliens(&model->armada, down);
        hitbox->bottom_right_y = new_bottom_right_y;
        hitbox->top_left_y = new_top_left_y;

        armada->move_direction = right;
      }
      break;
    default:
      break;
  }

  if (collides(*(hitbox), model->player.hitbox))
    game_over(model);
}

/*
 * Populates 2d array of aliens
 */
void init_armada(Armada *armada) {
  int row, col;
  uint16 x = ALIENS_START_X;
  uint16 y = ALIENS_START_Y;
  uint16 score = ALIEN_C_SCORE;
  Alien alien;

  armada->move_direction = right;
  armada->alive_count = ALIENS_NUM_OF_ALIENS;
  armada->shot_count = 0;

  for (row = 0; row < ALIENS_ROWS; row++) {
    switch (row) {
      case 1:
      case 2:
        score = ALIEN_B_SCORE;
        break;
      case 3:
      case 4:
        score = ALIEN_A_SCORE;
        break;
    }

    for (col = 0; col < ALIENS_COLS; col++) {
      _init_alien(&alien, x, y, row, col, score);
      armada->aliens[row][col] = alien;
      x += ALIEN_BOX_SIZE;
    }

    x = ALIENS_START_X;
    y += ALIEN_BOX_SIZE;

  }

  _init_armada_hitbox(armada);
  _init_shots(armada->shots, armada, alien_bomb, ALIEN_MAX_BOMBS);
}


/*
 * Shot functions
 */
void move_shot(Shot *shot, Model *model) {
  if (shot->type == spaceship_laser)
    shot->y -= SPACESHIP_LASER_SPEED;
  else if (shot->type == alien_bomb)
    shot->y += ALIEN_BOMB_SPEED;

  _update_shot_hitbox(&shot->hitbox, shot->y);

  if (shot->y <= SCOREBOX_Y + 8 ||
    shot->y >= model->player.hitbox.bottom_right_y) {
    shot->is_active = false;
    if (shot->type == spaceship_laser)
      model->player.shot_count -= 1;
    else
      model->armada.shot_count -= 1;
  }
}

void reset_shot(Shot *shot, Model *model) {
  shot->is_active = false;
  shot->is_out_of_bounds = false;
  shot->x = model->player.x;
  shot->x = model->player.y;
  model->player.shot_count -= 1;
}

bool laser_collides_with_alien(Alien *alien, Shot *laser) {
  return collides(alien->hitbox, laser->hitbox);
}

bool bomb_collides_with_spaceship(Spaceship *spaceship, Shot *bomb) {
  return collides(spaceship->hitbox, bomb->hitbox);
}

/*
 * Scorebox functions
 */
void update_scorebox(Scorebox *scorebox, int alien_score) {
  if (scorebox->score < MAX_SCORE)
    scorebox->score += alien_score;
  else
    scorebox->score = MAX_SCORE;
}

void init_scorebox(Model* model, int player_count) {
  model->scorebox.score = 0;
  model->scorebox.x = SCOREBOX_P1_X;
  model->scorebox.y = SCOREBOX_Y;
  if (player_count == 2) {
    model->scorebox2.score = 0;
    model->scorebox2.x = SCOREBOX_P2_X;
    model->scorebox2.y = SCOREBOX_Y;
  }
}


/*
 * Model functions
 */
void init_model(Model* model, int player_count) {
  model->is_playing = true;
  model->is_game_over = false;
  init_armada(&model->armada);
  init_spaceship(&model->player);
  init_scorebox(model, player_count);
}

void game_over(Model *model) {
  model->is_game_over = true;
  model->is_playing = false;
}


bool collides(hitbox_t box1, hitbox_t box2) {
  return
    box1.active && box2.active &&
    box1.top_left_x < box2.bottom_right_x &&
    box1.bottom_right_x > box2.top_left_x &&
    box1.top_left_y < box2.bottom_right_y &&
    box1.bottom_right_y > box2.top_left_y;
}


/* Helpers */
void _init_alien(Alien *alien, int x, int y, int row, int col, int score) {
  alien->x = x;
  alien->y = y;
  alien->row = row;
  alien->col = col;
  alien->score_val = score;
  alien->is_alive = true;
  alien->hitbox.top_left_x = x;
  alien->hitbox.top_left_y = y;
  alien->hitbox.bottom_right_x = x + SPRITE_SIZE;
  alien->hitbox.bottom_right_y = y + SPRITE_SIZE;
  alien->hitbox.width = SPRITE_SIZE;
  alien->hitbox.height = SPRITE_SIZE;
  alien->hitbox.active = true;
}

void _init_armada_hitbox(Armada *armada) {
  armada->hitbox.top_left_x = ALIENS_START_X;
  armada->hitbox.top_left_y = ALIENS_START_Y;
  armada->hitbox.bottom_right_x =
    armada->aliens[ALIENS_ROWS - 1][ALIENS_COLS - 1].x + SPRITE_SIZE;
  armada->hitbox.bottom_right_y =
    armada->aliens[ALIENS_ROWS - 1][ALIENS_COLS - 1].y + SPRITE_SIZE;
  armada->hitbox.width =
    (armada->hitbox.bottom_right_x + SPRITE_SIZE) - armada->hitbox.top_left_x;
  armada->hitbox.height =
    (armada->hitbox.bottom_right_y + SPRITE_SIZE) - armada->hitbox.top_left_y;
  armada->hitbox.active = true;
}

void _init_shots(Shot shots[], Armada *armada, shot_t type, int max_shots) {
  int i, row, col;
  Shot shot;
  for (i = 0; i < max_shots; i++) {
    if (type == spaceship_laser) {
      shot.x = SPACESHIP_START_X;
      shot.y = SPACESHIP_START_Y - 8;
    } else if (type == alien_bomb) {
      shot.x = armada->aliens[0][0].x;
      shot.y = armada->aliens[0][0].y;
    }

    shot.type = type;
    shot.is_active = false;
    shot.is_out_of_bounds = false;

    shot.hitbox.top_left_x = shot.x;
    shot.hitbox.top_left_y = shot.y;
    shot.hitbox.bottom_right_x = shot.x + SHOT_WIDTH;
    shot.hitbox.bottom_right_y = shot.y + SHOT_HEIGHT;
    shot.hitbox.width = SHOT_WIDTH;
    shot.hitbox.width = SHOT_HEIGHT;
    shot.hitbox.active = true;

    shots[i] = shot;
  }
}

void _move_aliens(Armada *armada, direction_t direction) {
  int row, col;
  for (row = 0; row < ALIENS_ROWS; row++)
    for (col = 0; col < ALIENS_COLS; col++)
      _move_alien(&armada->aliens[row][col], direction);
}

void _move_alien(Alien *alien, direction_t direction) {
  if (direction == right)
    alien->x += ALIEN_SPEED_X;
  else if (direction == left)
    alien->x -= ALIEN_SPEED_X;
  else if (direction == down)
    alien->y += ALIEN_SPEED_Y;

  alien->hitbox.top_left_x = alien->x;
  alien->hitbox.top_left_y = alien->y;
  alien->hitbox.bottom_right_x = alien->x + SPRITE_SIZE;
  alien->hitbox.bottom_right_y = alien->y + SPRITE_SIZE;
}

void _update_shot_hitbox(hitbox_t *hitbox, int dy) {
  hitbox->top_left_y = dy;
  hitbox->bottom_right_y = dy + SHOT_HEIGHT;
}
