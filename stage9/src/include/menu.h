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
#include "game.h"
#include "raster.h"
#include "sprites.h"

#define MENU_CHOICE_START_1_PLAYER 1
#define MENU_CHOICE_START_2_PLAYERS 2
#define MENU_CHOICE_EXIT 3

void menu();

void process_keyboard_choice();

void select_option(int choice);

void draw_choice_selector(int choice, uint16* base);

void clear_choice_selector(int choice, uint16* base);

int mouse_location();

#endif /*SPACE_INVADERS_MENU_H*/
