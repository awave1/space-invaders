/*
 *  File: menu.h
 *  Authors: Artem Golovin, Daniel Artuso
 */

#ifndef SPACE_INVADERS_MENU_H
#define SPACE_INVADERS_MENU_H

#include <osbind.h>
#include <stdio.h>
#include "event.h"

void menu();

void process_keyboard_choice();

void select_option(int choice);

#endif /*SPACE_INVADERS_MENU_H*/
