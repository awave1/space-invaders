#include "include/spaceinv.h"

void start() {
  void *base = Physbase();
  disable_cursor();
  clear_qk(base);
  render_splashscreen(base);
  menu();
}

int main() {
  start();
  return 0;
}
