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

 /*
  * Moves armada as a single entity
  */
void move_armada(Armada *armada) {
  switch(armada->move_direction) {
    case right:
      if (armada->bottom_right_x + 2 < SCREEN_WIDTH) {
        armada->bottom_right_x += 2;
        armada->top_left_x += 2;
      } else {
        armada->bottom_right_y += 8;
        armada->top_left_y += 8;
        armada->move_direction = left;
      }
      break;
    case left:
      if (armada->top_left_x - 2 >= 0) {
        armada->bottom_right_x -= 2;
        armada->top_left_x -= 2;
      } else {
        armada->bottom_right_y += 8;
        armada->top_left_y += 8;
        armada->move_direction = right;
      }
      break;
    default:
      break;
  }
}

/*
 * Populates 2d array of aliens
 */
void populate_armada(Armada *armada) {
  int row, col;
  uint16 alien_screen_x = ALIENS_START_X;
  uint16 alien_screen_y = ALIENS_START_Y;
  uint16 alien_score = ALIEN_C_SCORE;
  Alien alien;

  armada->top_left_x = ALIENS_START_X;
  armada->top_left_y = ALIENS_START_Y;
  armada->move_direction = right;

  for (row = 0; row < ALIENS_ROWS; row++) {
    for (col = 0; col < ALIENS_COLS; col++) {
      alien.x = alien_screen_x;
      alien.y = alien_screen_y; 
      alien.row = row;
      alien.col = col;
      alien.score_val = alien_score;
      alien.isAlive = true;

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

  /* 
   * shitcode, but works 
   * todo: reformat
   */
  armada->bottom_right_x = armada->aliens[ALIENS_ROWS - 1][ALIENS_COLS - 1].x;
  armada->bottom_right_y = armada->aliens[ALIENS_ROWS - 1][ALIENS_COLS - 1].y;

  if (true) {
    printf("model: initial positions of aliens:\n");
    for (row = 0; row < ALIENS_ROWS; row++) {
      for (col = 0; col < ALIENS_COLS; col++) {
        printf("%d,%d ", armada->aliens[row][col].row, armada->aliens[row][col].col);
      }
      printf("\n");
    }
    printf("armada coords: \n");
    printf("top: %d,%d, bottom: %d,%d\n", armada->top_left_x, armada->top_left_y, armada->bottom_right_x, armada->bottom_right_y);
  }
}

/*
 * Shot functions
 */
void move_shot(Shot *shot) {
  shot->y += 3;
}


/*
 * Scorebox functions
 */
void update_scorebox(Scorebox *scorebox, int alien_score) {
  scorebox->score += alien_score;
  sprintf(scorebox->score_str, "%d", scorebox->score);
}

