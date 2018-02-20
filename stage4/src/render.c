#include "include/render.h"

void render(Model *model, uint16 *base) {
  render_spaceship(&model->player, base);
  render_armada(&model->armada, base);
  render_scoreboard(&model->scorebox, base);
}

void render_spaceship(const Spaceship *spaceship, uint16 *base) {
  plot_bitmap_16(base, spaceship->x, spaceship->y, spaceship_bitmap, 16);
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
  plot_bitmap_16(base, alien->x, alien->y, alien1_bitmap, 16);
}

void render_shot(const Shot *shot, uint16 *base) {
  if (shot->is_active) {
    plot_rectangle(base, shot->x, shot->y, 2, 4);
  }
}

/*change base size if sprite different*/
void render_scoreboard(const Scorebox *scorebox, uint16 *base) {
  print_num(base, scorebox->x, scorebox->y, scorebox->score);
}

