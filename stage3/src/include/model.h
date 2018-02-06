#ifndef SPACE_INVADERS_MODEL_H
#define SPACE_INVADERS_MODEL_H

#define SPACESHIP_Y_POS 40
#define SPACESHIP_MOVE_LEFT -1
#define SPACESHIP_MOVE_STOP 0
#define SPACESHIP_MOVE_RIGHT 1

#define ALIENS_ROWS 5
#define ALIENS_COLS 8
#define ALIENS_NUM_OF_ALIENS ALIENS_COLS * ALIENS_ROWS

typedef struct {
  int x;
} spaceship;

typedef struct {
  unsigned int row;
  unsigned int col;
} alien;

typedef struct {
  alien aliens[ALIENS_ROWS][ALIENS_COLS];
} armada;

#endif /* SPACE_INVADERS_MODEL_H */
