/*
 * ftext.h
 *
 *  Created on: 29 avr. 2018
 *      Author: student
 */

#ifndef INC_FTEXT_H_
#define INC_FTEXT_H_

#include "struct.h"
#include "config.h"

void draw_text(char* string, char* pfont, int size, int x, int y, SDL_Color foregroundColor, SDL_Color backgroundColor);
void coordonnees(int x, int y);
void affichageClickDepart(int xd, int yd, int i, char* nom);
void affichageClickArrivee(int xa, int ya, int i, char* nom);
void affichageClickDepartError(void);
void affichageClickArriveeError(void);
void affichageDijkstra(double temps);

#endif /* INC_FTEXT_H_ */
