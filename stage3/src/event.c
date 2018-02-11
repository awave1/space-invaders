#include "include/event.h"
#include <stdio.h>

/*
 * basic spaceship movement
 */
void on_spaceship_move(Spaceship* spaceship) {
  unsigned long input;

  do {
    input = Cnecin();
    input = input >> 16;

    if (input == LEFT_KEY) {
      printf("left\n");
      move_spaceship(spaceship, left);
    } else if (input == RIGHT_KEY) {
      printf("right\n");
      move_spaceship(spaceship, right);
    }
    printf("x pos: %d\n", spaceship->x);
  } while (input == LEFT_KEY || input == RIGHT_KEY);
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