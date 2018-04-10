/*
 *  File: render.h 
 *  Authors: Artem Golovin, Daniel Artuso 
 */

#ifndef SPACE_INVADERS_RENDER_H
#define SPACE_INVADERS_RENDER_H

#include <osbind.h>

#include "menu.h"
#include "model.h"
#include "event.h"
#include "raster.h"
#include "font.h"
#include "sprites.h"

/**
 * Render the entire game model and its elements
 * 
 * @param model - Game model
 * @param base  - Screen
 */
void render(Model* model, void* base, int player_count);

/**
 * Render spaceship
 * 
 * @param spaceship - Spaceship
 * @param base      - Screen
 */
void render_spaceship(const Spaceship *spaceship, uint16 *base);

/**
 * Render the armada
 * 
 * @param armada - Armada
 * @param base   - Screen
 */
void render_armada(const Armada *armada, uint16 *base);

/**
 * Render single alien
 * 
 * @param alien - Alien
 * @param base  - Screen
 */
void render_alien(const Alien *alien, uint16 *base);

/**
 * Render shots based on the type
 * 
 * @param shots     - Shots to render
 * @param shot_type - Shot type
 * @param base      - Screen
 */
void render_shots(const Shot shots[], shot_t shot_type, uint16 *base);

/**
 * Render the scorebox
 * 
 * @param scorebox - Scorebox
 * @param base     - Screen
 */
void render_scoreboard(const Model* model, uint8* base, int player_count);

/**
 * Render the splashscreen
 * 
 * @param base - Screen
 */
void render_splashscreen(uint32* base);

/**
 * Render game over screen 
 * 
 * @param base - screen
 */
void render_game_over(uint32* base);

/**
 * Render next player notification
 * 
 * @param base - screen
 */
void render_next_player(uint32* base);

/**
 * Plots simple mouse pointer as rectangle
 * 
 * @param base - screen
 * @param x    - x position
 * @param y    - y position
 */
void render_mouse_ptr(uint16* base, int x, int y);

/**
 * @brief 
 * 
 * @param base 
 * @param x 
 * @param y 
 */
void save_mouse_bg(uint16 *base, int x, int y);

/**
 * @brief 
 * 
 * @param base 
 * @param x 
 * @param y 
 */
void restore_mouse_bg(uint16 *base, int x, int y);

/**
 * Disable the cursor using terminal command
 */
void disable_cursor();

#endif /*SPACE_INVADERS_RENDER_H*/
