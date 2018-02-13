#include <osbind.h>
#include <stdio.h>
#include "include/raster.h"

/*
 * raster lib test driver
 */
int main() {
  void* base = Physbase();
  int i, j;
  const int x_start = 195;
  const int y_start = 40;
  int x = x_start;
  int y = y_start;

  plot_rectangle(base, 0, 0, 640, 400);

  /*
  * Plot 5 x 8 grid of 16x16 blocks, each 16px apart
  */
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 8; j++) {
      plot_rectangle__inverse(base, x, y, 16, 16);
      x += 32;
    }
    x = x_start;
    y += 32;
  }

  /*
  * Plot approx location of the player's ship
  */
  plot_rectangle__inverse(base, 312, 368, 16, 16);
	
  getchar();
  clear_screen(base);
  return 0;
}

