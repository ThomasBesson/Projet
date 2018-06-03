#include <stdio.h>

#include "dijkstra.h"

#define INF 0xFFFFFFF

double dijkstra(int numero_depart, int numero_arrivee,T_SOMMET*tab_sommets,int x){

    /*initialisation variables*/
    clock_t debut,fin;
    double* pcc = NULL; //tableau pcc
    int* pere = NULL; //tableau pere
    Pile trajet = creer_pile(); //Pile court
    int i; //indice boucle
    int j,indice_j; //numero sommmet avec + petit pcc et son indice
    int k; //numero sommet adjacent
    int c=0; //taille tableau court
    double cout; //cout
    Liste S = creer_liste_basique();
    Liste C = creer_liste_basique();

    /*allocation tableaux*/
    pcc = calloc(x, sizeof(*pcc));
    pere = alloue(x);

    /*initialisation algo*/
    for (i=0; i<x; i++) {
        pcc[i] = INF;
        pere[i] = -1;
    }

    pcc[numero_depart]=0;

    C = creer_C(tab_sommets, x);

    /*boucle faire algo*/
    debut = clock();
    do {
        c=c+1;
        j = min_pcc(pcc, x, C);
        indice_j = rech_j(j,C);

        C = supprimen_basique(indice_j,C);
        S = ajout_queue_basique(j,S);

        L_ARC p = tab_sommets[j].voisins;

        /*boucle sommets k adjacents*/
        while (!est_vide_arc(p)) {
            k = p->val.arrivee;
            cout = p->val.cout;
            if(pcc[k] > pcc[j]+cout) {
                pcc[k] = pcc[j]+cout;
                pere[k] = j;
            }
            p = p->suiv;
        }

    } while (!appartient_liste(numero_arrivee, S) && pcc[j]!=INF);
    fin = clock();

    /*recuperation du + court chemin*/
    chemin(pere,numero_depart,numero_arrivee,&trajet);
   if(pcc[tab_sommets[numero_arrivee].tas]==INF){
       printf("Il n'y a pas de chemin possible pour aller de %s à %s.\n",tab_sommets[numero_depart].nom,tab_sommets[numero_arrivee].nom);
    }
    else {
        printf("Chemin : ");
        visualiser_pile_char(trajet,tab_sommets);
        printf("Cout : %lf\n", pcc[tab_sommets[numero_arrivee].tas]);
    }

    /*liberation*/
    liberer_basique(S);
    liberer_basique(C);
    free(pcc);
    free(pere);
    liberer_pile(trajet);

    return ((double)fin-debut)/CLOCKS_PER_SEC;
}
