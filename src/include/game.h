/*
 *  Authors: Artem Golovin, Daniel Artuso 
 */

#ifndef SPACE_INVADERS_GAME_LOOP
#define SPACE_INVADERS_GAME_LOOP

#include <osbind.h>
#include <stdio.h>
#include "model.h"
#include "event.h"
#include "render.h"
#include "psg.h"
#include "music.h"
#include "clear.h"
#include "video.h"

#define PLAYER_ONE 1
#define PLAYER_TWO 2

/**
 * Game loop, that processes async/sync events and handles double buffering
 */
void game_loop();

/**
 * Process all asynchronous events
 * 
 * @param model - Game model
 */
void process_async_events(Model* model);

/**
 * Process all synchronous events
 * 
 * @param model - Game model
 */
void process_sync_events(Model* model, int player);

/**
 * Set up the game, clear the screen and draw the initial state of the game
 * 
 * @param model        - Game model
 * @param base         - Screen
 * @param player_count - number of players
 */
void setup_game(Model* model, void *base, int player_count);

/**
 * Removes the installed vectors and cleard ikbd buffer 
 */
void clear_interrupts();

/**
 * Shows game over screen to the player 
 * 
 * @param base - screen
 */
void show_game_over(uint16* base);

/**
 * Shows notification with next player
 * 
 * @param base - screen
 */
void show_next_player(uint16* base);

/**
 * Get the 256 byte aligned base
 * 
 * @param second_buffer - second buffere used for double buffering technique
 * @return uint8* - 256 byte aligned screen base
 */
uint8* get_base(uint8 *second_buffer);

/**
 * Starts the game with single player
 */
void start_single_player();

/**
 * Starts the game with 2 players, each player take turns
 */
void start_multiplayer();

#endif /* SPACE_INVADERS_GAME_LOOP */
