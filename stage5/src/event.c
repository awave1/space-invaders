#include "include/event.h"

/*
 * basic spaceship movement
 */
void on_spaceship_move(Spaceship *spaceship, unsigned long key) {
  if (key == LEFT_KEY)
    move_spaceship(spaceship, left);
  else if (key == RIGHT_KEY)
    move_spaceship(spaceship, right);
  else if (key == SPACE_KEY)
    spaceship_shoot(spaceship);

  if (EVENT_DEBUG) {
    printf("event: spaceship x pos: %d\n", spaceship->x);
    printf("event: spaceship shots: %d\n", spaceship->shot_count);
    printf("event: spaceship shot pos: %d\n", spaceship->shots[0].y);
  }
}

/*
 * todo: not sure if anything else supposed to be here
 */
void on_armada_move(Model *model) {
  move_armada(model);
  
  if (EVENT_DEBUG) {
    printf("event: armada top: %d,%d, bottom: %d,%d\n",
               model->armada.top_left_x, model->armada.top_left_y,
               model->armada.bottom_right_x, model->armada.bottom_right_y);
  }
}

void on_laser_move(Model *model) {
  int i;
  for (i = 0; i < SPACESHIP_MAX_LASERS; i++) {
    if (model->player.shots[i].is_active)
      move_shot(&model->player.shots[i], model);
  }
}

void on_bomb_move(Model *model) {
  int i;
  for (i = 0; i < ALIEN_MAX_BOMBS; i++) {
    if (model->armada.shots[i].is_active) {
      move_shot(&model->armada.shots[i], model);
    }
  }
}

void on_laser_hit_alien(Model *model) {
  int i, row, col;
  bool collided = false;
  for (i = 0; i < model->player.shot_count && !collided; i++) {
    for (row = 0; row < ALIENS_ROWS && !collided; row++) {
      for (col = 0; col < ALIENS_COLS && !collided; col++) {
        if (model->player.shots[i].is_active && laser_collides_with_alien(&model->armada.aliens[row][col], &model->player.shots[i])) {
          destroy_alien(&model->armada.aliens[row][col], &model->player.shots[i], &model->armada);

          /* todo: add function to reset shot */
          model->player.shots[i].is_active = false;
          model->player.shots[i].is_out_of_bounds = false;
          model->player.shots[i].x = model->player.x;
          model->player.shots[i].x = model->player.y;
          model->player.shot_count -= 1;

          collided = true;

          if (EVENT_DEBUG) {
            printf("destroyed (on screen): %d, %d\n", model->armada.aliens[row][col].x, model->armada.aliens[row][col].y);
            printf("alien count: %d\n", model->armada.alive_count);
          }
        }
      }
    }
  }
}

/* todo: write test driver for below functions */
void on_laser_hit_boundary(Shot *laser) {
  if (laser->type == spaceship_laser) {
    laser->is_active = false;
    laser->is_out_of_bounds = true;
  }
}

void on_bomb_hit_boundary(Shot *bomb) {
  if (bomb->type == alien_bomb) {
    bomb->is_active = false;
    bomb->is_out_of_bounds = true;
  }
}

void on_bomb_hit_player(Model* model) {
  int i;
  for (i = 0; i < model->armada.shot_count; i++) {
    if (model->armada.shots[i].is_active && bomb_collides_with_spaceship(&model->player, &model->armada.shots[i])) {
      model->player.is_alive = false;
      on_game_over(model);
      break;
    }
  }
}

void on_alien_hit_bottom(Alien *alien) {
  alien->is_alive = false;
}

void on_game_start(Model *model) {
  init_model(model);
}

void on_game_pause(Model *model) {
  /* todo: add functions to halt all movement */
  pause_game(model);
}

void on_game_over(Model *model) {
  game_over(model);
}

bool has_user_input() {
  return Cconis();
}

unsigned long get_user_input() {
  return Cnecin() >> 16;
}
