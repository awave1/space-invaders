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

/**
 * Keeps track of menu state.
 */
extern int MENU_STATE;

/**
 * true, if mouse click happened within boundsries of menu choice
 */
extern bool VALID_CLICK;

/**
 * Main menu loop
 */
void menu();

/**
 * Updates selection from keyboard input
 */
void process_menu_choice();

/**
 * Select option selected upon enter key/mouse click
 * 
 * @param: choice, can be one of the following:
 *      - MENU_CHOICE_START_1_PLAYER  - 1
 *      - MENU_CHOICE_START_2_PLAYERS - 2
 *      - MENU_CHOICE_EXIT            - 3
 */
void select_option(int choice);

/**
 * Draw menu selector based on choice
 * 
 * @param choice - menu choice
 * @param base   - screen base
 */
void draw_choice_selector(int choice, uint16* base);

/**
 * Clears menu selector from previous choice
 * 
 * @param choice - menu choice
 * @param base   - screen base
 */
void clear_choice_selector(int choice, uint16* base);

/**
 * Gets mouse location
 * 
 * @return menu choice, if mouse pointer within any of menu buttons
 */
int mouse_location();

#endif /*SPACE_INVADERS_MENU_H*/
