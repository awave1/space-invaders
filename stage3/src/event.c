#include "include/event.h"

/*
 * basic spaceship movement
 */
void on_spaceship_move(Spaceship* spaceship, unsigned long key) {
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
void on_armada_move(Armada* armada) {
  move_armada(armada);
  if (armada->bottom_right_y >= SCREEN_HEIGHT) {
    /* todo: call game_over() */
  }
  if (EVENT_DEBUG) {
    printf("event: armada top: %d,%d, bottom: %d,%d\n", 
            armada->top_left_x, armada->top_left_y, armada->bottom_right_x, armada->bottom_right_y);
  }
}

void on_laser_move(Shot *laser) {
  if (laser->is_active)
    move_shot(laser);
}

void on_bomb_move(Shot *bomb) {
  move_shot(bomb);
}

void on_laser_hit_alien(Shot *laser, Alien *alien) {
  if (laser_collides_with_alien(alien, laser)) {
    laser->is_active = false;
    alien->is_alive = false;
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

void on_bomb_hit_player(Spaceship *spaceship, Shot *bomb) {
  /* todo: end game function */
  if (bomb_collides_with_spaceship(spaceship, bomb)) {
    spaceship->is_alive = false;
  }
}

void on_alien_hit_bottom(Alien *alien) {
  alien->is_alive = false;
}

void on_game_start(Model* model) {
  init_model(model);
}

void on_game_pause(Model* model) {
  /* todo: add functions to halt all movement */ 
}

void on_game_over(Model* model) {
  stop_game(model);
}

void _log_event(char* event_name, char* message) {
  printf("EVENT: %s\n", event_name);
  printf(message);
  printf('\n');
}

