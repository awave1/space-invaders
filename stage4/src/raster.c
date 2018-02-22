#include "include/raster.h"
#include "include/font.h"

/*
 * Description: 
 *      1. x >> 3 (x / 8)     - gets the byte where the required bit will be activated
 *      2. x & 7  (x % 8)     - gets which bit inside that byte will be activated
 *      3. 1 << (7 - (x & 7)) - results in binary representing selected byte
 * 
 */
void plot_pixel(uint8 *base, int x, int y) {
  if (in_bounds(x, y))
    *(base + (y * 80) + (x >> 3)) |= 1 << (7 - (x & 7));
}

/*
 * Assume y2 > y1
 * 
 * works faster than calling plot_line
 */
void plot_vertical_line(uint8 *base, int x, int y, int height) {
  int i = 0;
  for (i = 0; i < height; i++)
    *(base + ((y + i) * 80) + (x >> 3)) |= 1 << 7 - (x & 7);
}

/*
 * Assume x2 > x1
 * 
 * works faster than calling plot_line
 */
void plot_horizontal_line(uint8 *base, int x, int y, int width) {
  int i = 0;
  int x_count = width >> 3;
  uint8 *draw = base + (y * 80) + (x >> 3);

  for (i = 0; i < x_count; i++)
    *(draw++) |= 0xff;
}

void plot_horizontal_line__inverse(uint8 *base, int x, int y, int width) {
  int i = 0;
  int x_count = width >> 3;
  uint8 *draw = base + (y * 80) + (x >> 3);

  for (i = 0; i < x_count; i++)
    *(draw++) &= 0x00;
}

void plot_line(uint8 *base, int x1, int y1, int x2, int y2) {
  int delta_x = x2 - x1;
  int delta_y = y2 - y1;

  int sx = x1 < x2 ? 1 : -1;
  int sy = y1 < y2 ? 1 : -1;


  int err = (delta_x > delta_y ? delta_x : -delta_y) / 2;
  int e2;

  for (;;) {
    plot_pixel(base, x1, y1);
    if (x1 == x2 && y1 == y2)
      break;

    e2 = err;
    if (e2 > -delta_x) {
      err -= delta_y;
      x1 += sx;
    }

    if (e2 < delta_y) {
      err += delta_x;
      y1 += sy;
    }
  }
}

void plot_rectangle(uint8 *base, int x, int y, int width, int height) {
  register int i = 0;
  uint8 *_base = base;
  for (i = 0; i < height; i++) {
    plot_horizontal_line(_base, x, y, width);
    _base += 80;
  }
}

void plot_rectangle__inverse(uint8 *base, int x, int y, int width, int height) {
  int i = 0;
  uint8 *_base = base;
  for (i = 0; i < height; i++) {
    plot_horizontal_line__inverse(_base, x, y, width);
    _base += 80;
  }
}

void plot_bitmap_8(uint8 *base, int x, int y, uint8 *bitmap, int height) {
  int i = 0;
  uint8 *location = base + (y * 80) + (x >> 3);
  for (i = 0; i < height; i++) {
    *location |= *(bitmap++);
    location += 80;
  }
}

/*
 * Plot 16x16 bitmap
 * 
 * Note: (x >> 4) = (x / 16)
 */
void plot_bitmap_16(uint16 *base, int x, int y, uint16 *bitmap, int height) {
  int i = 0;
  uint16 *location = base + (y * 40) + (x >> 4);
  for (i = 0; i < height; i++) {
    *location |= *(bitmap++);
    location += 40;
  }
}

/*
 * todo: make more generic
 */
void print_char(uint8 *base, int x, int y, char ch) {
  int i = 0;
  /*
  * start font from given char
  */
  uint8 *char_hex = GLYPH_START(ch);
  for (i = 0; i < 8; i++, char_hex++) {
    *(base + (y + i) * 80 + (x >> 3)) = *char_hex;
  }
}

void print_string(uint8 *base, int x, int y, char *str) {
  int i = 0;
  while (str[i] != '\0') {
    print_char(base, x, y, str[i]);
    i++;
    x += 8;
  }
}

void print_num(uint8 *base, int x, int y, uint16 num) {
  char a, b, c, d;

  d = (num % 10) + '0';
  num /= 10;

  c = (num % 10) + '0';
  num /= 10;

  b = (num % 10) + '0';
  num /= 10;

  a = (num % 10) + '0';

  print_char(base, x, y, a);
  print_char(base, x + 8, y, b);
  print_char(base, x + 16, y, c);
  print_char(base, x + 24, y, d);
}

/*
 * Clear screen (each longword (640 / 32) portion of the screen) 
 */

void _clear_screen(uint32 *base, bool inverse) {
  int x, y;
  for (x = 0; x < 20; x++) {
    for (y = 0; y < 399; y++) {
      *(base + (y * 20) + x) = !inverse ? 0x00000000 : 0xffffffff;
    }
  }
}

void clear_screen(uint32 *base) {
  _clear_screen(base, false);
}

void clear_screen__inverse(uint32 *base) {
  _clear_screen(base, true);
}
