#ifndef _GRAPHES
#define _GRAPHES

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include "liste_arc.h"
#include "liste.h"
#include "liste_hachage.h"
#include "ctype.h"

/* Prototypes des fonctions de graphe */
void visualiser_graphe(T_SOMMET* tab_sommets, int* k);
void lecture_arc(FILE* fp, T_SOMMET* tab_sommets);
T_SOMMET* lecture_graphe(char* nom_graphe, int* s, int dimension, Liste_hachage* tab_hach);
void liberer_sommet(T_SOMMET* tab_sommets, int x);
unsigned int hachage(char* mot, int dim_tab_hach);
void lecture_sommet(FILE* fp, T_SOMMET* tab_sommets, int* k, int dimension, Liste_hachage* tab_hach);
int demande_station_depart(Liste_hachage* tab_hach, int dimension_tab_hach, T_SOMMET* tab_sommets, int x);
int demande_station_arrivee(Liste_hachage* tab_hach, int dimension_tab_hach, T_SOMMET* tab_sommets, int x);

#endif
