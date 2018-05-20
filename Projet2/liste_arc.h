#ifndef _L_ARC
#define _L_ARC

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

/* Prototypes des fonctions de liste d'arc */
void affiche_arc(T_ARC* e);
L_ARC creer_liste_arc(void);
int est_vide_arc(L_ARC l);
void visualiser_liste_arc(L_ARC l);
L_ARC ajout_tete_arc(T_ARC e, L_ARC l);
L_ARC supprimer_tete_arc(L_ARC l);
void liberer_arc(L_ARC l);
L_ARC ajout_queue_arc(T_ARC e, L_ARC l);
L_ARC concat_arc(L_ARC l1, L_ARC l2);
L_ARC copie_arc(L_ARC l);
L_ARC supprimen_arc(int n, L_ARC l);
L_ARC rech_arc(int arrivee, double cout, L_ARC l);

#endif
