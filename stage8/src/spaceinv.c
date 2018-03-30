#include "include/spaceinv.h"

void start() {
  long old = Super(0);
  uint16 *base = get_video_base();
  Super(old);

  disable_cursor();
  clear_qk(base);
  render_splashscreen(base);
  menu();
}

int main() {
  start();
  return 0;
}
