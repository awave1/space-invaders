#include "include/menu.h"

int MENU_STATE = MENU_CHOICE_START_1_PLAYER;
bool VALID_CLICK = false;

void menu() {
  process_menu_choice();
}

void process_menu_choice() {
  unsigned long input;
  int choice = MENU_CHOICE_START_1_PLAYER;
  int prev_choice = choice;
  int mouse_choice;
  int prev_mouse_choice;
  uint16 *base = get_video_base();

  init_mouse(base);

  draw_choice_selector(choice, base);
  draw_menu_underlines(base);

  while (MENU_STATE != MENU_CHOICE_EXIT) {
    upd_mouse_events(base);

    if (has_user_input()) {
      clear_choice_selector(mouse_choice, base);
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

      if (input == ENTER_KEY)
        select_option(choice);
      if (input == ESC_KEY)
        select_option(MENU_CHOICE_EXIT);

    } else if (has_mouse_input()) {
      prev_mouse_choice = mouse_choice;
      mouse_choice = mouse_location();
      if (mouse_choice != INVALID_MOUSE_CHOICE) {
        if (VALID_CLICK && G_MOUSE_LEFT_CLICK)
          select_option(mouse_choice);
      }
    }
  }
}

void select_option(int choice) {
  switch (choice) {
    case MENU_CHOICE_START_1_PLAYER:
      MENU_STATE = MENU_CHOICE_START_1_PLAYER;
      game_loop();
      stop_sound();
      break;
    case MENU_CHOICE_START_2_PLAYERS:
      MENU_STATE = MENU_CHOICE_START_2_PLAYERS;
    case MENU_CHOICE_EXIT:
    default:
      MENU_STATE = MENU_CHOICE_EXIT;
      break;
  }
}


void draw_choice_selector(int choice, uint16* base) {

  switch (choice) {
    default:
    case MENU_CHOICE_START_1_PLAYER:
      plot_bitmap_16(base, SELECTION_X, SELECTION_1Y, menu_pointer,
                     SPRITE_SIZE);
      break;
    case MENU_CHOICE_START_2_PLAYERS:
      plot_bitmap_16(base, SELECTION_X, SELECTION_2Y, menu_pointer,
                     SPRITE_SIZE);
      break;
    case MENU_CHOICE_EXIT:
      plot_bitmap_16(base, SELECTION_X, SELECTION_3Y, menu_pointer,
                     SPRITE_SIZE);
      break;
  }
}

void draw_menu_underlines(uint16* base) {
  int y1 = SELECTION_1Y + 25;
  int y2 = SELECTION_2Y + 25;
  int y3 = SELECTION_3Y + 25;
  int x = SELECTION_X + 30;
  int width = 148;
  int height = 5;
  plot_rectangle__inverse((uint8*) base, x, y1, width, height);
  plot_rectangle__inverse((uint8*) base, x, y2, width, height);
  plot_rectangle__inverse((uint8*) base, x, y3, width, height);
}

void clear_choice_selector(int choice, uint16* base) {
  switch (choice) {
    default:
    case MENU_CHOICE_START_1_PLAYER:
      clear_region(base, SELECTION_X, SELECTION_1Y, 16, 16);
      break;
    case MENU_CHOICE_START_2_PLAYERS:
      clear_region(base, SELECTION_X, SELECTION_2Y, 16, 16);
      break;
    case MENU_CHOICE_EXIT:
      clear_region(base, SELECTION_X, SELECTION_3Y, 16, 16);
      break;
  }
}

int mouse_location() {
  int mouse_location = INVALID_MOUSE_CHOICE;
  bool valid_x = (G_MOUSE_X >= 220 && G_MOUSE_X <= 580);
  bool valid_y_choice1 = (G_MOUSE_Y >= 247 && G_MOUSE_Y <= 263);
  bool valid_y_choice2 = (G_MOUSE_Y >= 293 && G_MOUSE_Y <= 309);
  bool valid_y_choice3 = (G_MOUSE_Y >= 337 && G_MOUSE_Y <= 353);

  if (valid_x && valid_y_choice1)
    mouse_location = MENU_CHOICE_START_1_PLAYER;
  else if (valid_x && valid_y_choice2)
    mouse_location = MENU_CHOICE_START_2_PLAYERS;
  else if (valid_x && valid_y_choice3)
    mouse_location = MENU_CHOICE_EXIT;

  VALID_CLICK = (valid_x && valid_y_choice1) || 
                (valid_x && valid_y_choice2) ||
                (valid_x && valid_y_choice3);
  
  return mouse_location;
}

