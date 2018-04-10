/*
 *  File: video.h
 *  Authors: Artem Golovin, Daniel Artuso
 */
#ifndef SPACE_INVADERS_VIDEOBASE
#define SPACE_INVADERS_VIDEOBASE

#include "types.h"

/**
 * Equivalent to Physbase() call
 * get screen/video base
 * 
 * @return screen address
 */
uint16* get_video_base();

/**
 * Equivalent to Setscreen call
 * sets screen base to given address
 * 
 * @param base - desired screen base 
 */
void set_video_base(uint16* base);

#endif /* SPACE_INVADERS_VIDEOBASE */