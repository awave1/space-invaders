#include "include/game.h"

const uint8 second_buffer[32256]; /*Second Screen for double buffering */
extern bool G_RENDER_REQUEST;
extern int G_SHOT_TIMER;
extern int G_GAME_TIMER;
extern int G_SHOT_MOVE_TIMER;
extern int G_ARMADA_MOVE_TIMER;


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
  int prev_score = model->scorebox.score;

  if (G_GAME_TIMER > 0) {
    if (G_SHOT_TIMER >= 150) {
      on_alien_shoot(model);
      G_SHOT_TIMER = 0;
    }

    on_laser_hit_alien(model);
    on_bomb_hit_player(model);

    if (G_ARMADA_MOVE_TIMER >= 3) {
      on_armada_move(model);
      G_ARMADA_MOVE_TIMER = 0;
    }

    if (G_SHOT_MOVE_TIMER >= 2) {
      on_bomb_move(model);
      on_laser_move(model);
      G_SHOT_MOVE_TIMER = 0;
    }
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
  void *screen2;
  uint16* base;
  /*unsigned long prev_call = get_time();*/
  long old_ssp;

  old_ssp = Super(0);
  base = get_video_base();
  Super(old_ssp);


  setup_game(&model, base);

  screen2 = get_base(second_buffer);
  clear_qk(screen2);
  start_music();

  install_vectors();
  while (!model.is_game_over || model.scorebox.score >= MAX_SCORE) {
    process_async_events(&model);
    process_sync_events(&model);

    if (model.armada.alive_count == 0)
      on_next_wave(&model);

    if (!model.is_game_over) {
      if (G_RENDER_REQUEST) {
        if (swap_screens) {
          clear_game(base); /* clears only game part of the screen */
          render(&model, base);

          old_ssp = Super(0);
          set_video_base(base);
          Super(old_ssp);

        } else {
          clear_game(screen2);
          render(&model, screen2);

          old_ssp = Super(0);
          set_video_base(screen2);
          Super(old_ssp);
        }
        G_RENDER_REQUEST = false;
        swap_screens = !swap_screens;
      }
    } else {
      /* 
        The only solution that worked. We tried adding a boolean flag, but it wouldn't break out of the loop 
        That is why we had to use break statement here.
      */
      break;
    }
  }
  remove_vectors();
  render(&model, base);

  old_ssp = Super(0);
  set_video_base(base);
  Super(old_ssp);
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
