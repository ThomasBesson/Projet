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

/* Affichage du texte */
void draw_text(char* string, char* pfont, int size, int x, int y, SDL_Color foregroundColor, SDL_Color backgroundColor);

/* Affichage des coordonnees de la souris */
void coordonnees(int x, int y);

/* Affichages lies au click de la souris */
void affichageClickDepart(int xd, int yd, int i, char* nom);
void affichageClickArrivee(int xa, int ya, int i, char* nom);
void affichageClickDepartError(void);
void affichageClickArriveeError(void);

/* Affichage du temps d'execution de Dijkstra */
void affichageDijkstra(double temps);

#endif /* INC_FTEXT_H_ */
