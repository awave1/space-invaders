#include "raster.h"
#include "font.h"


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
  plot_line(base, x, y1, x, y2);
}

/*
 * Assume x2 > x1
 */ 
void plot_horizontal_line(UINT8* base, int x1, int x2, int y) {
  plot_line(base, x1, y, x2, y);
}

void plot_line(UINT8* base, int x1, int y1, int x2, int y2) {
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

void plot_bitmap(UINT8* base, int x, int y, UINT16* bitmap, int height) {
  int i = 0;
}

/*
 * todo: make more generic
 */
void print_char(UINT8* base, int x, int y, char ch) {
  int i = 0;
  /*
   * start font from given char
   */
  UINT8* char_hex = GLYPH_START(ch);
  for (i = 0; i < 8; i++, char_hex++) {
    *(base + (y + i) * 80 + (x >> 3)) = *char_hex;
  }
}

void print_string(UINT8* base, int x, int y, char* str) {
  int i = 0;
  while(str[i] != '\0') {
    print_char(base, x, y, str[i]);
    i++;
    x += 8;
  }
}

void print_num(UINT8* base, int x, int y, UINT16 num) {
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
