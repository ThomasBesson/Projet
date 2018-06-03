#ifndef _LISTE
#define _LISTE

#include <stdio.h>
#include <stdlib.h>

/* Structure de liste basique */
struct cellule1 {
	int val;
	struct cellule1 * suiv;};

typedef struct cellule1* Liste;

/* Prototypes des fonctions de liste basique */
Liste creer_liste_basique(void);
int est_vide_basique(Liste l);
void visualiser_liste_basique(Liste l);
Liste ajout_tete_basique(int e, Liste l);
Liste supprimer_tete_basique(Liste l) ;
void liberer_basique(Liste  l);
Liste ajout_queue_basique(int e, Liste l);
Liste concat_basique(Liste l1, Liste l2);
Liste copie_basique(Liste l);
Liste supprimen_basique(int n, Liste l);
Liste supprimer_queue_basique(Liste l, int* x);

#endif
