#include "sprites.c"
#include "include/render.h"

void render(const Model *model, UINT16 *base) {
  render_spaceship(model->player, base);
  render_armada(model->armada, base);
  /*render_scoreboard(model->scorebox,base);*/
}

void render_spaceship(const Spaceship *spaceship, UINT16 *base) {
  plot_bitmap_16(base, spaceship->x, spaceship->y, spaceship_bitmap, 16);
}

void render_armada(const Armada *armada, UINT16 *base) {
  for (int i = 0; i < ALIENS_ROWS; ++i) {
    for (int j = 0; j < ALIENS_COLS; ++j) {
      if (armada->aliens[i][j].is_alive)
        render_alien(armada->aliens[i][j], base);
    }
  }
}

void render_alien(const Alien *alien, UNIT16 *base) {
  plot_bitmap_16(base, alien->x, alien->y, alien1_bitmap, 16);
}

void render_shot(const Shot *shot, UINT16 *base) {
  if (shot->is_active)
    /*plot_bitmap_16(base,shot->x,shot->y,todo:shot bitmap, height);/*
}/*change base size if sprite different*/
    void render_scoreboard(const Scorebox *scorebox, UINT16 *base) {
      /*plot_bitmap_16(base,scorebox->x,scorebox->y, todo:scorebox bitmap)*/
    }

  void plot_bitmap_16(UINT16 *base, int x, int y, UINT16 *bitmap, int height) {
    int i = 0;
    UINT16 *location = base + (y * 40) + (x >> 4);
    for (i = 0; i < height; i++) {
      *location |= *(bitmap++);
      location += 40;
    }
  }