#include "pile.h"

/* Verification si la pile est vide
   Renvoie 1 si la liste est vide, 0 sinon */
int pile_vide(Pile p){
	return !p;
}

/* Creation d'une pile */
Pile creer_pile(void){
	return NULL;
}

/* Empilement d'un element sur la pile */
Pile empiler(int c, Pile p){
	return ajout_tete_basique(c,p);
}

/* Depilement et renvoie d'un element de la pile */
int depiler(Pile * ap){
	int e = (*ap)->val;
	*ap = supprimer_tete_basique(*ap);
	return e;
}

/* Visualisation de la pile */
void visualiser_pile(Pile p){
	visualiser_liste_basique((Liste)p);
}

/* Liberation de la pile */
void liberer_pile(Pile p){
	int a;
	while(!pile_vide(p)){
		a = depiler(&p);
	}
}

/* Visualisation d'une pile de char */
void visualiser_pile_char(Pile p, T_SOMMET* C){
    visualiser_liste_char((Liste)p,C);
}

/* Visualisation d'une liste de char */
void visualiser_liste_char(Liste l, T_SOMMET* C) {
    Liste a = NULL;
    if (est_vide_basique(l)) {
        puts("liste vide");
        return;
    }
    printf("\n");
    for (a = l; !est_vide_basique(a); a = a->suiv) {
        printf("%s\t",C[a->val].nom);
        printf("Ligne : %s\n",C[a->val].ligne);
    }
    printf("\n");
}
