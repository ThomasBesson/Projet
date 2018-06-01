/*
 * fevent.h
 *
 *  Created on: 29 avr. 2018
 *      Author: student
 */

#ifndef INC_FEVENT_H_
#define INC_FEVENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

#include <SDL/SDL.h>

typedef struct
{
	char key[SDLK_LAST];
	int mousex,mousey;
	int mousexrel,mouseyrel;
	char mousebuttons[8];
	T_SOMMET* tab_som;
	int n;
	int indd;
	int inda;
	int d;
	int a;
	char quit;
} Input;

void UpdateEvents(Input* in, int* xd, int* yd, int* xa, int* ya);
void InitEvents(Input* in);
void attendreTouche(void);
void actualiser(void);
void affichageClickDepart(int xd, int yd, int i, char* nom);
void affichageClickArrivee(int xa, int ya, int i, char* nom);
void affichageClickDepartError(void);
void affichageClickArriveeError(void);
void affichageDijkstra(double temps);
void correspondanceDepart(int x, int y, int dilatation, double r, Input* in);
void correspondanceArrivee(int x, int y, int dilatation, double r, Input* in);

#endif /* INC_FEVENT_H_ */
