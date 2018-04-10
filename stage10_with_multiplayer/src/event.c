/**
 *  File: event.c
 *  Authors: Artem Golovin, Daniel Artuso
 */
#include "include/event.h"

/*
 * basic spaceship movement
 */
void on_spaceship_move(Spaceship *spaceship, unsigned long key) {
  if (key == LEFT_KEY)
    move_spaceship(spaceship, left);
  else if (key == RIGHT_KEY)
    move_spaceship(spaceship, right);
  else if (key == SPACE_KEY) {
    spaceship_shoot(spaceship);
  }
}

void on_armada_move(Model *model) {
  move_armada(model);
}

void on_alien_shoot(Model *model) {
  alien_shoot(&model->armada);
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
    if (model->armada.shots[i].is_active)
      move_shot(&model->armada.shots[i], model);
  }
}

void on_laser_hit_alien(Model* model, int player) {
  int i, row, col;
  bool collided = false;
  Alien *alien;
  Shot *shot;

  for (i = 0; i < model->player.shot_count && !collided; i++) {
    for (row = 0; row < ALIENS_ROWS && !collided; row++) {
      for (col = 0; col < ALIENS_COLS && !collided; col++) {
        shot = &model->player.shots[i];
        alien = &model->armada.aliens[row][col];
        if (shot->is_active && laser_collides_with_alien(alien, shot)) {
          destroy_alien(alien, shot, &model->armada);
          reset_shot(shot, model);
          explosion_effect(true);

          if (player == PLAYER_ONE)
            update_scorebox(&model->scorebox, alien->score_val);
          else if (player == PLAYER_TWO)
            update_scorebox(&model->scorebox2, alien->score_val);

          /* break out of all loops since collision happened */
          collided = true;
        }
      }
    }
  }
}

void on_bomb_hit_player(Model *model) {
  int i;
  bool collided = false;
  for (i = 0; i < model->armada.shot_count && !collided; i++) {
    if (model->armada.shots[i].is_active &&
      bomb_collides_with_spaceship(&model->player, &model->armada.shots[i])) {
      explosion_effect(false);
      model->player.is_alive = false;
      on_game_over(model);
      collided = true;
    }
  }
}

void on_game_start(Model *model, int player_count) {
  init_model(model, player_count);
}

void on_game_over(Model *model) {
  game_over(model);
}

void on_game_exit() {
  stop_sound();
  clear_interrupts();
}

void on_next_wave(Model *model) {
  init_armada(&model->armada);
}

bool has_user_input() {
  return ikbd_is_waiting();
}

bool has_mouse_input() {
  return ikbd_mouse_moved();
}

unsigned long get_user_input() {
  return read_from_ikbd_buffer();
}
