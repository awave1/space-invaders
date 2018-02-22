#include <stdio.h>
#include "include/render.h"

int main() {
  Model model;
  uint16 *base = (uint16*) Physbase();
  uint32 *screen = (uint32) Physbase();
  on_game_start(&model);
  clear_screen__inverse(base);
  /* render(&model, base); */
  return 0;
}
