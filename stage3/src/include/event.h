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


void on_shoot();

void on_spaceship_move(Spaceship* spaceship, unsigned long key);

void on_laser_move(Shot *laser);

void bomb_moves(Shot *bomb);

void on_armada_move(Armada *armada);

void alien_shoots();

void laser_hit_alien(Shot *laser, Alien *hit);

void laser_hit_boundary(Shot *laser);

void bomb_hit_boundary(Shot *bomb);

void bomb_hit_player(Spaceship *spaceship);

void alien_hit_bottom(Spaceship *spaceship);

void alien_hit_side(Armada *armada);

void player_hit_side(Spaceship *spaceship);

void alien_hit_player(Spaceship *spaceship);
#endif /* EVENT_H */
