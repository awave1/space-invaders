#include "include/menu.h"

void menu() {
  process_keyboard_choice();
}

void process_keyboard_choice() {
  unsigned long input;
  int choice = MENU_CHOICE_START_1_PLAYER;
  int mouse_choice;
  int prev_choice = choice;
  uint16 *base = get_video_base();
  bool exit = false;

  init_mouse(base);

  draw_choice_selector(choice, base);
  while (input != ENTER_KEY && input != ESC_KEY) {
    upd_mouse_events(base);
    if (has_user_input()) {
      prev_choice = choice;
      input = get_user_input();
      switch (input) {
        case UP_KEY:
          if (choice > MENU_CHOICE_START_1_PLAYER)
            choice--;
          break;
        case DOWN_KEY:
          if (choice < MENU_CHOICE_EXIT)
            choice++;
          break;
        default:
          break;
      }
      
      clear_choice_selector(prev_choice, base);
      draw_choice_selector(choice, base);

      if (input == ENTER_KEY || G_MOUSE_LEFT_CLICK)
        select_option(choice);
      if (input == ESC_KEY)
        select_option(MENU_CHOICE_EXIT);
    }

    if (mouse_location() != -1) {
      prev_choice = choice;
      choice = mouse_location();
      clear_choice_selector(prev_choice, base);
      draw_choice_selector(choice, base);

/*
      if (G_MOUSE_LEFT_CLICK)
        select_option(mouse_choice);
        */
    }

  }
}

void select_option(int choice) {
  switch (choice) {
    case MENU_CHOICE_START_1_PLAYER:
      game_loop();
      stop_sound();
      break;
    case MENU_CHOICE_START_2_PLAYERS:
      /*Two player game mode here*/
    case MENU_CHOICE_EXIT:
    default:
      /*Quit option*/
      clear_interrupts();
      break;
  }
}


void draw_choice_selector(int choice, uint16* base) {

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

void clear_choice_selector(int choice, uint16* base) {
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

int mouse_location() {
  int mouse_location = -1;
  bool valid_x = (G_MOUSE_X >= 220 && G_MOUSE_X <= 580);

  if (valid_x && (G_MOUSE_Y >= 247 && G_MOUSE_Y <= 263))
    mouse_location = MENU_CHOICE_START_1_PLAYER;
  else if (valid_x && (G_MOUSE_Y >= 293 && G_MOUSE_Y <= 309))
    mouse_location = MENU_CHOICE_START_2_PLAYERS;
  else if (valid_x && (G_MOUSE_Y >= 337 && G_MOUSE_Y <= 353))
    mouse_location = MENU_CHOICE_EXIT;
  
  return mouse_location;
}
