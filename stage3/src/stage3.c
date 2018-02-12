#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <osbind.h>
#include "include/model.h"
#include "include/event.h"

void game_loop() {
  Model* model = malloc(sizeof *model);
  unsigned long input_key;

  init_model(model);

  /*
   * simple loop
   */
  while (true) {

    if (Cconis()) {
      input_key = Cnecin();
      input_key = input_key >> 16;
      
      on_spaceship_move(&model->player, input_key);
    }

    on_armada_move(&model->armada);
    on_laser_move(&model->player.shots[0]);
  }

  free(model);
}

int main() {
  game_loop();
  return 0;
}
