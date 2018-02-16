#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <osbind.h>
#include "include/model.h"
#include "include/event.h"

void game_loop(char choice) {
  Model* model = malloc(sizeof *model);
  unsigned long input_key;

  on_game_start(model);

  switch(choice) {
    case 'a':
      printf("testing armada movement: \n");
      while (!model->is_game_over) {
        on_armada_move(model, true);
      }
      printf("\n");
      break;
    case 's':
      printf("testing spaceship movement\n(press l anr r keys to move, spacebar to shoot)\n");
      printf("\t(press ctrl-c to exit)\n");
      while (!model->is_game_over) {
      
        if (Cconis()) {
          input_key = Cnecin();
          input_key = input_key >> 16;
    
          on_spaceship_move(&model->player, input_key);
        }
        on_laser_move(model);
      }
      break;
    case 'c':
      printf("testing shot collision\n");
      while (!model->is_game_over) {
        if (Cconis()) {
          input_key = Cnecin();
          input_key = input_key >> 16;

          on_spaceship_move(&model->player, input_key);
        }
        
        on_laser_move(model);
        on_laser_hit_alien(model);
        on_armada_move(model, false);
        if (model->armada.alive_count < ALIENS_NUM_OF_ALIENS) {
          break;
        }
      }
      break;
  }

  free(model);
}

int main(int argc, char** argv) {
  char *s;
  while (--argc > 0 && (*++argv)[0] == '-') {
    for(s = argv[0]+1; *s != '\0'; s++)
      game_loop(*s);
  }
  return 0;
}
