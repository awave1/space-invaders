#include "include/menu.h"

void menu() {
  process_keyboard_choice();
}


void process_keyboard_choice() {
  unsigned long input;
  int choice = 1;
  int prev_choice = choice;

  draw_choice_selector(choice);
  while (input != ENTER_KEY && input != ESC_KEY) {
    if (has_user_input()) {
      input = get_user_input();
      prev_choice = choice;
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
      clear_choice_selector(prev_choice);
      draw_choice_selector(choice);
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


void draw_choice_selector(int choice) {
  uint16 *base = Physbase();

  switch (choice) {
    default:
    case 1:
      plot_bitmap_16(base, SELECTION_X, SELECTION_1Y, menu_pointer,
                     SPRITE_SIZE);
      break;
    case 2:
      plot_bitmap_16(base, SELECTION_X, SELECTION_2Y, menu_pointer,
                     SPRITE_SIZE);
      break;
    case 3:
      plot_bitmap_16(base, SELECTION_X, SELECTION_3Y, menu_pointer,
                     SPRITE_SIZE);
      break;
  }
}

void clear_choice_selector(int choice) {
  uint16 *base = Physbase();

  switch (choice) {
    default:
    case 1:
      clear_region(base, SELECTION_X, SELECTION_1Y, 16, 16);
      break;
    case 2:
      clear_region(base, SELECTION_X, SELECTION_2Y, 16, 16);
      break;
    case 3:
      clear_region(base, SELECTION_X, SELECTION_3Y, 16, 16);
      break;
  }
}