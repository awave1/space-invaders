#ifndef RASTER_H
#define RASTER_H

#include "types.h"
/*
 * For each function you develop, write a short header block comment which specifies:
1. its purpose, from the caller’s perspective (if not perfectly clear from the name);
2. the purpose of each input parameter (if not perfectly clear from the name);
3. the purpose of each output parameter and return value (if not perfectly clear from the name);
4. any assumptions, limitations or known bugs.
 */


/* Plot Pixel
 * Require x,y of pixel to place
 *
 */
void plot_pixel(UINT8* base, int x, int y);

/* Plots vertical_line
 * Require x,y of starting location
 * height specifies how many pixels towards the bottom the line will go
 *
 */
void plot_vertical_line(UINT8* base, int x, int y, int height);

/* Plots horizontal_line
 * Require x,y of starting location
 * Width specifies how many pixels to the right the line will go
 *
 */
void plot_horizontal_line(UINT8* base, int x, int y, int width);

/* Plot line
 * Require starting x,y coordinates (x1,y2)
 * and end line location (x2,y2)
 *
 */
void plot_line(UINT8* base, int x1, int y1, int x2, int y2);

/* Plot rectangle
 * Require starting coordinates of rectange
 * Width is how many pixels to the right the thickness of the rectangle will be
 * Height is how many pixels towards the bottom from the starting coordinates
 *  the rectangle will be.
 *
 */
void plot_rectangle(UINT8* base, int x, int y, int width, int height);

/* Plots 8 bit Bitmap
 * Requires top left coordinate the bitmap will placed at
 * and which to use
 * todo: finish
 */
void plot_bitmap_8(UINT8* base, int x, int y, UINT8* bitmap, int height);

/* todo: docs
 *
 */
void plot_bitmap_16(UINT16* base, int x, int y, UINT16* bitmap, int height);

/* todo: docs
 *
 */
void print_char(UINT8* base, int x, int y, char ch);

/* todo: docs
 */
void print_string(UINT8* base, int x, int y, char* str);

/* todo: docs
 */
void print_num(UINT8* base, int x, int y, UINT16 num);

/* todo: docs
 *
 */
void clear_screen(UINT32* base);

#endif
