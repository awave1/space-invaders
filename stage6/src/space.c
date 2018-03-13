#include "include/space.h"

/*
uint8 buffer[SCREEN_BUFFER_SIZE];
*/
uint8 second_buffer[32256];
void process_async_events(Model *model, void *base) {
  unsigned long input;
  if (has_user_input()) {
    input = get_user_input();
    on_spaceship_move(&model->player, input);
  }
}

void process_sync_events(Model *model, void *base) {
  unsigned long time_then, time_now, time_elapsed;
  int prev_score = model->scorebox.score;

  time_now = get_time();
  time_elapsed = time_now - time_then;
  if (time_elapsed > 0) {
    /* TODO: Need to delay the shots */
    /* decrement some int val */
    on_alien_shoot(model);

    on_armada_move(model);
    on_bomb_move(model);
    on_laser_move(model);

    on_laser_hit_alien(model);
    on_bomb_hit_player(model);

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
  /*TODO: Implement double buffering*/
  Model model;
  bool isScreen1;
  uint8 *base = Physbase();
  void *screen2;
  setup_game(&model, base);

  isScreen1 = true;
  screen2 = get_base(second_buffer);
  clear_qk(screen2);

  while (!model.is_game_over || model.armada.alive_count != 0) {
    if (isScreen1) {
      process_async_events(&model, base);
      process_sync_events(&model, base);
      clear_game(base); /* clears only game part of the screen */
      render(&model, base);
      Setscreen(-1, base, -1);
    } else {
      process_async_events(&model, screen2);
      process_sync_events(&model, screen2);
      clear_game(screen2); /* clears only game part of the screen */
      render(&model, screen2);
      Setscreen(-1, screen2, -1);
    }
    Vsync();
    isScreen1 = !isScreen1;
  }
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
