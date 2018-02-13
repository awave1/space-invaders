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
  if (EVENT_DEBUG) {
    printf("event: armada top: %d,%d, bottom: %d,%d\n", 
            armada->top_left_x, armada->top_left_y, armada->bottom_right_x, armada->bottom_right_y);
  }
}

void on_laser_move(Shot *laser) {
  if (laser->is_active)
    move_shot(laser);
}

void bomb_moves(Shot *bomb) {
  move_shot(bomb);
}

void laser_hit_alien(Shot *laser, Alien *hit) {
  laser->is_active = false;
  hit->is_alive = false;
}

/* todo: write test driver for below functions */
void laser_hit_boundary(Shot *laser) {
  laser->is_active = false;
  laser->is_out_of_bounds = true;
}

void bomb_hit_boundary(Shot *bomb) {
  bomb->is_active = false;
  bomb->is_out_of_bounds = true;
}

void bomb_hit_player(Spaceship *spaceship) {
  /* todo: end game function */
  spaceship->is_alive = false;
}

void alien_hit_bottom(Spaceship *spaceship) {
  spaceship->is_alive = false;
}

void alien_hit_side(Armada *armada) {
  armada->move_direction = -armada->move_direction;
}

void player_hit_side(Spaceship *spaceship) {
  spaceship->direction = 0;
  /* stop direction */
}

void alien_hit_player(Spaceship *spaceship) {
  spaceship->is_alive = false;
}