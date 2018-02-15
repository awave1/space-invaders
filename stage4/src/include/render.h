#include "model.h"
#include "types.h"
#include "const.h"
#include "event.h"

#ifndef SPACE_INVADERS_RENDER_H
#define SPACE_INVADERS_RENDER_H

void render(const Model *model, UINT16 *base);

void render_spaceship(const Spaceship *spaceship, UINT16 *base);

void render_armada(const Armada *armada, UINT16 *base);

void render_alien(const Alien *alien, UNIT16 *base);

void render_shot(const Shot *shot,
                 UINT16 *base);/*change base size if sprite different*/
void render_scoreboard(const Scorebox *scorebox, UINT16 *base);

#endif //SPACE_INVADERS_RENDER_H
