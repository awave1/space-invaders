/*
 *  File: game.c
 *  Authors: Artem Golovin, Daniel Artuso
 */
#include "include/game.h"

const uint8 second_buffer[32256]; /*Second Screen for double buffering */

extern bool G_RENDER_REQUEST;
extern int G_SHOT_TIMER;
extern int G_GAME_TIMER;
extern int G_SHOT_MOVE_TIMER;
extern int G_ARMADA_MOVE_TIMER;
extern int G_MUSIC_TIMER;
extern int G_KEY_REPEAT_TICKS;
extern bool key_repeat;


bool game_is_running = true;

void process_async_events(Model *model) {
  unsigned long input;
  if (has_user_input()) {
    if (key_repeat && G_KEY_REPEAT_TICKS >= 2) {
      input = get_user_input();

      if (input == ESC_KEY)
        game_is_running = false;

      on_spaceship_move(&model->player, input);
      G_KEY_REPEAT_TICKS = 0;
    }
  }
}

void process_sync_events(Model *model) {
  int prev_score = model->scorebox.score;

  if (G_GAME_TIMER > 0) {
    if (model->armada.alive_count >= 20 && G_SHOT_TIMER >= 150) {
      on_alien_shoot(model);
      G_SHOT_TIMER = 0;
    } else if (model->armada.alive_count < 20 && G_SHOT_TIMER >= 75) {
      on_alien_shoot(model);
      G_SHOT_TIMER = 0;
    }

    on_laser_hit_alien(model);
    on_bomb_hit_player(model);

    if (model->armada.alive_count >= 20 && G_ARMADA_MOVE_TIMER >= 3) {
      on_armada_move(model);
      G_ARMADA_MOVE_TIMER = 0;
    } else if (model->armada.alive_count < 20 && G_ARMADA_MOVE_TIMER >= 2) {
      on_armada_move(model);
      G_ARMADA_MOVE_TIMER = 0;
    } else if (model->armada.alive_count < 10) {
      on_armada_move(model);
    }

    if(G_SHOT_MOVE_TIMER >= 2) {
      on_bomb_move(model);
      on_laser_move(model);
      G_SHOT_MOVE_TIMER = 0;
    }
  }
}

void process_game_over() {
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
  long old_ssp;
  bool game_over_screen_flag = false;

  base = get_video_base();

  setup_game(&model, base);

  screen2 = get_base(second_buffer);
  clear_qk(screen2);

  start_music();
  while (game_is_running && !model.is_game_over || model.scorebox.score >= MAX_SCORE) {
    process_async_events(&model);
    process_sync_events(&model);

    if (update_music(G_MUSIC_TIMER))
      G_MUSIC_TIMER = 0;

    if (model.armada.alive_count == 0)
      on_next_wave(&model);

    if (!model.is_game_over) {
      if (G_RENDER_REQUEST) {
        if (swap_screens) {
          clear_game(base); /* clears only game part of the screen */
          render(&model, base);
          set_video_base(base);

        } else {
          clear_game(screen2);
          render(&model, screen2);
          set_video_base(screen2);
        }
        G_RENDER_REQUEST = false;
        swap_screens = !swap_screens;
      }
    } else {
      game_is_running = false;
    }
  }
  set_video_base(base);

/*
  if (!game_is_running) {
    clear_game(base);
    render_game_over(base);

    do {
      game_over_screen_flag = has_user_input();
    } while (!game_over_screen_flag);
  }
  */

  clear_qk(base);
  render_splashscreen(base);
}

void clear_interrupts() {
  clear_ikbd_buffer();
  remove_vectors();
}

void setup_game(Model *model, void *base) {
  disable_cursor();
  on_game_start(model);
  clear_qk(base);
  render(model, base);
}
