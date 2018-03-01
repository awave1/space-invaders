#ifndef EVENT_H
#define EVENT_H

#include <osbind.h>
#include "model.h"

void on_spaceship_move(Spaceship *spaceship, unsigned long key);

void on_armada_move(Model *model);
void on_laser_move(Shot *laser);
void on_bomb_move(Shot *bomb);

void on_shoot();

void alien_shoots();

void on_alien_hit_bottom(Alien *alien);

void on_laser_hit_boundary(Shot *laser);
void on_bomb_hit_boundary(Shot *bomb);
void on_laser_hit_alien(Shot *laser, Alien *hit);

void on_bomb_hit_player(Spaceship *spaceship, Shot *bomb);


void on_game_start(Model *model);

void on_game_pause(Model *model);

void on_game_over(Model *model);

bool has_user_input();

unsigned long get_user_input();

#endif /* EVENT_H */

