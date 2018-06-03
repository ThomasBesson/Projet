#include "algo.h"

/* Allocation du tableau de pcc */
int* alloue(int x) {
    int* tab = NULL;
    tab = calloc(x, sizeof(*tab));
    if (tab == NULL) {
        printf("Memory error : pcc");
        return NULL;
    }
    return tab;
}

/* Allocation du tableau de pcc */
int rech_j(int e, Liste L) {
    Liste p = L;
    int c = 0;
    while(!est_vide_basique(p->suiv) && p->val!=e) {
        p=p->suiv;
        c+=1;
    }
    return c;
}

/* Verification si l'element est dans le tableau
   Renvoie 1 si l'element est dans le tableau, 0 sinon */
int appartient_tab(int a, int*S,int n) {
    int i=0;
    while(i<n) {
        if (a == S[i]) {
            return 1;
        }
        i=i+1;
    }
    return 0;
}

/* Verification si l'element est dans la liste
   Renvoie 1 si l'element est dans la liste, 0 sinon */
int appartient_liste(int a, Liste S) {
    Liste p = S;
    while(!est_vide_basique(p)) {
        if (p->val == a) {
            return 1;
        }
        p = p->suiv;
    }
    return 0;
}

/* Creation de la liste C triee */
Liste creer_C(T_SOMMET* tab_sommets, int x) {
    int i;
    Liste p = NULL;
    for (i=0; i<x; i++) {
        p = ajout_queue_basique(i,p);
    }
    return p;
}

/* Recherche et renvoie le minimum des pcc */
int min_pcc(double* pcc, int x, Liste L) {
    Liste p = L;
    int mini = p->val;
    while(!est_vide_basique(p->suiv)) {
        p = p->suiv;

        if (pcc[p->val]<pcc[mini]) {
            mini = p->val;
        }
    }
    return mini;
}

/* Visualisation du tableau d'entiers */
void visualiser_tab(int* tab, int x) {
    int i;
    for (i=0; i<x; i++) {
        printf("%d ",tab[i]);
    }
    printf("\n");
}

/* Visualisation du tableau de doubles */
void visualiser_tab2(double* tab, int x) {
    int i;
    for (i=0; i<x; i++) {
        printf("%lf ",tab[i]);
    }
    printf("\n");
}

/* Construction du plus court chemin */
void chemin(int* pere, int d, int a, Pile *court) {
    int s = a;
    if (pere[a] == -1) {
        return;
    }
    *court = empiler(a,*court);
    while (pere[s]!=d) {
        *court = empiler(pere[s],*court);
        s = pere[s];
    }
    *court = empiler(d,*court);
}
