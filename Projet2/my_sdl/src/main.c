/*
 * main.c
 *
 *  Created on: 29 avr. 2018
 *      Author: student
 */
#include <time.h>
#include <string.h>

#include "graphe.h"
#include "dijkstra.h"

#include "finit.h"
#include "fevent.h"
#include "ftext.h"
#include "ffigure.h"

SDL_Surface* affichage;
Uint32 couleurs[NB_COULEURS];
SDL_Color colors_sdl[NB_COULEURS];
SDL_Color couleurNoire = {0, 0, 0};
SDL_Color couleurBlanche = {255, 255, 255};

#define INF 10000
#define R 2
#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 600
#define NOM_GRAPHE "graphe1.txt"
//#define NOM_GRAPHE "graphe2.txt"
#define DILATATION 300
#define X0 400
#define Y0 300

int rand_a_b(int a, int b){

    return rand()%(b-a) +a;

}

int main(int argc, char **argv)
{
	Input in;
	int r;
	int n; //nombre sommets
	int i; //indice boucle
	int x1,y1,x2,y2,xd,yd,xa,ya; //coordonnees
	int xr, yr;
	int k;
	double temps_dijkstra;
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

	//SDL_Delay(100);
	ligneHorizontale(0, Y0, 800, couleurs[C_OCRE]);
	ligneVerticale(X0, 0, 800, couleurs[C_OCRE]);
	draw_text("Hello !", "Vera", 50, 0, 0, couleurNoire, couleurBlanche);
	//SDL_Delay(100);

	/*for (r=0; r<1X0000; r++) {
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

		draw_text(str, "Vera", 10, x1-20, y1-13, couleurNoire, colors_sdl[i+1]);
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
	/*attendreTouche();*/

	/*char title[40];
	int x = 0;
	int y = 0;
	char* debut = "Coordonnees : x = ";
	char strx[5];
	sprintf(strx,"%d",x);
	char* milieu = " / y = ";
	char stry[5];
	sprintf(stry,"%d",x);
	//strcpy(title, debut);
	strcat(title, debut);
	strcat(title, strx);
	strcat(title, milieu);
	strcat(title, stry);

	SDL_WM_SetCaption(title, NULL);
	actualiser();*/

	char test[5]="test";
	SDL_WM_SetCaption(test, NULL);
	actualiser();
	//SDL_Delay(100);

	InitEvents(&in);
	in.tab_som = tab_sommets;
	in.n = n;
	while(!in.quit)
	{
		UpdateEvents(&in,&xd, &yd, &xa, &ya);
		if(in.d && in.a) {
			temps_dijkstra = dijkstra(in.indd, in.inda, tab_sommets, n);
			affichageDijkstra(temps_dijkstra);
			in.d = 0;
			in.a = 0;
		}
		/*while(!in.key[SDLK_ESCAPE])
		{
			UpdateEvents(&in);
			coordonnees(in.mousex,in.mousey);

			actualiser();
			//SDL_Flip(screen);
			SDL_Delay(5);
		}*/
		//attendreTouche();
	}
	liberer_sommet(tab_sommets,n);
	liberer_tab_hachage(tab_hach, dimension_tab_hach);
	return 0;
}
