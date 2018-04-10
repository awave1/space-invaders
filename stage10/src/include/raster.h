/**
 *  File: raster.h 
 *  Authors: Artem Golovin, Daniel Artuso 
 *  Note: all function with "__inverse" suffix perform the same operation as original function but instead,
 *        plot white on black.
 */

#ifndef SPACE_INVADERS_RASTER_H
#define SPACE_INVADERS_RASTER_H

#include "types.h"
#include "const.h"
#include "font.h"
#include "sprites.h"

/**
 * Plot Pixel
 * Require x,y of pixel to place
 *
 */
void plot_pixel(uint8* base, int x, int y);

/**
 * Plots vertical_line
 * 
 * @param base - screen base
 * @param x - starting x position
 * @param y - starting y position
 * @param height - how many pixels
 */
void plot_vertical_line(uint8* base, int x, int y, int height);

/**
 * Plots horizontal_line
 * 
 * @param base - screen base
 * @param x - starting x position
 * @param y - starting y position
 * @param width - how wide the line will be
 */
void plot_horizontal_line(uint8* base, int x, int y, int width);
void plot_horizontal_line__inverse(uint8* base, int x, int y, int width);

/**
 * Requires starting x,y coordinates (x1,y2)
 * and end line location (x2,y2)
 *
 * @param base - Screen
 * @param x1   - starting x
 * @param y1   - starting y
 * @param x2   - end x
 * @param y2   - end y
 */
void plot_line(uint8* base, int x1, int y1, int x2, int y2);

/**
 * Requires starting coordinates of rectange
 * Width is how many pixels to the right the thickness of the rectangle will be
 * Height is how many pixels towards the bottom from the starting coordinates
 *  the rectangle will be.
 *
 * @param base   - Screen
 * @param x      - x position
 * @param y      - y position
 * @param width  - width of rectange
 * @param height - height of rectange
 */
void plot_rectangle(uint8* base, int x, int y, int width, int height);
void plot_rectangle__inverse(uint8* base, int x, int y, int width, int height);

/**
 * Plots 8 bit Bitmap
 * 
 * @param base - screen base
 * @param x - starting x position
 * @param y - starting y position
 * @param bitmap - bitmap to plot
 * @param height - height of the bitmap
 */
void plot_bitmap_8(uint8* base, int x, int y, uint8* bitmap, int height);

/**
 * Plots 16 bit bitmap
 * 
 * @param base - screen base
 * @param x - starting x position
 * @param y - starting y position
 * @param bitmap - bitmap to plot
 * @param height - height of the bitmap
 */
void plot_bitmap_16(uint16* base, int x, int y, uint16* bitmap, int height);

/**
 * Fill an entire screen with splashscreen
 * 
 * @param base - screen base 
 * @param splash - splash screen, or bitmap with size of 640x400
 */
void plot_screen(uint32* base, uint32* splash);

/**
 * Prints a character
 * prints a specified character at given x,y coordinates
 * 
 * @param base - screen base
 * @param x - starting x position
 * @param y - starting y position
 * @param ch - character to pring
 */
void print_char(uint8* base, int x, int y, char ch);

/**
 * Prints a string
 * 
 * @param base - screen base
 * @param x - starting x position
 * @param y - starting y position
 * @param str - cstring to print
 */
void print_string(uint8* base, int x, int y, char* str);

/**
 * Prints number or numbers at specified x,y coordinates
 * Limitations:
 *  No negative or decimal numbers - only natural numbers
 * 
 * @param base - screen base
 * @param x - starting x position
 * @param y - starting y position
 * @param num - number to print
 */
void print_num(uint8* base, int x, int y, uint16 num);

/**
 * Various clearing functions
 */
void clear_region(void* base, int x, int y, int width, int height);

void clear_region_8(uint8* base, int x, int y, int width, int height);

void clear_region_16(uint16* base, int x, int y, int width, int height);

void clear_region_32(uint32* base, int x, int y, int width, int height);

void clear_hline(void* base, int x, int y, int width);

void clear_hline_8(uint8* base, int x, int y, int width);

void clear_hline_16(uint16* base, int x, int y, int width);

void clear_hline_32(uint32* base, int x, int y, int width);

#endif /* SPACE_INVADERS_RASTER_H */
