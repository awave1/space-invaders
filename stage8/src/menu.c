#include "include/menu.h"

void menu() {
  /*TODO: draw splash screen*/
  uint16 *base = Physbase();

  process_keyboard_choice();
}


void process_keyboard_choice() {
  unsigned long input;
  int choice = 1;
  while (input != ENTER_KEY && input != ESC_KEY) {
    if (has_user_input()) {
      input = get_user_input();
      switch (input) {
        case UP_KEY:
          if (choice > 1)
            choice--;
          break;
        case DOWN_KEY:
          if (choice < 3)
            choice++;
          break;
        default:
          break;
      }
      /*TODO: process drawing selection icon*/
      if (input == ENTER_KEY)
        select_option(choice);
      if (input == ESC_KEY)
        select_option(3);
    }
  }
}


void select_option(int choice) {
  switch (choice) {
    case 1:
      game_loop();
      stop_sound();
      break;
    case 2:
      /*Two player game mode here*/
    case 3:
    default:
      /*Quit option*/
      break;
  }
}