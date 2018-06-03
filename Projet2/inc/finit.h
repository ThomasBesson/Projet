/*
 * finit.h
 *
 *  Created on: 29 avr. 2018
 *      Author: student
 */

#ifndef INC_FINIT_H_
#define INC_FINIT_H_

#include <stdio.h>
#include <stdlib.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

/* Enumeration des couleurs */
enum {
  C_NOIR, C_BLEU_FONCE, C_VERT_FONCE, C_CYAN_FONCE, C_ROUGE_FONCE,
  C_MAGENTA_FONCE, C_OCRE, C_GRIS_CLAIR, C_GRIS, C_BLEU, C_VERT,
  C_CYAN, C_ROUGE, C_MAGENTA, C_JAUNE, C_BLANC,

  NB_COULEURS
};

/* Initialisation du texte */
void init_ttf(void);

/* Initialisation de la fenetre graphique */
void initSDL(void);

/* Initialisation des couleurs */
void initCouleurs(void);

#endif /* INC_FINIT_H_ */
