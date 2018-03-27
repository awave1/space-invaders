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
void render(Model *model, void *base);

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
void render_scoreboard(const Scorebox *scorebox, uint8 *base);

/**
 * Render the splashscreen
 * 
 * @param base - Screen
 */
void render_splashscreen(uint32* base);

/**
 * Disable the cursor using terminal command
 */
void disable_cursor();

#endif /*SPACE_INVADERS_RENDER_H*/
