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

	/*char test2[5]="test2";
	SDL_WM_SetCaption(test2, NULL);
		actualiser();*/
}
