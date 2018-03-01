#ifndef SPACE_INVADERS_RENDER_H
#define SPACE_INVADERS_RENDER_H

#include <osbind.h>

#include "model.h"
#include "event.h"
#include "bitmap.h"
#include "raster.h"
#include "font.h"
#include "sprites.h"

void render(Model *model, void* base);

void render_spaceship(const Spaceship *spaceship, uint16 *base);

void render_armada(const Armada *armada, uint16 *base);

void render_alien(const Alien *alien, uint16 *base);

void render_shot(const Shot *shot, uint8 *base);

void render_scoreboard(const Scorebox *scorebox, uint8 *base);

#endif /*SPACE_INVADERS_RENDER_H*/
