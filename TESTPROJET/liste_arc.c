#include "liste_arc.h"

/* Affichage d'un arc */
void affiche_arc(T_ARC* e) {
    printf("arrivee : %d, cout : %lf ;",e->arrivee, e->cout);
}

/* Creation d'une liste d'arc */
L_ARC creer_liste_arc(void) {
    return NULL;
}

/* Verification si la liste d'arc est vide
   Renvoie 1 si la liste est vide, 0 sinon */
int est_vide_arc(L_ARC l) {
    return !l;
}

/* Visualisation de la liste d'arc */
void visualiser_liste_arc(L_ARC l) {
    L_ARC c = NULL;
	if (est_vide_arc(l)) {
		printf("Liste vide");
	}
  	for (c = l; !est_vide_arc(c); c = c->suiv) {
		affiche_arc(&(c->val));
	}
	printf("\n");
}

/* Ajout d'un element en tete de la liste d'arc */
L_ARC ajout_tete_arc(T_ARC e, L_ARC l) {
	L_ARC c = NULL;
	c = calloc(1,sizeof(*c));
	if (c == NULL) {
    puts("Memory error : L_ARC");
		return NULL;
	}
	c->val = e;
	c->suiv = l;
	return c;
}

/* Suppression d'un element en tete de la liste d'arc */
L_ARC supprimer_tete_arc(L_ARC l) {
	L_ARC c;
	if (est_vide_arc(l)) {
		return NULL;
	}
	c = l->suiv;
	free(l);
	return c;
}

/* Liberation de la liste d'arc */
void liberer_arc(L_ARC l) {
	L_ARC c = NULL;
	c = l;
	while (c != NULL) {
		c = supprimer_tete_arc(c);
	}
}

/* Ajout d'un element en queue de la liste d'arc */
L_ARC ajout_queue_arc(T_ARC e, L_ARC l) {
	L_ARC c = NULL;
    L_ARC p = NULL;
    if (est_vide_arc(l)) {
        return ajout_tete_arc(e,l);
    }
    c = calloc(1,sizeof(*c));
    if (est_vide_arc(c)) {
        return NULL;
	}
    c->val = e;
    c->suiv = NULL;
    p = l;
    while (p->suiv != NULL) {
        p = p->suiv;
    }
    p->suiv = c;
    return l;
}

/* Concatenation de 2 listes d'arc */
L_ARC concat_arc(L_ARC l1, L_ARC l2) {
	L_ARC p = NULL;
    L_ARC c = NULL;
    L_ARC s = NULL;
	if (est_vide_arc(l1)) {
		return NULL;
	}
	if (est_vide_arc(l2)) {
		return l1;
	}
    c = copie_arc(l1);
    s = copie_arc(l2);
    p = c;
    while (p->suiv != NULL) {
        p = p->suiv;
    }
	p->suiv = s;
	return c;
}

/* Copie de la liste d'arc */
L_ARC copie_arc(L_ARC l) {	//copie en O(n)
	L_ARC p = NULL;
	L_ARC m = NULL;
	L_ARC c = NULL;
	if (est_vide_arc(l)) {
		return NULL;
	}
	m = calloc(1,sizeof(*m));
    if (est_vide_arc(m)) {
		return NULL;
	}
    c = m;
    p = l;
    while(p != NULL) {
        c->val = p->val;
        p = p->suiv;
        if (p != NULL) {
            c->suiv = calloc(1,sizeof(*m));
            if (est_vide_arc(m)) {
                return NULL;
            }
        c = c->suiv;
        }
	}
	return m;
}

/* Suppression du maillon n de la liste d'arc */
L_ARC supprimen_arc(int n, L_ARC l) {
	L_ARC p = NULL;
	L_ARC m = NULL;
    L_ARC k = NULL;
 	int c = 2;
    if (n <= 0) {
        printf("Error : n<=0\n");
        return copie_arc(l);
    }
    k = copie_arc(l);
	p = k;
    if(n == 1) {
        k = supprimer_tete_arc(k);
        return k;
    }
	while (c != n){
		p = p->suiv;
		c += 1;
	}
	m = p->suiv;
	p->suiv = m->suiv;
	free(m);
    return k;
}

/* Recherche d'un element de la liste d'arc */ //wtf ??????
L_ARC rech_arc(int arrivee, double cout, L_ARC l) {
    L_ARC p = creer_liste_arc();
    p = l;
    L_ARC m = creer_liste_arc();
    L_ARC n = creer_liste_arc();
    T_ARC e = {arrivee,cout};
    if(est_vide_arc(p)) {
        p = ajout_tete_arc(e, p);
        return p;
    }
    n = calloc(1,sizeof(*n));
    if (n == NULL) {
		printf("Memory error : L_ARC");
		exit(1);
	}
    n->val = e;
    while( !est_vide_arc(p->suiv) && (p->val.arrivee == arrivee) ) {p = p->suiv;}
    m = p->suiv;
    p->suiv = n;
    n->suiv = m;
    return l;
}
