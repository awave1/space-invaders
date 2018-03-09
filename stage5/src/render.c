#include "include/render.h"

void render(Model *model, void* base) {
  render_spaceship(&model->player, (uint16*) base);
  render_armada(&model->armada, (uint16*) base);
  render_scoreboard(&model->scorebox, (uint8*) base);
}

void render_spaceship(const Spaceship *spaceship, uint16 *base) {
  plot_bitmap_16(base, spaceship->x, spaceship->y, spaceship_bitmap, SPRITE_SIZE);
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

void render_shots(const Shot shots[], shot_t shot_type, uint8 *base) {
  int i;
  int max_shots = shot_type == spaceship_laser ? SPACESHIP_MAX_LASERS : ALIEN_MAX_BOMBS;
  for (i = 0; i < max_shots; i++) {
    if (shots[i].is_active)
      plot_rectangle__inverse(base, shots[i].x, shots[i].y, 8, 8);
  }
}

/*change base size if sprite different*/
void render_scoreboard(const Scorebox *scorebox, uint8 *base) {
  print_string(base, scorebox->x, scorebox->y - 8, "Score");
  print_num(base, scorebox->x, scorebox->y, scorebox->score);
}

void disable_cursor() {
	printf("\033f");
	fflush(stdout);
}

void clear_aliens(Armada* armada, uint16* base) {
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

void clear_shots(Shot shots[], uint8* base) {
  int i;
  for (i = 0; i < SPACESHIP_MAX_LASERS; i++) {
    if (shots[i].is_active)
      clear_region(base, shots[i].x, shots[i].y, SHOT_WIDTH, SHOT_HEIGHT);
  }
}