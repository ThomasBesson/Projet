/*
 * fevent.c
 *
 *  Created on: 29 avr. 2018
 *      Author: student
 */

#include "fevent.h"
#include "ftext.h"
#include "finit.h"

#include "graphe.h"

SDL_Surface* affichage;
SDL_Rect rect;
SDL_Color couleurNoire2 = {0, 0, 0};
SDL_Color couleurBlanche2 = {255, 255, 255};
Uint32 couleurs[NB_COULEURS];

/* Avec Eclipse */
//#define NOM_POLICE "Vera"

/* Sans Eclipse */
#define NOM_POLICE "/home/student/Projet2/my_sdl/Vera"

////void affichageClickDepart(int* xd, int* yd) {
//	char strd[50] = "\0";
//	char* debutd = "Coordonnees depart : xd =";
//	char strxd[5] = "\0";
//	sprintf(strxd,"%d",*xd);
//	char* milieud = "/ yd = ";
//	char stryd[5] = "\0";
//	sprintf(stryd,"%d",*yd);
//	strcat(strd, debutd);
//	strcat(strd, strxd);
//	strcat(strd, milieud);
//	strcat(strd, stryd);
//	rect.x=5;
//	rect.y=395;
//	rect.h=50;
//	rect.w=650;
//	SDL_FillRect(affichage, &rect, couleurs[C_ROUGE]);
//	draw_text(strd, NOM_POLICE, 30, 10, 400, couleurNoire2, couleurBlanche2);
//}

void affichageClickDepart(int xd, int yd, int i, char* nom) {
	char strd[50] = "\0";
	char strind[5] = "\0";
	sprintf(strind,"Depart : %d / ",i);
	char strxd[5] = "\0";
	sprintf(strxd," / (%d,",xd);
	char stryd[5] = "\0";
	sprintf(stryd,"%d)",yd);
	strcat(strd, strind);
	strcat(strd, nom);
	strcat(strd, strxd);
	strcat(strd, stryd);
	rect.x=5;
	rect.y=445;
	rect.h=45;
	rect.w=560;
	SDL_FillRect(affichage, &rect, couleurs[C_ROUGE]);
	draw_text(strd, NOM_POLICE, 30, 10, 450, couleurNoire2, couleurBlanche2);
}

void affichageClickArrivee(int xa, int ya, int i, char* nom) {
	char stra[50] = "\0";
	char strind[5] = "\0";
	sprintf(strind,"Arrivee : %d / ",i);
	char strxa[5] = "\0";
	sprintf(strxa," / (%d,",xa);
	char strya[5] = "\0";
	sprintf(strya,"%d)",ya);
	strcat(stra, strind);
	strcat(stra, nom);
	strcat(stra, strxa);
	strcat(stra, strya);
	rect.x=5;
	rect.y=495;
	rect.h=45;
	rect.w=560;
	SDL_FillRect(affichage, &rect, couleurs[C_BLEU]);
	draw_text(stra, NOM_POLICE, 30, 10, 500, couleurNoire2, couleurBlanche2);
}

void affichageClickDepartError(void) {
	rect.x=5;
	rect.y=445;
	rect.h=45;
	rect.w=560;
	SDL_FillRect(affichage, &rect, couleurs[C_ROUGE]);
	draw_text("Aucun sommet trouve !", NOM_POLICE, 30, 10, 450, couleurNoire2, couleurBlanche2);
}

void affichageClickArriveeError(void) {
	rect.x=5;
	rect.y=495;
	rect.h=45;
	rect.w=560;
	SDL_FillRect(affichage, &rect, couleurs[C_BLEU]);
	draw_text("Aucun sommet trouve !", NOM_POLICE, 30, 10, 500, couleurNoire2, couleurBlanche2);
}

void affichageDijkstra(double temps) {
	char str[50] = "\0";
	sprintf(str,"Temps Dijkstra : %lf ", temps);
	rect.x=5;
	rect.y=545;
	rect.h=45;
	rect.w=560;
	SDL_FillRect(affichage, &rect, couleurs[C_VERT]);
	draw_text(str, NOM_POLICE, 30, 10, 550, couleurNoire2, couleurBlanche2);
}

