#ifndef SPACE_INVADERS_GAME
#define SPACE_INVADERS_GAME

#include <osbind.h>
#include <stdio.h>
#include "model.h"
#include "event.h"
#include "render.h"

/*
 * TODO: Documentation
 */
long get_time();

/*
 * TODO: Documentation
 */
void game_loop();

/*
 * TODO: Documentation
 */
void process_async_events(Model* model, void* base);

/*
 * TODO: Documentation
 */
void process_sync_events(Model* model, void* base);

/*
 * TODO: Documentation
 */
void setup_game(Model* model, void* base);

#endif /* SPACE_INVADERS_GAME */