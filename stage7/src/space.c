#include "include/space.h"

const uint8 second_buffer[32256]; /*Second Screen for double buffering */
int next_shot = 50; /* TODO: Replace asap */

void process_async_events(Model *model) {
  unsigned long input;
  if (has_user_input()) {
    input = get_user_input();
    on_spaceship_move(&model->player, input);
    if (input == ESC_KEY)
      on_game_over(model);
  }
}

void process_sync_events(Model *model) {
  unsigned long time_then, time_now, time_elapsed;
  int prev_score = model->scorebox.score;

  time_now = get_time();
  time_elapsed = time_now - time_then;
  if (time_elapsed > 0) {
    if (next_shot == 0) {
      on_alien_shoot(model);
      next_shot = 50;
    }

    on_laser_hit_alien(model);
    on_bomb_hit_player(model);

    on_armada_move(model);
    on_bomb_move(model);
    on_laser_move(model);

    next_shot--;
    time_then = time_now;
  }
}

/*get base function*/
uint8 *get_base(uint8 *second_buffer) {
  /*make sure byte aligned*/
  uint8 *base;
  uint16 difference;
  base = second_buffer;
  difference = (int) base;
  difference %= 0x100;
  difference = 0x100 - difference;
  return base + difference;
}

void game_loop() {
  Model model;
  bool swap_screens = true;
  uint8 *base = Physbase();
  void *screen2;
  setup_game(&model, base);

  screen2 = get_base(second_buffer);
  clear_qk(screen2);

  while (!model.is_game_over || model.scorebox.score >= MAX_SCORE) {
    process_async_events(&model);
    process_sync_events(&model);
    
    if (model.armada.alive_count == 0)
      on_next_wave(&model);

    if (!model.is_game_over) {
      if (swap_screens) {
        clear_game(base); /* clears only game part of the screen */
        render(&model, base);
        Setscreen(-1, base, -1);
      } else {
        clear_game(screen2);
        render(&model, screen2);
        Setscreen(-1, screen2, -1);
      }
      Vsync();
      swap_screens = !swap_screens;
    } else {
      /* 
        The only solution that worked. We tried adding a boolean flag, but it wouldn't break out of the loop 
        That is why we had to use break statement here.
      */
      break;
    }
  }
  render(&model, base);
  Setscreen(-1, base, -1);
  Vsync();
}

long get_time() {
  long *timer = (long *) SYSTEM_CLOCK;
  long old_ssp = Super(0);
  long time_now = *timer;
  Super(old_ssp);
  return time_now;
}

void setup_game(Model *model, void *base) {
  disable_cursor();
  on_game_start(model);
  clear_qk(base);
  render(model, base);
}

int main() {
  game_loop();
  return 0;
}
