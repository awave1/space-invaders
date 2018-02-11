#include <stdio.h>
#include <stdlib.h>
#include <osbind.h>
#include "include/model.h"
#include "include/event.h"

void game_loop() {
  Spaceship* spaceship = malloc(sizeof *spaceship);
  Armada* armada = malloc(sizeof *armada);

  spaceship->x = 208;
  populate_armada(armada);

  /*
   * simple loop, runs everything synchronously
   */
  while (true) {
    on_spaceship_move(spaceship);
    on_armada_move(armada);
    printf("\n");
  }
}

int main() {
  game_loop();
  return 0;
}
