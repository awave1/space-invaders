#ifndef EVENT_H
#define EVENT_H

/* todo: rename event function to on_<event> format, like on_spaciship_move */

#include <osbind.h>
#include "model.h"

/* 
 * note: these are temporary, todo: need to figure out how to swap
 * so we can get for example instead of 0x004b0000 -> 0x4b
 */
const unsigned long LEFT_KEY =  0x004b0000;
const unsigned long RIGHT_KEY = 0x004d0000;
const unsigned long SPACE_KEY = 0x00390020;


void shoot_weapon();

void on_spaceship_move(Spaceship* spaceship);

void laser_moves();

void bomb_moves();

void armada_moves();

void alien_shoots();

void laser_hit_alien();

void laser_hit_boundary();

void bomb_hit_boundary();

void bomb_hit_player();

void alien_hit_bottom();

void alien_hit_side();

void player_hit_side();

void alien_hit_player();
#endif /* EVENT_H */
