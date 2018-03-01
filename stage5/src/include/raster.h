#ifndef RASTER_H
#define RASTER_H

#include "types.h"
#include "font.h"

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
void plot_pixel(uint8 *base, int x, int y);

/* Plots vertical_line
 * Require x,y of starting location
 * height specifies how many pixels towards the bottom the line will go
 *
 */
void plot_vertical_line(uint8 *base, int x, int y, int height);

/* Plots horizontal_line
 * Require x,y of starting location
 * Width specifies how many pixels to the right the line will go
 *
 */
void plot_horizontal_line(uint8 *base, int x, int y, int width);

void plot_horizontal_line__inverse(uint8 *base, int x, int y, int width);


/* Plot line
 * Require starting x,y coordinates (x1,y2)
 * and end line location (x2,y2)
 *
 */
void plot_line(uint8 *base, int x1, int y1, int x2, int y2);

/* Plot rectangle
 * Require starting coordinates of rectange
 * Width is how many pixels to the right the thickness of the rectangle will be
 * Height is how many pixels towards the bottom from the starting coordinates
 *  the rectangle will be.
 *
 */
void plot_rectangle(uint8 *base, int x, int y, int width, int height);

void plot_rectangle__inverse(uint8 *base, int x, int y, int width, int height);

/* Plots 8 by height Bitmap todo: idk if this is correct
 * Requires top left coordinate the bitmap will placed at
 * and which to use
 * Height specifies the height of the bitmap
 */
void plot_bitmap_8(uint8 *base, int x, int y, uint8 *bitmap, int height);

/* Plots an 16 by height sized bitmap todo: idk if this is correct
 * Requires top left coordinate the bitmap will placed at
 * and which to use
 * Height specifies the height of the bitmap
 */
void plot_bitmap_16(uint16 *base, int x, int y, uint16 *bitmap, int height);

/* Prints a character
 * prints a specified character at given x,y coordinates
 */
void print_char(uint8 *base, int x, int y, char ch);

/* Prints a string (array of char)
 * Prints an array of char at specified x,y coordinates
 */
void print_string(uint8 *base, int x, int y, char *str);

/* Prints a number
 * Prints number or numbers at specified x,y coordinates
 * Limitations:
 *  No negative or decimal numbers - only natural numbers
 */
void print_num(uint8 *base, int x, int y, uint16 num);

/*
 * Clears the entire screen
 */
void _clear_screen(uint32 *base, bool inverse);
void clear_screen(uint32 *base);
void clear_screen__inverse(uint32 *base);
void clear_region(void *base, int x, int y, int width, int height);
#endif
