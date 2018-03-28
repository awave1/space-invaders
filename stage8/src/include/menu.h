/*
 *  File: menu.h
 *  Authors: Artem Golovin, Daniel Artuso
 */

#ifndef SPACE_INVADERS_MENU_H
#define SPACE_INVADERS_MENU_H

#include <osbind.h>
#include <stdio.h>
#include "types.h"
#include "const.h"
#include "event.h"
#include "splash.h"
#include "space.h"
#include "raster.h"
#include "sprites.h"

void menu();

void process_keyboard_choice();

void select_option(int choice);

void draw_choice_selector(int choice);

#endif /*SPACE_INVADERS_MENU_H*/
