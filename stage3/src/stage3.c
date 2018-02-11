#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <osbind.h>
#include "include/model.h"
#include "include/event.h"

void game_loop() {
  Spaceship* spaceship = malloc(sizeof *spaceship);
  Armada* armada = malloc(sizeof *armada);
  Scorebox* scorebox = malloc(sizeof *scorebox);
  int score = 10;

  spaceship->x = 208;
  populate_armada(armada);
  scorebox->score = 0;

  /*
   * simple loop, runs everything synchronously
   */
  while (true) {
    on_spaceship_move(spaceship);
    on_armada_move(armada);
    update_scorebox(scorebox, score);
    score += 10;
    printf("\n");
  }
}

int main() {
  game_loop();
  return 0;
}
