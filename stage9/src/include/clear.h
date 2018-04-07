/*
 *  File: clear_qk.h 
 *  Authors: Artem Golovin, Daniel Artuso 
 */

#ifndef SPACE_INVADERS_CLEAR_H
#define SPACE_INVADERS_CLEAR_H

/**
 * Clear only active section of the screen (everything but the scorebox)
 * 
 * @param base - Screen to clear
 */
void clear_qk(void *base);

/**
 * Clear the entire screen. 
 * 
 * @param base - Screen to clear
 */
void clear_game(void *base);

#endif /* CLEAR_QK_H */