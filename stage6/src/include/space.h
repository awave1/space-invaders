/*
 *  File: space.h 
 *  Authors: Artem Golovin, Daniel Artuso 
 */

#ifndef SPACE_INVADERS_GAME
#define SPACE_INVADERS_GAME

#include <osbind.h>
#include <stdio.h>
#include "model.h"
#include "event.h"
#include "render.h"
#include "clear_qk.h"
#include "clear_ga.h"

/**
 * Game loop, that processes async/sync events and handles double buffering
 */
void game_loop();

/**
 * Process all async events
 * 
 * @param model - Game model
 */
void process_async_events(Model *model);

/**
 * Process all sync events
 * 
 * @param model - Game model
 */
void process_sync_events(Model *model);

/**
 * Set up the game, clear the screen and draw the initial state of the game
 * 
 * @param model - Game model
 * @param base  - Screen
 */
void setup_game(Model *model, void *base);

/**
 * Get the system time
 * 
 * @return long - system time
 */
long get_time();

/**
 * @brief Get the 256 byte aligned base
 * 
 * @param second_buffer - second buffere used for double buffering technique
 * @return uint8* - 256 byte aligned screen base
 */
uint8 *get_base(uint8 *second_buffer);

#endif /* SPACE_INVADERS_GAME */
