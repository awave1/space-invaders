#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <osbind.h>
#include <linea.h>
#include <osbind.h>
#include "include/model.h"
#include "include/event.h"
#include "include/render.h"

int main() {
  Model model;
  void *base = Physbase();
  on_game_start(&model);
  render(&model, base);
  return 0;
}
