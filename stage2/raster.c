#include "raster.h"

/*
* Some magick is happening here
*/
void plot_pixel(UINT16* base, int x, int y) {
  if (in_bounds(x, y))
    *(base + y * 80 + (x >> 3)) |= 1 << (7 - (x & 7));
}
