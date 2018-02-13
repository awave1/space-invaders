#ifndef EVENT_H
#define EVENT_H

#include <osbind.h>
#include <stdio.h>
#include "model.h"
#include "types.h"
#include "const.h"

/* 
 * note: these are temporary, todo: need to figure out how to swap
 * so we can get for example instead of 0x004b0000 -> 0x4b
 */


void on_spaceship_move(Spaceship* spaceship, unsigned long key);
void on_armada_move(Armada *armada);
void on_laser_move(Shot *laser);
void on_bomb_move(Shot *bomb);

void on_shoot();

void alien_shoots();

void on_alien_hit_bottom(Alien *alien);

void on_laser_hit_boundary(Shot *laser);
void on_bomb_hit_boundary(Shot *bomb);
void on_laser_hit_alien(Shot *laser, Alien *hit);
void on_bomb_hit_player(Spaceship *spaceship, Shot* bomb);


void on_game_start(Model* model);
void on_game_pause(Model* model);
void on_game_over(Model* model);

void _log_event(const char* event_name, const char* message);

#endif /* EVENT_H */

