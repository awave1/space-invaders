#include "include/model.h"
#include <stdio.h>

/*
 * Spaceship functions
 */

/*
 * note: value of 10 was choosen randomly, might need to change
 */
void move_spaceship(Spaceship *spaceship, direction_t direction) {
  switch (direction) {
    case left:
      if (in_bounds(spaceship->x - 10, SPACESHIP_Y_POS))
        spaceship->x -= 10;
      break;
    case right:
      if (in_bounds(spaceship->x + 10, SPACESHIP_Y_POS))
        spaceship->x += 10;
      break;
    default:
      break;
  }
}

void spaceship_shoot(Spaceship *spaceship) {

}


/*
 * Alien functions
 */
void alien_shoot(Alien *alien) {
  /* todo */
}

void alien_collide(Alien *alien) {
}


/*
 * Armada functions
 */
void move_armada(Armada *armada) {
}


/*
 * Shot functions
 */
void move_shot(Shot *shot) {

}


/*
 * Scorebox functions
 */
void update_scorebox(Scorebox *scorebox) {
  /* todo */
}

