/*
 * main.c
 *
 *  Created on: 29 avr. 2018
 *      Author: student
 */

/* Se placer dans ../Debug pour lancer le make */

#include "config.h"
#include "graphe.h"
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

/* Pour test nombre de points */
//int rand_a_b(int a, int b){
//    return rand()%(b-a) +a;
//}

int main(int argc, char **argv)
{
	Input in;
	int n; //nombre sommets
	int i; //indice boucle
	int x1,y1,x2,y2; //coordonnees
	//int r, xr, yr; //test
	int k;
	//double temps_dijkstra;
//	attendreTouche();

    int dimension_tab_hach;
	T_SOMMET* tab_sommets = NULL; //tableau sommets
    Liste_hachage* tab_hach = NULL;

    dimension_tab_hach = dimension_tab_hachage();
    tab_hach = calloc(dimension_tab_hach, sizeof(*tab_hach));

    tab_sommets = lecture_graphe(NOM_GRAPHE, &n, dimension_tab_hach, tab_hach);

	initSDL();
	init_ttf();
	initCouleurs();
	effacerEcran();
	actualiser();
    //attendreTouche();
	//visualiser_graphe2(tab_sommets, &n);

	ligneHorizontale(0, Y0, SCREEN_WIDTH, couleurs[C_OCRE]);
	ligneVerticale(X0, 0, SCREEN_HEIGHT, couleurs[C_OCRE]);
	draw_text("A vous de jouer !", NOM_POLICE, POLICE, POLICE_X, 10, couleurNoire, couleurBlanche);
	draw_text("Click gauche -> depart !", NOM_POLICE, POLICE, POLICE_X, 10+DELTA_Y, couleurNoire, couleurBlanche);
	draw_text("Click droit -> arrivee !", NOM_POLICE, POLICE, POLICE_X, 10+2*DELTA_Y, couleurNoire, couleurBlanche);
	draw_text("Regardez le terminal !", NOM_POLICE, POLICE, POLICE_X, 10+3*DELTA_Y, couleurNoire, couleurBlanche);

	/* Test nombre de points */
	/*for (r=0; r<10000; r++) {
		xr = rand_a_b(-X0,X0)+X0;
		yr = -rand_a_b(-Y0,Y0)+Y0;
		setPixelVerif(xr, yr, couleurs[C_NOIR]);
	}*/

	//attendreTouche();
	for (i=0; i<n; i++) {
		char str[10] = "";
		sprintf(str, "%d", i);

		x1 = tab_sommets[i].x*DILATATION+X0;
		y1 = -tab_sommets[i].y*DILATATION+Y0;
		disque(x1, y1, R, couleurs[i+1]);

		draw_text(str, NOM_POLICE, 20, x1-10, y1+5, couleurNoire, colors_sdl[i+1]);
		actualiser();
		//SDL_Delay(100);

		L_ARC p = tab_sommets[i].voisins;
		while (!est_vide_arc(p)) {
			k = p->val.arrivee;
			x2 = tab_sommets[k].x*DILATATION+X0;
			y2 = -tab_sommets[k].y*DILATATION+Y0;
			ligne(x1, y1, x2, y2, couleurs[C_BLEU_FONCE]);
			actualiser();
			//SDL_Delay(100);
			p = p->suiv;
		}
		free(p);
	}
	actualiser();

	char test[5]="test";
	SDL_WM_SetCaption(test, NULL);
	actualiser();

	InitEvents(&in);
	in.tab_som = tab_sommets;
	in.n = n;
	while(!in.quit)
	{
		UpdateEvents(&in);
//		if(in.d && in.a) {
//			temps_dijkstra = dijkstra(in.indd, in.inda, tab_sommets, n);
//			affichageDijkstra(temps_dijkstra);
//			in.d = 0;
//			in.a = 0;
//		}
		//attendreTouche();
	}
	liberer_sommet(tab_sommets,n);
	liberer_tab_hachage(tab_hach, dimension_tab_hach);
	return 0;
}
