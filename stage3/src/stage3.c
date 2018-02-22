#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <osbind.h>
#include "include/model.h"
#include "include/event.h"

void game_loop(char choice) {
  Model* model = malloc(sizeof *model);
  unsigned long input_key;
  int row, col;

  on_game_start(model);


  printf("model: initial positions of aliens:\n");
  for (row = 0; row < ALIENS_ROWS; row++) {
    for (col = 0; col < ALIENS_COLS; col++) {
      printf("%d,%d ", model->armada.aliens[row][col].x, model->armada.aliens[row][col].y);
    }
    printf("\n");
  }
  

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
          printf("\n");
          for (row = 0; row < ALIENS_ROWS; row++) {
            for (col = 0; col < ALIENS_COLS; col++) {
              if (model->armada.aliens[row][col].is_alive) {
                printf("%d,%d ", model->armada.aliens[row][col].x, model->armada.aliens[row][col].y);
              } else {
                 printf("000,000 "); 
              }
            }
            printf("\n");
          }
          break;
        }
      }
      break;
    case 'e':
      printf("testing enemy-player shot collision\n");
      /* simulate shot */
      model->armada.shots[0].is_active = true;
      model->armada.shot_count = 1;

      model->player.x = model->armada.aliens[0][0].x;

      while (!model->is_game_over) {
        if (Cconis()) {
          input_key = Cnecin();
          input_key = input_key >> 16;

          on_spaceship_move(&model->player, input_key);
        }
        on_bomb_move(model);
        on_bomb_hit_player(model);
        if (!model->player.is_alive) {
          printf("player alive? %s\n", model->player.is_alive == true ? "true" : "false");
        }
      }
      break;
  }

  free(model);
}

int main(int argc, char** argv) {
  char *s;

  /*
   * Read only single char after dash
   *   For example: <exe_name> <args>, where arguement can be -a or -ab
   *    only 'a' will be read or in second case first a then b will be read 
   */
  while (--argc > 0 && (*++argv)[0] == '-') {
    for(s = argv[0]+1; *s != '\0'; s++)
      game_loop(*s);
  }
  return 0;
}
