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

void render_shot(const Shot *shot, uint8 *base) {
  if (shot->is_active) {
    plot_rectangle(base, shot->x, shot->y, 2, 4);
  }
}

/*change base size if sprite different*/
void render_scoreboard(const Scorebox *scorebox, uint8 *base) {
  print_num(base, scorebox->x, scorebox->y, scorebox->score);
}

