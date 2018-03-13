#ifndef SPACE_INVADERS_GAME
#define SPACE_INVADERS_GAME

#include <osbind.h>
#include <stdio.h>
#include "model.h"
#include "event.h"
#include "render.h"
#include "clear_qk.h"
#include "clear_ga.h"


/*
 * TODO: Documentation
 */
void game_loop();

/*
 * TODO: Documentation
 */
void process_async_events(Model *model, void *base);

/*
 * TODO: Documentation
 */
void process_sync_events(Model *model, void *base);

/*
 * TODO: Documentation
 */
void setup_game(Model *model, void *base);

/*
 * TODO: Documentation
 */
long get_time();

/*
 * TODO: Documentation
 */
uint8 *get_base(uint8 *second_buffer);

#endif /* SPACE_INVADERS_GAME */
