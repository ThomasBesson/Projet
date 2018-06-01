/*
 * ffigure.h
 *
 *  Created on: 29 avr. 2018
 *      Author: student
 */

#ifndef INC_FFIGURE_H_
#define INC_FFIGURE_H_

#include <stdio.h>

#include <SDL/SDL_image.h>

void setPixel(int x, int y, Uint32 coul);

void setPixelVerif(int x, int y, Uint32 coul);

void barre(int x, int y, int w, int h, Uint32 coul);

void ligneHorizontale(int x, int y, int w, Uint32 coul);

void ligneVerticale(int x, int y, int h, Uint32 coul);

void rectangle(int x, int y, int w, int h, Uint32 coul);

void effacerEcran(void);

void echangerEntiers(int* x, int* y);

void ligne(int x1, int y1, int x2, int y2, Uint32 coul);

void cercle(int cx, int cy, int rayon, int coul);

void disque(int cx, int cy, int rayon, int coul);

#endif /* INC_FFIGURE_H_ */
