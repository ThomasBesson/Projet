#include "liste.h"

/* Creation d'une liste basique */
Liste creer_liste_basique(void) {
	return NULL;
}

/* Verification si la liste basique est vide
   Renvoie 1 si la liste est vide, 0 sinon */
int est_vide_basique(Liste l) {
	return !l;
}

/* Visualisation de la liste basique */
void visualiser_liste_basique(Liste l) {
 	Liste c = NULL;
	if (est_vide_basique(l)) {
		puts("liste vide");
		return;
	}
    for (c = l; !est_vide_basique(c); c = c->suiv) {
		printf("%d ",c->val);
	}
	printf("\n");
}

/* Ajout d'un element en tete de la liste basique */
Liste ajout_tete_basique(int e, Liste l) {
	Liste c = NULL;
	c = calloc(1,sizeof(*c));
	if (c == NULL) {
		return NULL;
	}
	c->val = e;
	c->suiv = l;
	return c;
}

/* Suppression d'un element en tete de la liste basique */
Liste supprimer_tete_basique(Liste l) {
	Liste c = NULL;
	if (est_vide_basique(l)) {
		return NULL;
	}
	c = l->suiv;
	free(l);
	return c;
}

/* Liberation de la liste basique */
void liberer_basique(Liste  l) {
	Liste c = NULL;
	c = l;
	while (c  != NULL) {
		c = supprimer_tete_basique(c);
	}
}

/* Ajout d'un element en queue de la liste basique */
Liste ajout_queue_basique(int e, Liste l) {
	Liste c = NULL;
 	Liste p = NULL;
    if (est_vide_basique(l)) {
    	return ajout_tete_basique(e,l);
    }
    c = calloc(1,sizeof(*c));
    if (est_vide_basique(c)) {
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

/* Concatenation de 2 listes basiques*/
Liste concat_basique(Liste l1, Liste l2) {
	Liste p = NULL;
    Liste c = NULL;
    Liste s = NULL;
	if (est_vide_basique(l1)) {
		return NULL;
	}
	if (est_vide_basique(l2)) {
		return l1;
	}
    c = copie_basique(l1);
    s = copie_basique(l2);
    p = c;
    while (p->suiv != NULL) {
        p = p->suiv;
    }
	p->suiv = s;
	return c;
}

/* Copie de la liste basique */
Liste copie_basique(Liste l) {	//copie en O(n)
	Liste p = NULL;
	Liste m = NULL;
	Liste c = NULL;
	if (est_vide_basique(l)) {
		return NULL;
	}
	m = calloc(1,sizeof(*m));
    if (est_vide_basique(m)) {
		return NULL;
	}
    c=m;
    p=l;
    while(p!=NULL) {
        c->val=p->val;
        p=p->suiv;
        if (p!=NULL) {
            c->suiv = calloc(1,sizeof(*m));
            if (est_vide_basique(m)) {
                return NULL;
            }
        c=c->suiv;
        }
	}
	return m;
}

/* Suppression du maillon n de la liste basique */
Liste supprimen_basique(int n, Liste l) {
	Liste p = NULL;
	Liste m = NULL;
 	int c = 1;
    if (n < 0) {
        printf("Error : n<=0\n");
        return l;
    }
	p = l;
    if(n == 0) {
		l = supprimer_tete_basique(l);
        return l;
    }
	while (c != n){
		p = p->suiv;
		c += 1;
	}
	m = p->suiv;
	p->suiv = m->suiv;
	free(m);
    return l;
}

/* Suppression d'un element en queue de la liste basique */
Liste supprimer_queue_basique(Liste l, int* x) {
	Liste p = NULL;
	p = l;
    if(est_vide_basique(p)) {
		puts("Error : l est vide");
        return l;
    }
	if(est_vide_basique(p->suiv)) {
		l = supprimer_tete_basique(l);
		return l;
	}
	while (!est_vide_basique(p->suiv->suiv)){
		puts("while suppr");
		p = p->suiv;
	}
	*x = p->suiv->val;
	p->suiv = NULL;
	free(p->suiv);
  return l;
}
