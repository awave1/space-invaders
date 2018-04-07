#include "include/isr.h"

int G_MUSIC_TIMER = 0;
int G_GAME_TIMER = 0;
int G_SHOT_TIMER = 0;
int G_SHOT_MOVE_TIMER = 0;
int G_ARMADA_MOVE_TIMER = 0;
bool G_RENDER_REQUEST = true;

Vector vbl_vector;

volatile uint8* const ikbd_control = 0xfffc00;
volatile uint8* const ikbd_status = 0xfffc00;
volatile uint8* const ikbd_rdr = 0xfffc02;

void vbl_req() {
  G_MUSIC_TIMER++;
  
  G_GAME_TIMER++;
  G_SHOT_TIMER++;
  G_ARMADA_MOVE_TIMER++;
  G_SHOT_MOVE_TIMER++;

  G_RENDER_REQUEST = true;
}

void ikbd_req() {
  
}

void install_vectors() {
  vbl_vector = install_vector(VBL_ISR, vbl_isr);
}

void remove_vectors() {
  install_vector(VBL_ISR, vbl_vector);
}

Vector install_vector(int num, Vector vector) {
  Vector* vectp = (Vector *) ((long) num << 2);
  Vector orig;
  long old_ssp = Super(0);

  orig = *vectp;
  *vectp = vector;

  Super(old_ssp);
  return orig;
}
