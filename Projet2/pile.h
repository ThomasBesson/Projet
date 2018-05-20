#ifndef _Pile
#define _Pile

//#include <stdio.h>
#include "liste.h"
#include "struct.h"

/* Structure de pile */
typedef Liste Pile;

/* Prototypes des fonctions de pile */
/* ATTENTION : plusieurs de ces fonctions n'ont pas de sens avec une pile vide	*/

int pile_vide(Pile p);	/* une pile vide sera representee par NULL*/
Pile creer_pile(void);	/* une pile vide sera representee par NULL*/
Pile empiler(int, Pile p); /* Ajoute une carte au sommet de la pile */
int depiler(Pile *ap);	/* Retourne la carte au sommet et la supprime de la pile */
void visualiser_pile(Pile p); /* Affichage de tous les elements de la pile sans la modifier */
void liberer_pile(Pile p);
void visualiser_liste_char(Liste l, T_SOMMET* C);
void visualiser_pile_char(Pile p, T_SOMMET* C);

#endif
