#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphes.h"
#include "liste_hachage.h"

int main() {
  	int x;
	int depart,arrivee;
  	T_SOMMET* tab_sommets = NULL;
	Liste_hachage*tab_hach=calloc(3,sizeof(*tab_hach));
  	char nom_graphe[]="graphe1.txt";
  	tab_sommets=lecture_graphe(nom_graphe,&x,3,tab_hach);
	puts("visualisation du graphe");
	visualiser_graphe(tab_sommets, &x);
	
	liberer_sommet(tab_sommets, x);
	liberer_tab_hachage(tab_hach, 3);
}
