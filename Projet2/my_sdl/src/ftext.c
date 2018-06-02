/*
 * ftext.c
 *
 *  Created on: 29 avr. 2018
 *      Author: student
 */

#include "ftext.h"
#include "finit.h"
#include "fevent.h"

SDL_Surface* affichage;
SDL_Rect rect;
SDL_Color couleurNoire2 = {0, 0, 0};
SDL_Color couleurBlanche2 = {255, 255, 255};
Uint32 couleurs[NB_COULEURS];

void draw_text(char* string, char* pfont, int size, int x, int y, SDL_Color foregroundColor, SDL_Color backgroundColor)
{
  char font_name[100];
  char* ext = ".ttf";
  strcpy(font_name, pfont);
  strcat(font_name,ext);
  TTF_Font* font = TTF_OpenFont(font_name, size);
  if(font == NULL)
  {
   printf("font NULL\n");
   exit(1);
  }
  SDL_Surface* textSurface = TTF_RenderText_Shaded(font, string, foregroundColor, backgroundColor);
  if ( textSurface == NULL)
    {
        printf("Couldn't create String %s \n", SDL_GetError());
        exit(7);
    }
  SDL_Rect textLocation = { x, y, 0, 0 };
  SDL_BlitSurface(textSurface, NULL, affichage, &textLocation);
  SDL_FreeSurface(textSurface);
  TTF_CloseFont(font);
}

void coordonnees(int x, int y)
{
	char title[50] = "\0";
	char* debut = "Coordonnees : x = ";
	char strx[5] = "\0";
	sprintf(strx,"%d",x);
	char* milieu = " / y = ";
	char stry[5] = "\0";
	sprintf(stry,"%d",y);
	strcat(title, debut);
	strcat(title, strx);
	strcat(title, milieu);
	strcat(title, stry);

	SDL_WM_SetCaption(title, NULL);
	actualiser();
}

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
	rect.x=BOX_X;
	rect.y=BOX_Y;
	rect.h=BOX_H;
	rect.w=BOX_W;
	SDL_FillRect(affichage, &rect, couleurs[C_ROUGE]);
	draw_text(strd, NOM_POLICE, POLICE, POLICE_X, POLICE_Y, couleurNoire2, couleurBlanche2);
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
	rect.x=BOX_X;
	rect.y=BOX_Y+DELTA_Y;
	rect.h=BOX_H;
	rect.w=BOX_W;
	SDL_FillRect(affichage, &rect, couleurs[C_BLEU]);
	draw_text(stra, NOM_POLICE, POLICE, POLICE_X, POLICE_Y+DELTA_Y, couleurNoire2, couleurBlanche2);
}

void affichageClickDepartError(void) {
	rect.x=BOX_X;
	rect.y=BOX_Y;
	rect.h=BOX_H;
	rect.w=BOX_W;
	SDL_FillRect(affichage, &rect, couleurs[C_ROUGE]);
	draw_text("Aucun sommet trouve !", NOM_POLICE, POLICE, POLICE_X, POLICE_Y, couleurNoire2, couleurBlanche2);
}

void affichageClickArriveeError(void) {
	rect.x=BOX_X;
	rect.y=BOX_Y+DELTA_Y;
	rect.h=BOX_H;
	rect.w=BOX_W;
	SDL_FillRect(affichage, &rect, couleurs[C_BLEU]);
	draw_text("Aucun sommet trouve !", NOM_POLICE, POLICE, POLICE_X, POLICE_Y+DELTA_Y, couleurNoire2, couleurBlanche2);
}

void affichageDijkstra(double temps) {
	char str[50] = "\0";
	sprintf(str,"Temps Dijkstra : %lf ", temps);
	rect.x=BOX_X;
	rect.y=BOX_Y+2*DELTA_Y;
	rect.h=BOX_H;
	rect.w=BOX_W;
	SDL_FillRect(affichage, &rect, couleurs[C_VERT]);
	draw_text(str, NOM_POLICE, POLICE, POLICE_X, POLICE_Y+2*DELTA_Y, couleurNoire2, couleurBlanche2);
}
