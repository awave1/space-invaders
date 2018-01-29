#include "raster.h"

/*
* Some magick is happening here
*/
void plot_pixel(UINT8* base, int x, int y) {
  if (in_bounds(x, y))
    *(base + y * 80 + (x >> 3)) |= 1 << (7 - (x & 7));
}

/*
 * Assume y2 > y1
 */ 
void plot_vertical_line(UINT8* base, int x, int y1, int y2) {
  int i = 0;
  if (in_bounds(x, y1) && in_bounds(x, y2)) {
    for (i = y1; i != y2; i++) {
      plot_pixel(base, x, i);
    }
  }
}

/*
 * Assume x2 > x1
 */ 
void plot_horizontal_line(UINT8* base, int x1, int x2, int y) {
  int i = 0;
  if (in_bounds(x1, y) && in_bounds(x2, y)) {
    for (i = x1; i != x2; i++) {
      plot_pixel(base, i, y);
    }
  }
}
