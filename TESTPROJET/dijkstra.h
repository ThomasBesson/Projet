#ifndef dijkstra_h
#define dijkstra_h

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include "graphes.h"
#include "algo.h"
#include "pile.h"
#include "tas.h"
#include "time.h"
#include "liste_hachage.h"

/* Prototype de la fonction de tri par dijkstra */
double dijkstra(int numero_depart, int numero_arrivee, T_SOMMET* tab_sommets, int x);

#endif
