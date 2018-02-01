#ifndef RASTER_H
#define RASTER_H

#include "types.h"

void plot_pixel(UINT8* base, int x, int y);

void plot_vertical_line(UINT8* base, int x, int y, int height);
void plot_horizontal_line(UINT8* base, int x, int y, int width);
void plot_line(UINT8* base, int x1, int y1, int x2, int y2);

void plot_rectangle(UINT8* base, int x, int y, int width, int height);

void plot_bitmap_8(UINT8* base, int x, int y, UINT8* bitmap, int height);
void plot_bitmap_16(UINT16* base, int x, int y, UINT16* bitmap, int height);

void print_char(UINT8* base, int x, int y, char ch);
void print_string(UINT8* base, int x, int y, char* str);
void print_num(UINT8* base, int x, int y, UINT16 num);

void clear_screen(UINT32* base);

#endif
