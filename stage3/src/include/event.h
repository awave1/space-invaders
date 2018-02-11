#ifndef EVENT_H
#define EVENT_H

/* todo: rename event function to on_<event> format, like on_spaciship_move */

#include <osbind.h>
#include <stdio.h>
#include "model.h"
#include "types.h"

/* 
 * note: these are temporary, todo: need to figure out how to swap
 * so we can get for example instead of 0x004b0000 -> 0x4b
 */
const unsigned long LEFT_KEY =  0x4b;
const unsigned long RIGHT_KEY = 0x4d;
const unsigned long SPACE_KEY = 0x39;

const bool EVENT_DEBUG = true;


void on_shoot();

void on_spaceship_move(Spaceship* spaceship);

void laser_moves(Shot *laser);

void bomb_moves(Shot *bomb);

void on_armada_move(Armada *armada);

void alien_shoots();

void laser_hit_alien(Shot *laser, Alien *hit);

void laser_hit_boundary(Shot *laser);

void bomb_hit_boundary();

void bomb_hit_player();

void alien_hit_bottom();

void alien_hit_side();

void player_hit_side();

void alien_hit_player();
#endif /* EVENT_H */
