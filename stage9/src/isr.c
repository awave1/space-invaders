#include "include/isr.h"

int G_MUSIC_TIMER = 0;
int G_GAME_TIMER = 0;
bool G_RENDER_REQUEST = true;

Vector vbl_vector;

void vbl_isr_request() {
  G_MUSIC_TIMER++;

  if (update_music(G_MUSIC_TIMER)) {
    G_MUSIC_TIMER = 0;  
  }

  G_GAME_TIMER++;
  G_RENDER_REQUEST = true; 
}


void install_vectors() {
  vbl_vector = install_vector(VBL_ISR, vbl_isr);
}

void remove_vectors() {
  install_vector(VBL_ISR, vbl_vector);
}
