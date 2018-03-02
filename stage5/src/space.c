#include "include/space.h"

void clear_aliens(Armada* armada, uint16* base) {
  int i, j, x, y;
  for (i = 0; i < ALIENS_ROWS; i++) {
    for (j = 0; j < ALIENS_COLS; j++) {
      x = armada->aliens[i][j].x;
      y = armada->aliens[i][j].y;
      clear_region(base, x, y, 16, 16);
    }
  }
}

long get_time() {
  long* timer = (long*) SYSTEM_CLOCK;
  long old_ssp = Super(0);
  long time_now = *timer;
  Super(old_ssp);
  return time_now;
}

void disable_cursor() {
	printf("\033f");
	fflush(stdout);
}

void process_async_events(Model* model, void* base) {
  unsigned long input;

  if (has_user_input()) {
    input = get_user_input();
    clear_region(base, model->player.x, model->player.y, 16, 16);
    on_spaceship_move(&model->player, input);
    render_spaceship(&model->player, base);
  }
}

void process_sync_events(Model* model, void* base) {
  unsigned long time_then, time_now, time_elapsed;

  time_now = get_time();
  time_elapsed = time_now - time_then;
  if (time_elapsed > 0) {
    clear_aliens(&model->armada, base);
    on_armada_move(model);
    render_armada(&model->armada, base);
    time_then = time_now;
  }
}

void setup_game(Model* model, void* base) {
  disable_cursor();
  on_game_start(model);
  clear_qk(base);
  render(model, base);
}

void game_loop() {
  Model model;
  void* base = Physbase();

  setup_game(&model, base);

  while (!model.is_game_over) {
    process_async_events(&model, base);
    process_sync_events(&model, base);
  }
}

int main() {
  game_loop();
  return 0;
}
