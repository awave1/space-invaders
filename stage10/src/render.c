/**
 *  File: render.c
 *  Authors: Artem Golovin, Daniel Artuso
 */
#include "include/render.h"

void render(Model *model, void *base) {
  render_spaceship(&model->player, (uint16 *) base);
  render_armada(&model->armada, (uint16 *) base);
  render_shots(model->armada.shots, alien_bomb, base);
  render_shots(model->player.shots, spaceship_laser, base);
  render_scoreboard(&model->scorebox, (uint8 *) base);
}

void render_spaceship(const Spaceship *spaceship, uint16 *base) {
  plot_bitmap_16(base, spaceship->x, spaceship->y, spaceship_bitmap,
                 SPRITE_SIZE);
}

void render_armada(const Armada *armada, uint16 *base) {
  int i, j;
  for (i = 0; i < ALIENS_ROWS; ++i) {
    for (j = 0; j < ALIENS_COLS; ++j) {
      if (armada->aliens[i][j].is_alive)
        render_alien(&armada->aliens[i][j], base);
    }
  }
}

void render_alien(const Alien *alien, uint16 *base) {
  switch (alien->score_val) {
    case ALIEN_A_SCORE:
      plot_bitmap_16(base, alien->x, alien->y, alien1_bitmap, SPRITE_SIZE);
          break;
    case ALIEN_B_SCORE:
      plot_bitmap_16(base, alien->x, alien->y, alien2_bitmap, SPRITE_SIZE);
          break;
    case ALIEN_C_SCORE:
      plot_bitmap_16(base, alien->x, alien->y, alien3_bitmap, SPRITE_SIZE);
          break;
  }
}

void render_shots(const Shot shots[], shot_t shot_type, uint16 *base) {
  int i;
  int max_shots =
    shot_type == spaceship_laser ? SPACESHIP_MAX_LASERS : ALIEN_MAX_BOMBS;
  for (i = 0; i < max_shots; i++) {
    if (shots[i].is_active)
      plot_bitmap_16(base, shots[i].x, shots[i].y, alien_bomb_test,
                     SPRITE_SIZE);
  }
}

/*change base size if sprite different*/
void render_scoreboard(const Scorebox *scorebox, uint8 *base) {
  print_string(base, scorebox->x, scorebox->y - 8, "Score");
  print_num(base, scorebox->x, scorebox->y, scorebox->score);
}

void render_splashscreen(uint32* base) {
  int y1 = SELECTION_1Y + 25;
  int y2 = SELECTION_2Y + 25;
  int y3 = SELECTION_3Y + 25;
  int x = SELECTION_X + 30;
  int width = 148;
  int height = 5;

  clear_qk(base);
  plot_screen(base, splash_screen);

  plot_rectangle__inverse((uint8*) base, x, y1, width, height);
  plot_rectangle__inverse((uint8*) base, x, y2, width, height);
  plot_rectangle__inverse((uint8*) base, x, y3, width, height);
}

void render_game_over(uint32* base) {
  int x1 = 284;
  int x2 = 212;
  int y1 = 200;
  int y2 = 216;
  print_string((uint8*) base, x1, y1, "GAME OVER");
  print_string((uint8*) base, x2, y2, "(PRESS ANY KEY TO CONTINUE)");
}

void disable_cursor() {
  printf("\033f");
  fflush(stdout);
}

void clear_aliens(Armada *armada, uint16 *base) {
  int i, j, x, y;
  /* TODO: Clear by row */
  for (i = 0; i < ALIENS_ROWS; i++) {
    for (j = 0; j < ALIENS_COLS; j++) {
      x = armada->aliens[i][j].x;
      y = armada->aliens[i][j].y;
      if (armada->aliens[i][j].is_alive)
        clear_region(base, x, y, SPRITE_SIZE, SPRITE_SIZE);
    }
  }
}

void clear_shots(Shot shots[], uint8 *base) {
  int i;
  for (i = 0; i < SPACESHIP_MAX_LASERS; i++) {
    if (shots[i].is_active)
      clear_region(base, shots[i].x, shots[i].y, SHOT_WIDTH, SHOT_HEIGHT);
  }
}

void save_mouse_bg(uint16 *base, int x, int y) {
  int i, j;

  for(i = 0, j = 0; i < MOUSE_BG_SIZE; i++)
    mouse_bg[j++] = *(base + (y + i) * 40 + (x >> 4));
}

void restore_mouse_bg(uint16 *base, int x, int y) {
  int i, j;

  for(i = 0, j = 0; i < MOUSE_BG_SIZE; i++)
    *(base + (y + i) * 40 + (x >> 4)) = mouse_bg[j++];
}

void render_mouse_ptr(uint16 *base, int x, int y) {
  plot_bitmap_16(base, x, y, mouse_pointer, SPRITE_SIZE);
}
