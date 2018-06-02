/*
 * fevent.c
 *
 *  Created on: 29 avr. 2018
 *      Author: student
 */

#include "fevent.h"
#include "ftext.h"
#include "finit.h"

SDL_Surface* affichage;

void testDijkstra(Input* in) {
	if(in->d && in->a) {
		in->dijkstra = dijkstra(in->indd, in->inda, in->tab_som, in->n);
		affichageDijkstra(in->dijkstra);
		in->d = 0;
		in->a = 0;
	}
}

void correspondanceDepart(int dilatation, double r, Input* in) {
	double xf, yf, xtab, ytab;
	int i;
	xf = (double)in->xd/dilatation;
	yf = (double)in->yd/dilatation;
	for (i=0; i<in->n; i++) {
		xtab = in->tab_som[i].x;
		ytab = in->tab_som[i].y;
		if (xf<=xtab+r && xf>=xtab-r && yf<=ytab+r && yf>=ytab-r) {
			char* nom = in->tab_som[i].nom;
			affichageClickDepart(in->xd, in->yd, i, nom);
			in->indd = i;
			in->d = 1;
			testDijkstra(in);
			break;
		} else {
			affichageClickDepartError();
		}
	}
}

void correspondanceArrivee(int dilatation, double r, Input* in) {
	double xf, yf, xtab, ytab;
	int i;
	xf = (double)in->xa/dilatation;
	yf = (double)in->ya/dilatation;
	for (i=0; i<in->n; i++) {
		xtab = in->tab_som[i].x;
		ytab = in->tab_som[i].y;
		if (xf<=xtab+r && xf>=xtab-r && yf<=ytab+r && yf>=ytab-r) {
			char* nom = in->tab_som[i].nom;
			affichageClickArrivee(in->xa, in->ya, i, nom);
			in->inda = i;
			in->a = 1;
			testDijkstra(in);
			break;
		} else {
			affichageClickArriveeError();
		}
	}
}

void UpdateEvents(Input* in)
{
	SDL_Event event;
	in->mousebuttons[SDL_BUTTON_WHEELUP] = 0;
	in->mousebuttons[SDL_BUTTON_WHEELDOWN] = 0;
	initCouleurs();
	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			in->quit = 1;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
				case SDLK_ESCAPE:
				case SDLK_q:
					in->quit = 1;
					break;
				default:
					break;
			}
			break;
		case SDL_MOUSEMOTION:
			in->mousex=event.motion.x-X0;
			in->mousey=-event.motion.y+Y0;
			in->mousexrel=event.motion.xrel;
			in->mouseyrel=event.motion.yrel;
			coordonnees(in->mousex,in->mousey);
			SDL_Delay(5);
			break;
		case SDL_MOUSEBUTTONDOWN:
			in->mousebuttons[event.button.button]=1;
			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button) {
				case SDL_BUTTON_LEFT:
					in->xd = event.motion.x-X0;
					in->yd = -event.motion.y+Y0;
					correspondanceDepart(DILATATION, DELTA, in);
					actualiser();
					break;
				case SDL_BUTTON_RIGHT:
					in->xa = event.motion.x-X0;
					in->ya = -event.motion.y+Y0;
					correspondanceArrivee(DILATATION, DELTA, in);
					actualiser();
					break;
				default:
					break;
			}
			break;
		default:
			break;
		}
	}
}

void InitEvents(Input* in)
{
	memset(in,0,sizeof(Input));
}

void attendreTouche(void)
{
  SDL_Event event;

  do
    SDL_WaitEvent(&event);
  while (event.type != SDL_QUIT && event.type != SDL_KEYDOWN);
}

void actualiser(void)
{
  SDL_UpdateRect(affichage, 0, 0, 0, 0);
}
