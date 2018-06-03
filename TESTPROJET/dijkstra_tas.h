#ifndef dijkstra_tas_h
#define dijkstra_tas_h

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include "graphes.h"
#include "algo.h"
#include "pile.h"
#include "tas.h"
#include "time.h"
#include "liste_hachage.h"

/* Prototype de la fonction de tri par djikstra + tas */
double dijstra_tas(int numero_depart, int numero_arrivee, T_SOMMET* tab_sommets, int x);

#endif
