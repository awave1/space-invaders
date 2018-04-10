/*
 *  File: event.h 
 *  Authors: Artem Golovin, Daniel Artuso 
 */

#ifndef SPACE_INVADERS_EVENT_H
#define SPACE_INVEDERS_EVENT_H

#include <osbind.h>
#include "model.h"
#include "effects.h"
#include "isr.h"

/**
 * Event that moves spaceship and shoots on keypress. 
 * Spaceship sprite is moved when following keys are pressed:
 *  - Left Arrow Key: move to the left 
 *  - Right Arrow Key: move to the right
 *  - Spacebar: shoot
 *  
 * @param spaceship - Spaceship model
 * @param key - keycode of button being pressed
 */
void on_spaceship_move(Spaceship* spaceship, unsigned long key);

/**
 * Event that moves armada of aliens.
 * Armada is moved in snaking fashion.
 * 
 * @param model - Game model
 */
void on_armada_move(Model* model);

/**
 * Event that moves spaceship's laser.
 * 
 * @param model - Game model
 */
void on_laser_move(Model* model);

/**
 * Event that moves alien bombs.
 * 
 * @param model - Game model
 */
void on_bomb_move(Model* model);

/**
 * Event that makes alien shoot bombs.
 * 
 * @param model - Game model
 */
void on_alien_shoot(Model* model);

/**
 * Event that checks if spaceship's laser collided with an alien.
 * 
 * @param model - Game model
 */
void on_laser_hit_alien(Model* model);

/**
 * Event that checks if alien bomb hit spaceship.
 * If collision happened, then on_game_over event is called
 * 
 * @param model - Game model
 */
void on_bomb_hit_player(Model* model);

/**
 * Event that is called once before the game started.
 * It calls init_model to initialize the whole game model
 * 
 * @param model - Game model
 */
void on_game_start(Model* model);

/**
 * Event that is called when the game is paused.
 * Note: not implemented yet
 * 
 * @param model - Game model
 */
void on_game_pause(Model* model);

/**
 * Called when game is over
 * 
 * @param model 
 */
void on_game_over(Model* model);

/**
 * Event that is called when the next wave needs to be generated
 * 
 * @param model - Game model
 */
void on_next_wave(Model* model);

/**
 * Checks if user entered a character
 * 
 * @return true if user entered a character
 */
bool has_user_input();

/**
 * Checks if user has moved mouse (created mouse input)
 *
 * @return true if user has moved the mouse
 */
bool has_mouse_input();

/**
 * Get the user input from keyboard
 * 
 * @return unsigned long - keycode
 */
unsigned long get_user_input();

#endif /* SPACE_INVADERS_EVENT_H */
