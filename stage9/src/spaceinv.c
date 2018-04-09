#include "include/spaceinv.h"

void start() {
  uint16 *base = get_video_base();

  disable_cursor();
  clear_qk(base);
  render_splashscreen(base);
  menu();
}

int main() {
  install_vectors();
  start();
  clear_interrupts();
  stop_sound();
  return 0;
}
