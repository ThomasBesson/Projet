#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphes.h"
#include "liste_hachage.h"

int main() {
	int x;
	int n;
	int depart,arrivee;
	int dimension;
	T_SOMMET* tab_sommets = NULL;
	Liste_hachage*tab_hach=NULL;
	char nom_graphe[]="graphe1.txt";
	char*e;
	dimension=dimension_tab_hachage();
	tab_hach=calloc(dimension,sizeof(*tab_hach));
	tab_sommets=lecture_graphe(nom_graphe,&x,dimension,tab_hach);
	
	depart=demande_station_depart(tab_hach,dimension,tab_sommets,x);
	arrivee=demande_station_arrivee(tab_hach,dimension,tab_sommets,x);
	
	printf("numero de depart = %d \n", depart);
	printf("numero d'arrivée = %d \n", arrivee);
	
	
	liberer_sommet(tab_sommets, x);
	liberer_tab_hachage(tab_hach, dimension);
	
	tab_hach=calloc(dimension,sizeof(*tab_hach));
	puts("la table de hachage est vidée");
	puts("ajout de différents mots");
	e="a";
	n=hachage(e, dimension);
	tab_hach[n]=ajout_tete_hachage(e,tab_hach[n]);
	e="b";
	n=hachage(e, dimension);
	tab_hach[n]=ajout_tete_hachage(e,tab_hach[n]);
	e="c";
	n=hachage(e, dimension);
	tab_hach[n]=ajout_tete_hachage(e,tab_hach[n]);
	e="d";
	n=hachage(e, dimension);
	tab_hach[n]=ajout_tete_hachage(e,tab_hach[n]);
	e="e";
	n=hachage(e, dimension);
	tab_hach[n]=ajout_tete_hachage(e,tab_hach[n]);
	e="f";
	n=hachage(e, dimension);
	tab_hach[n]=ajout_tete_hachage(e,tab_hach[n]);
	e="g";
	n=hachage(e, dimension);
	tab_hach[n]=ajout_tete_hachage(e,tab_hach[n]);
	e="h";
	n=hachage(e, dimension);
	tab_hach[n]=ajout_tete_hachage(e,tab_hach[n]);
	e="a";
	n=hachage(e, dimension);
	tab_hach[n]=ajout_tete_hachage(e,tab_hach[n]);
	
	visualiser_liste_hachage(tab_hach, dimension);
	
	puts("supression du premier element sur la première ligne");
	tab_hach[1]=supprimer_tete_hachage(tab_hach[1]);
	visualiser_liste_hachage(tab_hach, dimension);
	
	
	liberer_tab_hachage(tab_hach, dimension);
}
