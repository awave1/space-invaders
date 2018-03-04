#include "include/model.h"

/*
 * Spaceship functions
 */

/*
 * note: value of 10 was choosen randomly, might need to change
 */
void move_spaceship(Spaceship *spaceship, direction_t direction) {
  switch (direction) {
    case left:
      if (in_bounds(spaceship->x - 10, SPACESHIP_START_Y))
        spaceship->x -= SPACESHIP_MOVE_SPEED;
      break;
    case right:
      if (in_bounds(spaceship->x + 10, SPACESHIP_START_Y))
        spaceship->x += SPACESHIP_MOVE_SPEED;
      break;
    default:
      break;
  }
}

void spaceship_shoot(Spaceship *spaceship) {
  int i;
  for (i = 0; i < SPACESHIP_MAX_LASERS; i++) {
    /*
     * we can add more shots when curr count is less than max and current shot IS NOT active
     */
    if (spaceship->shot_count == 0 &&
        spaceship->shot_count < SPACESHIP_MAX_LASERS) {
      if (!spaceship->shots[i].is_active) {
        spaceship->shots[i].x = spaceship->x - 2;
        spaceship->shots[i].y = spaceship->y - 8;
        spaceship->shots[i].is_active = true;
        spaceship->shot_count += 1;
      }
    }
  }
}

void init_spaceship(Spaceship *spaceship) {
  spaceship->x = SPACESHIP_START_X;
  spaceship->y = SPACESHIP_START_Y;
  spaceship->shot_count = 0;
  spaceship->is_alive = true;
  init_shots(spaceship->shots, NULL, spaceship_laser, SPACESHIP_MAX_LASERS);
}


/*
 * Alien functions
 */
void alien_shoot(Armada *armada) {
  int i;
  for (i = 0; i < ALIEN_MAX_BOMBS; i++) {
    /*
     * we can add more shots when curr count is less than max and current shot IS NOT active
     */
    if (armada->shot_count == 0 && armada->shot_count < SPACESHIP_MAX_LASERS) {
      if (!armada->shots[i].is_active) {
        armada->shots[i].is_active = true;
        armada->shot_count++;
      }
    }

    if (armada->shots[i].is_out_of_bounds) {
      armada->shots[i].is_out_of_bounds = false;
      armada->shot_count--;
    }
  } 
}

