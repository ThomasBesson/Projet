/*
 * ftext.h
 *
 *  Created on: 29 avr. 2018
 *      Author: student
 */

#ifndef INC_FTEXT_H_
#define INC_FTEXT_H_

#include <stdio.h>

#include <SDL/SDL_ttf.h>

void draw_text(char* string, char* pfont, int size, int x, int y, SDL_Color foregroundColor, SDL_Color backgroundColor);

void coordonnees(int x, int y);

#endif /* INC_FTEXT_H_ */
