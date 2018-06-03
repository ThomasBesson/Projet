//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include "liste.h"
#include "struct.h"
#include "liste_arc.h"
#include "pile.h"

/* Prototypes des fonctions utiles pour l'algo */
int* alloue(int x);
int rech_j(int e, Liste L);
int appartient_tab(int a, int* S,int n);
Liste creer_C(T_SOMMET* tab_sommets, int x);
int min_pcc(double* pcc, int x, Liste L);
int appartient_liste(int a, Liste S);
void visualiser_tab(int* tab, int x);
void chemin(int* pere, int d, int a, Pile *x);
void visualiser_tab2(double* tab, int x);
