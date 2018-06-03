/*
 * main.c
 *
 *  Created on: 29 avr. 2018
 *      Author: student
 */

/* Se placer dans .../my_sdl/Debug pour lancer le make */
/* Modifier le fichier config.h en fonction de votre configuration */
/* Interface ne fonctionnant que sur des graphes courts comme graphe1.txt et graphe2.txt */

#include "config.h"
#include "graphes.h"
#include "dijkstra.h"
#include "finit.h"
#include "fevent.h"
#include "ftext.h"
#include "ffigure.h"
#include <time.h>
#include <string.h>

SDL_Surface* affichage;
SDL_Rect rect;
SDL_Color couleurNoire = {0, 0, 0};
SDL_Color couleurBlanche = {255, 255, 255};
Uint32 couleurs[NB_COULEURS];
SDL_Color colors_sdl[NB_COULEURS];

int main(int argc, char **argv)
{
	/* Initialisation des parametres */
	Input in; //structure d'evenements
	int n; //nombre sommets
	int i; //indice boucle
	int x1,y1,x2,y2; //coordonnees
	int k; // indice boucle

    int dimension_tab_hach;
	T_SOMMET* tab_sommets = NULL;
    Liste_hachage* tab_hach = NULL;

    dimension_tab_hach = dimension_tab_hachage();
    tab_hach = calloc(dimension_tab_hach, sizeof(*tab_hach));

    /* Creation et recuperation du tableau de sommets */
    tab_sommets = lecture_graphe(NOM_GRAPHE, &n, dimension_tab_hach, tab_hach);

    /* Initialisation des parametres lies a SDL */
	initSDL();
	init_ttf();
	initCouleurs();
	effacerEcran();
	actualiser();

	/* Creation de l'interface graphique */
	ligneHorizontale(0, Y0, SCREEN_WIDTH, couleurs[C_OCRE]);
	ligneVerticale(X0, 0, SCREEN_HEIGHT, couleurs[C_OCRE]);
	draw_text("A vous de jouer !", NOM_POLICE, POLICE, POLICE_X, 10, couleurNoire, couleurBlanche);
	draw_text("Click gauche -> depart !", NOM_POLICE, POLICE, POLICE_X, 10+DELTA_Y, couleurNoire, couleurBlanche);
	draw_text("Click droit -> arrivee !", NOM_POLICE, POLICE, POLICE_X, 10+2*DELTA_Y, couleurNoire, couleurBlanche);
	draw_text("Regardez le terminal !", NOM_POLICE, POLICE, POLICE_X, 10+3*DELTA_Y, couleurNoire, couleurBlanche);

	/* Affichage des sommets et des arcs */
	for (i=0; i<n; i++) {
		char str[10] = "";
		sprintf(str, "%d", i);

		x1 = tab_sommets[i].x*DILATATION+X0;
		y1 = -tab_sommets[i].y*DILATATION+Y0;
		disque(x1, y1, R, couleurs[i+1]);

		draw_text(str, NOM_POLICE, 20, x1-10, y1+5, couleurNoire, colors_sdl[i+1]);
		actualiser();

		L_ARC p = tab_sommets[i].voisins;
		while (!est_vide_arc(p)) {
			k = p->val.arrivee;
			x2 = tab_sommets[k].x*DILATATION+X0;
			y2 = -tab_sommets[k].y*DILATATION+Y0;
			ligne(x1, y1, x2, y2, couleurs[C_BLEU_FONCE]);
			actualiser();
			p = p->suiv;
		}
		free(p);
	}
	actualiser();

	/* Initialisation de la structure d'evenements */
	InitEvents(&in);
	in.tab_som = tab_sommets;
	in.n = n;

	/*  Boucle d'evenements */
	while(!in.quit)
	{
		UpdateEvents(&in);
	}

	/* Liberation */
	liberer_sommet(tab_sommets,n);
	liberer_tab_hachage(tab_hach, dimension_tab_hach);
	return 0;
}
