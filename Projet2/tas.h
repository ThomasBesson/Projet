#ifndef _TAS
#define _TAS

//#include <stdio.h>
//#include <stdlib.h>
#include "struct.h"
#include "liste.h"
#include "algo.h"

/* Prototypes des fonctions de tas */
void swap(double* a, double* b);
int indice_du_minimum(double* tab, int a, int b);
void swap_tab_T_SOMMET(T_SOMMET* tab, int* C, int i, int j);
void swap_tab(int* tab, int i, int j);
void augmentetas (double* tab1, int i, int* tab, T_SOMMET* tab2);
void constructiontas(double* tab1, int n, int* tab, T_SOMMET* tab2);
void deux_fils(double* tab1, int* a, int fils1, int fils2, int* tab, T_SOMMET* tab2);
void un_fils(double* tab1, int a, int fils, int*tab, T_SOMMET* tab2);
void descendretas(double* tab1, int i, int* tab, T_SOMMET* tab2);
void suppressiontas (double* tab1, int i, int* tab, T_SOMMET* tab2);
void tri (double* tab1, int n, int* tab, T_SOMMET* tab2);
void construction_tab(int* tab, int n);
int minimum(int a, int b);

#endif
