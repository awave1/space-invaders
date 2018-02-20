#include <stdio.h>
#include "include/render.h"

int main() {
  Model model;
  uint16 *base = (uint16*) Physbase();
  render(&model, base);
  return 0;
}
