/**
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

int player_count = 2;

void process_async_events(Model* model) {
  unsigned long input;
  if (has_user_input()) {
    input = get_user_input();

    if (input != MOUSE_MOVE_CODE) {
      if (input == ESC_KEY)
        game_is_running = false;

      if (key_repeat)
        on_spaceship_move(&model->player, input);
    } 
  }
}

void process_sync_events(Model* model) {
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

uint8* get_base(uint8 *second_buffer) {
  uint8* base;
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
  uint16* base;
  uint16* base2 = (uint16*) get_base(second_buffer);
  long old_ssp;
  int player;

  for (player = 0; player < player_count; player++) {
    base = get_video_base();

    setup_game(&model, base);
    clear_qk(base2);

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
            clear_game(base2);
            render(&model, base2);
            set_video_base(base2);
          }
          G_RENDER_REQUEST = false;
          swap_screens = !swap_screens;
        }
      } else {
        game_is_running = false;
      }
    }

    set_video_base(base);
    if (player != player_count)
      show_start_player(base);
    game_is_running = true;
  }

  show_game_over(base);
  
  clear_ikbd_buffer();

  clear_qk(base);
  render_splashscreen((uint32*) base);
}

void show_game_over(uint16* base) {
  bool has_input = false;
  clear_game(base);
  render_game_over((uint32*) base);
  while (!has_input)
    has_input = has_user_input();
}

void show_next_player(uint16* base) {
  bool has_input = false;
  clear_game(base);
  render_next_player((uint32*) base);
  while (!has_input)
    has_input = has_user_input();
}

void clear_interrupts() {
  clear_ikbd_buffer();
  remove_vectors();
}

void setup_game(Model* model, void* base) {
  disable_cursor();
  on_game_start(model);
  clear_qk(base);
  render(model, base);
}
