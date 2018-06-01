#ifndef _STRUCT
#define _STRUCT

#include <SDL/SDL.h>

/* Structure d'arc contenant le sommet d'arrivee et le cout pour y parvenir */
typedef struct {
    int arrivee;
    double cout; } T_ARC;

/* Structure de liste d'arcs contenant l'arc actuel et le lien pour parvenir au suivant */
typedef struct lsucc {
    T_ARC val;
    struct lsucc* suiv; } * L_ARC;

/* Structure de tableau de sommets contenant les informations relatives à chaque sommmet
   (nom, ligne, coordonnees...) ainsi que la liste d'arcs voisins */
typedef struct {
    char* nom;
    char ligne[128];
    double x,y;
    int tas;
  L_ARC voisins; } T_SOMMET;

/* Structure d'événement pour l'interface graphique */
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
	double xd;
	double yd;
	double xa;
	double ya;
	double dijkstra;
	char quit;
} Input;

#endif
