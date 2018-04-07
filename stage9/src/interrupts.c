#include "include/interrupts.h"

int G_MUSIC_TIMER = 0;
int G_GAME_TIMER = 0;
bool render_request = true;

void vbl_isr_request() {
  G_MUSIC_TIMER++;

  if (update_music(G_MUSIC_TIMER)) {
    G_MUSIC_TIMER = 0;  
  }

  G_GAME_TIMER++;
  render_request = true; 
}

