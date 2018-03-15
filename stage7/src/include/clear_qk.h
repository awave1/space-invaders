/*
 *  File: clear_qk.h 
 *  Authors: Artem Golovin, Daniel Artuso 
 */

#ifndef CLEAR_QK_H
#define CLEAR_QK_H

/**
 * Clear only active section of the screen (everything but the scorebox)
 * 
 * @param base - Screen to clear
 */
void clear_qk(void *base);

#endif /* CLEAR_QK_H */