//void correspondance(int x, int y, int dilatation, double r, T_SOMMET* tab_sommets, int n) {
//	double xf, yf, xtab, ytab;
//	int i;
//	xf = (double)x/dilatation;
//	yf = (double)y/dilatation;
//	printf("xf : %lf, yf : %lf\n", xf, yf);
//	for (i=0; i<n; i++) {
//		xtab = tab_sommets[i].x;
//		ytab = tab_sommets[i].y;
//		//printf("xtab : %lf, ytab : %lf\n", xtab, ytab);
//		printf("xtab+r : %lf, xtab-r : %lf, ytab+r : %lf, ytab-r : %lf\n", xtab+r, xtab-r, ytab+r, ytab-r);
//		if (xf<=xtab+r && xf>=xtab-r && yf<=ytab+r && yf>=ytab-r) {
//			//char nom[15] = tab_sommets[i].nom;
////			char str[5] = "\0";
////			sprintf(str,"%d",i);
////			draw_text(str, NOM_POLICE, 50, 100, 100, couleurNoire2, couleurBlanche2);
//			//draw_text(tab_sommets[i].nom, NOM_POLICE, 50, 100, 100, couleurNoire2, couleurBlanche2);
//			break;
//		} else {
//			draw_text("Inconnu", NOM_POLICE, 50, 100, 100, couleurNoire2, couleurBlanche2);
//		}
//	}
//}

void correspondanceDepart(int x, int y, int dilatation, double r, Input* in) {
	double xf, yf, xtab, ytab;
	int i;
	xf = (double)x/dilatation;
	yf = (double)y/dilatation;
	//printf("xf : %lf, yf : %lf\n", xf, yf);
	for (i=0; i<in->n; i++) {
		xtab = in->tab_som[i].x;
		ytab = in->tab_som[i].y;
		//printf("xtab : %lf, ytab : %lf\n", xtab, ytab);
		//printf("xtab+r : %lf, xtab-r : %lf, ytab+r : %lf, ytab-r : %lf\n", xtab+r, xtab-r, ytab+r, ytab-r);
		if (xf<=xtab+r && xf>=xtab-r && yf<=ytab+r && yf>=ytab-r) {
			char* nom = in->tab_som[i].nom;
			affichageClickDepart(x, y, i, nom);
			in->indd = i;
			in->d = 1;
			break;
		} else {
			affichageClickDepartError();
		}
	}
}

void correspondanceArrivee(int x, int y, int dilatation, double r, Input* in) {
	double xf, yf, xtab, ytab;
	int i;
	xf = (double)x/dilatation;
	yf = (double)y/dilatation;
	//printf("xf : %lf, yf : %lf\n", xf, yf);
	for (i=0; i<in->n; i++) {
		xtab = in->tab_som[i].x;
		ytab = in->tab_som[i].y;
		//printf("xtab : %lf, ytab : %lf\n", xtab, ytab);
		//printf("xtab+r : %lf, xtab-r : %lf, ytab+r : %lf, ytab-r : %lf\n", xtab+r, xtab-r, ytab+r, ytab-r);
		if (xf<=xtab+r && xf>=xtab-r && yf<=ytab+r && yf>=ytab-r) {
			char* nom = in->tab_som[i].nom;
			affichageClickArrivee(x, y, i, nom);
			in->inda = i;
			in->a = 1;
			break;
		} else {
			affichageClickArriveeError();
		}
	}
}

void UpdateEvents(Input* in, int* xd, int* yd, int* xa, int* ya)
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
			/*in->key[event.key.keysym.sym]=1;
			break;*/
		/*case SDL_KEYUP:
			in->key[event.key.keysym.sym]=0;
			break;*/
		case SDL_MOUSEMOTION:
			in->mousex=event.motion.x-400;
			in->mousey=-event.motion.y+300;
			in->mousexrel=event.motion.xrel;
			in->mouseyrel=event.motion.yrel;
			coordonnees(in->mousex,in->mousey);
			//actualiser();
			SDL_Delay(5);
			break;
		case SDL_MOUSEBUTTONDOWN:
			in->mousebuttons[event.button.button]=1;
			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button) {
				case SDL_BUTTON_LEFT:
					*xd = event.motion.x-400;
					*yd = -event.motion.y+300;
					correspondanceDepart(*xd, *yd, 300, 0.03, in);
					//affichageClickDepart(xd, yd);
					actualiser();
					break;
				case SDL_BUTTON_RIGHT:
					*xa = event.motion.x-400;
					*ya = -event.motion.y+300;
					correspondanceArrivee(*xa, *ya, 300, 0.03, in);
					//affichageClickArrivee(xa, ya);
					actualiser();
					break;
				default:
					break;
			}
			break;
			/*if (event.button.button == SDL_BUTTON_LEFT)
			if (event.button.button!=SDL_BUTTON_WHEELUP && event.button.button!=SDL_BUTTON_WHEELDOWN)
				in->mousebuttons[event.button.button]=0;
			break;*/
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
