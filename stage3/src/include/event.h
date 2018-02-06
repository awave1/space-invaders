#ifndef EVENT_H
#define EVENT_H

//todo:review these function and determine required params
//Asynchronous Events
void shoot_weapon();

void move_spaceship();

//Synchronous Events
void laser_moves();

void bomb_moves();

void armada_moves();

void alien_shoots();

//condition based events
void laser_hit_alien();

void laser_hit_boundary();

void bomb_hit_boundary();

void bomb_hit_player();

void alien_hit_bottom();

void alien_hit_side();

void player_hit_side();

void alien_hit_player();
#endif /* EVENT_H */
