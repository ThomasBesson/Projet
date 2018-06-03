/*
 * finit.c
 *
 *  Created on: 29 avr. 2018
 *      Author: student
 */

#include "finit.h"

SDL_Surface* affichage;
Uint32 couleurs[NB_COULEURS];
SDL_Color colors_sdl[NB_COULEURS];

void init_ttf(void)
{
  if (TTF_Init() == -1) {
    fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
    exit(EXIT_FAILURE);
  }

  atexit(TTF_Quit);
}

void initSDL(void)
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    fprintf(stderr, "Erreur a l'initialisation de la SDL : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  atexit(SDL_Quit);
  affichage = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE);

  if (affichage == NULL) {
    fprintf(stderr, "Impossible d'activer le mode graphique : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  SDL_WM_SetCaption("Graphique SDL", NULL);
  SDL_FillRect(affichage, NULL, couleurs[C_BLANC]);
}

void initCouleurs(void)
{
  couleurs[C_NOIR]          = SDL_MapRGB(affichage->format, 0x00, 0x00, 0x00);
  couleurs[C_BLEU_FONCE]    = SDL_MapRGB(affichage->format, 0x00, 0x00, 0x80);
  couleurs[C_VERT_FONCE]    = SDL_MapRGB(affichage->format, 0x00, 0x80, 0x00);
  couleurs[C_CYAN_FONCE]    = SDL_MapRGB(affichage->format, 0x00, 0x80, 0x80);
  couleurs[C_ROUGE_FONCE]   = SDL_MapRGB(affichage->format, 0x80, 0x00, 0x00);
  couleurs[C_MAGENTA_FONCE] = SDL_MapRGB(affichage->format, 0x80, 0x00, 0x80);
  couleurs[C_OCRE]          = SDL_MapRGB(affichage->format, 0x80, 0x80, 0x00);
  couleurs[C_GRIS_CLAIR]    = SDL_MapRGB(affichage->format, 0xC0, 0xC0, 0xC0);
  couleurs[C_GRIS]          = SDL_MapRGB(affichage->format, 0x80, 0x80, 0x80);
  couleurs[C_BLEU]          = SDL_MapRGB(affichage->format, 0x00, 0x00, 0xFF);
  couleurs[C_VERT]          = SDL_MapRGB(affichage->format, 0x00, 0xFF, 0x00);
  couleurs[C_CYAN]          = SDL_MapRGB(affichage->format, 0x00, 0xFF, 0xFF);
  couleurs[C_ROUGE]         = SDL_MapRGB(affichage->format, 0xFF, 0x00, 0x00);
  couleurs[C_MAGENTA]       = SDL_MapRGB(affichage->format, 0xFF, 0x00, 0xFF);
  couleurs[C_JAUNE]         = SDL_MapRGB(affichage->format, 0xFF, 0xFF, 0x00);
  couleurs[C_BLANC]         = SDL_MapRGB(affichage->format, 0xFF, 0xFF, 0xFF);

  colors_sdl[C_NOIR].r          = 0x00; colors_sdl[C_NOIR].g          = 0x00; colors_sdl[C_NOIR].b          = 0x00;
  colors_sdl[C_BLEU_FONCE].r    = 0x00; colors_sdl[C_BLEU_FONCE].g    = 0x00; colors_sdl[C_BLEU_FONCE].b    = 0x80;
  colors_sdl[C_VERT_FONCE].r    = 0x00; colors_sdl[C_VERT_FONCE].g    = 0x80; colors_sdl[C_VERT_FONCE].b      = 0x00;
  colors_sdl[C_CYAN_FONCE].r    = 0x00; colors_sdl[C_CYAN_FONCE].g    = 0x80; colors_sdl[C_CYAN_FONCE].b    = 0x80;
  colors_sdl[C_ROUGE_FONCE].r   = 0x80; colors_sdl[C_ROUGE_FONCE].g   = 0x00; colors_sdl[C_ROUGE_FONCE].b   = 0x00;
  colors_sdl[C_MAGENTA_FONCE].r = 0x80; colors_sdl[C_MAGENTA_FONCE].g = 0x00; colors_sdl[C_MAGENTA_FONCE].b = 0x80;
  colors_sdl[C_OCRE].r          = 0x80; colors_sdl[C_OCRE].g          = 0x80; colors_sdl[C_OCRE].b          = 0x00;
  colors_sdl[C_GRIS_CLAIR].r    = 0xC0; colors_sdl[C_GRIS_CLAIR].g    = 0xC0; colors_sdl[C_GRIS_CLAIR].b    = 0xC0;
  colors_sdl[C_GRIS].r          = 0x80; colors_sdl[C_GRIS].g          = 0x80; colors_sdl[C_GRIS].b          = 0x80;
  colors_sdl[C_BLEU].r          = 0x00; colors_sdl[C_BLEU].g          = 0x00; colors_sdl[C_BLEU].b          = 0xFF;
  colors_sdl[C_VERT].r          = 0x00; colors_sdl[C_VERT].g          = 0xFF; colors_sdl[C_VERT].b          = 0x00;
  colors_sdl[C_CYAN].r          = 0x00; colors_sdl[C_CYAN].g          = 0xFF; colors_sdl[C_CYAN].b          = 0xFF;
  colors_sdl[C_ROUGE].r         = 0xFF; colors_sdl[C_ROUGE].g         = 0x00; colors_sdl[C_ROUGE].b         = 0x00;
  colors_sdl[C_MAGENTA].r       = 0xFF; colors_sdl[C_MAGENTA].g       = 0x00; colors_sdl[C_MAGENTA].b       = 0xFF;
  colors_sdl[C_JAUNE].r         = 0xFF; colors_sdl[C_JAUNE].g         = 0xFF; colors_sdl[C_JAUNE].b         = 0x00;
  colors_sdl[C_BLANC].r         = 0xFF; colors_sdl[C_BLANC].g         = 0xFF; colors_sdl[C_BLANC].b         = 0xFF;

}
