#ifndef RASTER_H
#define RASTER_H

#include "types.h"

void plot_pixel(UINT8* base, int x, int y);
void plot_vertical_line(UINT8* base, int x, int y1, int y2);
void plot_horizontal_line(UINT8* base, int x1, int x2, int y);
void print_char(UINT8* base, int x, int y, char ch);
void print_string(UINT8* base, int x, int y, char* str);

#endif