void destroy_alien(Alien* alien, Shot* shot, Armada* armada) {
  if (shot->type == spaceship_laser) {
    shot->is_active = false;
    alien->is_alive = false;
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

  int new_bottom_right_x__right = armada->bottom_right_x + ALIEN_SPEED_X;
  int new_top_left_x__right = armada->top_left_x + ALIEN_SPEED_X;

  int new_bottom_right_x__left = armada->bottom_right_x - ALIEN_SPEED_X;
  int new_top_left_x__left = armada->top_left_x - ALIEN_SPEED_X;

  int new_bottom_right_y = armada->bottom_right_y + ALIEN_SPEED_Y;
  int new_top_left_y = armada->top_left_y + ALIEN_SPEED_Y;

  switch (armada->move_direction) {
    case right:
      if (new_bottom_right_x__right < SCREEN_WIDTH) {
        _update_alien_pos(&model->armada, right);
        armada->bottom_right_x = new_bottom_right_x__right;
        armada->top_left_x = new_top_left_x__right;
      } else {
        _update_alien_pos(&model->armada, down);
        if (new_bottom_right_y >= SCREEN_HEIGHT) {
          game_over(model);
        }

        armada->bottom_right_y = new_bottom_right_y;
        armada->top_left_y = new_top_left_y;
        armada->move_direction = left;
      }
      break;
    case left:
      if (new_top_left_x__left >= 0) {
        _update_alien_pos(&model->armada, left);
        armada->bottom_right_x = new_bottom_right_x__left;
        armada->top_left_x = new_top_left_x__left;
      } else {
        _update_alien_pos(&model->armada, down);
        if (new_bottom_right_y >= SCREEN_HEIGHT) {
          game_over(model);
        }

        armada->bottom_right_y = new_bottom_right_y;
        armada->top_left_y = new_top_left_y;
        armada->move_direction = right;
      }
      break;
    default:
      break;
  }
}


void _update_alien_pos(Armada* armada, direction_t direction) {
  int row, col;
  for (row = 0; row < ALIENS_ROWS; row++) {
    for (col = 0; col < ALIENS_COLS; col++) {
      if (direction == right)
        armada->aliens[row][col].x += ALIEN_SPEED_X;
      else if (direction == left)
        armada->aliens[row][col].x -= ALIEN_SPEED_X;
      else if (direction == down)
        armada->aliens[row][col].y += ALIEN_SPEED_Y;
    }
  }
}

/*
 * Populates 2d array of aliens
 */
void init_armada(Armada *armada) {
  int row, col;
  uint16 alien_screen_x = ALIENS_START_X;
  uint16 alien_screen_y = ALIENS_START_Y;
  uint16 alien_score = ALIEN_C_SCORE;
  Alien alien;

  armada->top_left_x = ALIENS_START_X;
  armada->top_left_y = ALIENS_START_Y;
  armada->move_direction = right;
  armada->alive_count = 0;

  for (row = 0; row < ALIENS_ROWS; row++) {
    for (col = 0; col < ALIENS_COLS; col++) {
      alien.x = alien_screen_x;
      alien.y = alien_screen_y; 
      alien.row = row;
      alien.col = col;
      alien.score_val = alien_score;
      alien.is_alive = true;

      armada->aliens[row][col] = alien;
      alien_screen_x += ALIEN_BOX_SIZE;
    }
    alien_screen_x = ALIENS_START_X;
    alien_screen_y += ALIEN_BOX_SIZE;
    if (row >= 1 && alien_score <= 3)
      alien_score = ALIEN_B_SCORE;
    else
      alien_score = ALIEN_A_SCORE;
  }

  armada->bottom_right_x = armada->aliens[ALIENS_ROWS - 1][ALIENS_COLS - 1].x;
  armada->bottom_right_y = armada->aliens[ALIENS_ROWS - 1][ALIENS_COLS - 1].y;

  armada->width = (armada->bottom_right_x + 16) - armada->top_left_x;
  armada->height = (armada->bottom_right_y + 16) - armada->top_left_y;
  armada->alive_count = ALIENS_NUM_OF_ALIENS;

  init_shots(armada->shots, armada, alien_bomb, ALIEN_MAX_BOMBS);

  if (MODEL_DEBUG) {
    printf("model: initial positions of aliens:\n");
    for (row = 0; row < ALIENS_ROWS; row++) {
      for (col = 0; col < ALIENS_COLS; col++) {
        printf("%d,%d ", armada->aliens[row][col].row,
               armada->aliens[row][col].col);
      }
      printf("\n");
    }
    printf("initial armada pos top: %d,%d, bottom: %d,%d\n", armada->top_left_x,
           armada->top_left_y, armada->bottom_right_x, armada->bottom_right_y);
  }
}

/*
 * Shot functions
 */
void move_shot(Shot *shot, Model* model) {
  if (shot->type == spaceship_laser)
    shot->y -= SPACESHIP_LASER_SPEED;
  else if (shot->type == alien_bomb)
    shot->y += ALIEN_BOMB_SPEED;

  if (shot->y <= 0 || shot->y >= SCREEN_HEIGHT) {
    shot->is_active = false;
    model->player.shot_count -= 1;
  }

  if (MODEL_DEBUG) {
    printf("shot moves: y = %d\n", shot->y);
  }
}

void init_shots(Shot shots[], Armada* armada, shot_t type, int max_shots) {
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
    shots[i] = shot;
  }
}

bool laser_collides_with_alien(Alien* alien, Shot* laser) {
  int x_start = alien->x;
  int x_end = alien->x + 16;

  return alien->is_alive && alien->y == laser->y && in_range(x_start, x_end, laser->x);
}

bool bomb_collides_with_spaceship(Spaceship* spaceship, Shot* bomb) {
  int x_start = spaceship->x;
  int x_end = spaceship->x + 16;

  return bomb->y >= spaceship->y && in_range(x_start, x_end, bomb->x); 

}


/*
 * Scorebox functions
 */
void update_scorebox(Scorebox *scorebox, int alien_score) {
  if (scorebox->score < MAX_SCORE)
    scorebox->score += alien_score;
  else
    scorebox->score = MAX_SCORE;

  if (MODEL_DEBUG) {
    printf("int score: %lu\n", scorebox->score);
  }
}

void init_scorebox(Scorebox *scorebox) {
  scorebox->score = 0;
  scorebox->x = SCOREBOX_P1_X;
  scorebox->y = SCOREBOX_Y;
}

void init_model(Model *model) {
  model->is_playing = true;
  model->is_game_over = false;
  init_armada(&model->armada);
  init_spaceship(&model->player);
  init_scorebox(&model->scorebox);
}

void resume_game(Model *model) {
  model->is_playing = true;
}

void pause_game(Model *model) {
  model->is_playing = false;
}

void game_over(Model *model) {
  model->is_game_over = true;
  model->is_playing = false;
}

bool in_range(unsigned int low, unsigned int high, unsigned int x) {
  return (low <= x  && x <= high);
}
