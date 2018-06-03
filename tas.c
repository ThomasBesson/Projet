#include "tas.h"

/* Echange de 2 doubles */
void swap(double* a, double* b){
	double c;
	c = *a;
	*a = *b;
	*b = c;
}

/* Recherche et renvoie l'indice du maximum */
int indice_du_maximum(double* tab, int a, int b){
	if (tab[a]>tab[b]){
		return a;
	}
	return b;
}

/* Echange de 2 elements tas du tableau tab_sommets */
void swap_tab_T_SOMMET(T_SOMMET* tab, int* C, int i, int j){
    int intermediaire = tab[C[i]].tas;
    tab[C[i]].tas = tab[C[j]].tas;
    tab[C[j]].tas = intermediaire;
}

/* Echange de 2 elements du tableau */
void swap_tab(int* tab, int i, int j){
    int intermediaire = tab[i];
    tab[i] = tab[j];
    tab[j] = intermediaire;
}

/* Agrandissement du tas */
void augmentetas(double* tab1, int i, int* tab, T_SOMMET* tab2){
	int pere = (i-2)/2;
	while( i>0 && tab1[pere]>tab1[i] ){
		swap(tab1+pere, tab1+i);
        swap_tab(tab, pere, i);
        swap_tab_T_SOMMET(tab2, tab, pere, i);
		i = pere;
		pere = pere/2;
	}
}

/* Construction d'un tas */
void constructiontas(double* tab1, int n, int* tab, T_SOMMET* tab2){
    int a;
	for (a=0; a<n; a++){
		augmentetas(tab1, a, tab, tab2);
    }

}

/* Correspondance entre tous les elements lorsqu'il y a 2 fils dans le tas */
void deux_fils(double* tab1, int* a, int fils1, int fils2, int* tab, T_SOMMET* tab2){
    int max = indice_du_maximum(tab1,fils1,fils2);
    swap(tab1+*a, tab1+max);
    swap_tab(tab, *a, max);
    swap_tab_T_SOMMET(tab2, tab, *a, max);
    *a = max;
}

/* Correspondance entre tous les elements lorsqu'il y a 1 fils dans le tas */
void un_fils(double* tab1, int a, int fils, int* tab, T_SOMMET* tab2){
    if(tab1[fils]<tab1[a]){
        swap(tab1+a, tab1+fils);
        swap_tab(tab, a, fils);
        swap_tab_T_SOMMET(tab2, tab, a, fils);
    }
}

/* Construction d'un tas */
void descendretas(double* tab1, int i, int* tab, T_SOMMET* tab2){
    int a=0,fils1=1,fils2=2;
    while( (fils1<i)&&(fils2<i)&&(tab1[fils1]>tab1[a]||tab1[fils2]>tab1[a]) ){
        deux_fils(tab1, &a, fils1, fils2, tab, tab2);
        fils1 = 2*a+1;
        fils2 = 2*a+2;
    }
    if(i==1){
        un_fils(tab1, a, fils1, tab, tab2);
    }
}

/* Suppression d'un tas */
void suppressiontas(double* tab1, int i, int* tab, T_SOMMET* tab2){
    swap(tab1, tab1+i-1);
    swap_tab(tab, 0, i-1);
    swap_tab_T_SOMMET(tab2 ,tab, 0, i-1);
	descendretas(tab1, i-1, tab, tab2);
}

/* Tri d'un tas */
void tri(double* tab1, int n, int* tab, T_SOMMET* tab2){
	int i;
    constructiontas(tab1, n, tab, tab2);
	if(n==1||n==0){
		if(tab1[0]>tab1[1]){
			swap(tab1, tab1+1);
			swap_tab(tab, 0, 1);
			swap_tab_T_SOMMET(tab2, tab, 0, 1);
		}
	}
	for(i=n; i>0; i--){
        suppressiontas(tab1,i,tab,tab2);
	}
}

/* Construction d'un tableau trie de n elements */
void construction_tab(int* tab,int n){
    int i;
    for (i=0; i<n; i++){
        tab[i] = i;
    }
}

/* Recherche et renvoie le minimum */
int minimum(int a,int b){
	if(a<b){
		return a;
	}
	return b;
}
