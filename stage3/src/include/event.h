#ifndef EVENT_H
#define EVENT_H

#include <osbind.h>
#include <stdio.h>
#include "model.h"
#include "types.h"
#include "const.h"
#include "isr.h"
#include "psg.h"


void on_spaceship_move(Spaceship* spaceship, unsigned long key);
void on_armada_move(Model* model, bool can_move);
void on_laser_move(Model *model);
void on_bomb_move(Model *model);

void on_shoot();

void alien_shoots();

void on_alien_hit_bottom(Alien *alien);

void on_laser_hit_boundary(Shot *laser);
void on_bomb_hit_boundary(Shot *bomb);
void on_laser_hit_alien(Model* model);
void on_bomb_hit_player(Model* model);


void on_game_start(Model* model);
void on_game_pause(Model* model);
void on_game_over(Model* model);
void on_game_exit();

void _log_event(const char* event_name, const char* message, ...);

#endif /* EVENT_H */

