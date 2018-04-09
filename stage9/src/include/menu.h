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

#define INVALID_MOUSE_CHOICE -1

extern int MENU_STATE;
extern bool VALID_CLICK;

/**
 * Main menu loop
 */
void menu();

/**
 * Updates selection from keyboard input
 */
void process_keyboard_choice();

/**
 * Select option selected upon enter key/mouse click
 * @param: choice - menu choice 1, 2 or 3
 */
void select_option(int choice);

/**
 * Draw menu selector based on choice
 * @param choice - menu choice,
 *        base   - screen base
 */
void draw_choice_selector(int choice, uint16* base);

/**
 * Clears menu selector from previous choice
 * @param choice - menu choice,
 *        base   - screen base
 */
void clear_choice_selector(int choice, uint16* base);

/**
 * Gets mouse location
 * @return mouse location
 */
int mouse_location();

#endif /*SPACE_INVADERS_MENU_H*/
