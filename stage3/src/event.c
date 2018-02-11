#include "include/event.h"

/*
 * basic spaceship movement
 */
void on_spaceship_move(Spaceship* spaceship) {
  unsigned long input;

  input = Cnecin();
  input = input >> 16;

  if (input == LEFT_KEY)
    move_spaceship(spaceship, left);
  else if (input == RIGHT_KEY)
    move_spaceship(spaceship, right);
  else if (input == SPACE_KEY)
    spaceship_shoot(spaceship);

  if (EVENT_DEBUG)
    printf("event: spaceship x pos: %d\n", spaceship->x);
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

void laser_moves(Shot *laser) {
  move_shot(laser);
}

void bomb_moves(Shot *bomb) {
  move_shot(bomb);
}

void laser_hit_alien(Shot *laser, Alien *hit) {
  laser->isActive = false;
  hit->isAlive = false;
}

void laser_hit_boundary(Shot *laser) {
  laser->isActive = false;
}