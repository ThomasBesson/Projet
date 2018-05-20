#ifndef _LISTE_HACHAGE
#define _LISTE_HACHAGE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"

/* Structure de liste pour le hachage */
typedef char* ELEMENT;
struct cellule {
    ELEMENT val;
    int x;
    struct cellule * suiv;};
typedef struct cellule * Liste_hachage;

/* Prototypes des fonctions de hachage */
Liste_hachage creer_liste_hachage(void);
int est_vide_hachage(Liste_hachage l);
int rech_hachage(ELEMENT e, Liste_hachage l, T_SOMMET* tab, int x);
Liste_hachage ajout_tete_hachage(ELEMENT e, Liste_hachage l, int a);
Liste_hachage supprimer_tete_hachage(Liste_hachage l);
void liberer_hachage(Liste_hachage l);
int dimension_tab_hachage(void);
void liberer_tab_hachage(Liste_hachage l[], int len);

#endif
