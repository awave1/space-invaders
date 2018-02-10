#include <stdio.h>
#include <stdlib.h>
#include <osbind.h>
#include "include/model.h"
#include "include/event.h"

int main() {
  Spaceship spaceship;
  spaceship.x = 208;
  on_spaceship_move(&spaceship);
  
  return 0;
}
