#include "dijkstra_tas.h"

#define INF 0XFFFFFF


double dijstra_tas(int numero_depart, int numero_arrivee,T_SOMMET*tab_sommets,int x){

    /*initialisation variables*/
    clock_t debut,fin;
    int* pere = NULL; //tableau pere
    Pile trajet = creer_pile(); //Pile court
    int i; //indice boucle
    int j; //numero sommmet avec + petit pcc et son indice
    int k;
	int a;
	int b;
	int c=0;
    double cout;
    Liste S = creer_liste_basique();

    /*allocation*/
    pere = alloue(x);
	int*C=calloc(x, sizeof(*C));
	double*pcc=calloc(x, sizeof(*pcc));

    /*initialisation algo*/

    for (i=0; i<x; i++) {
        pere[i] = -1;
		pcc[i]=INF;
    }
	pcc[numero_depart]=0;
	construction_tab(C, x);
	constructiontas(pcc, x, C, tab_sommets);


    /*boucle faire algo*/
    debut=clock();
    do {
		j=C[0];
		c=c+1;

		swap(pcc, pcc+x-c);
		swap_tab_T_SOMMET(tab_sommets, C, 0, x-c);
		swap_tab(C, 0, x-c);

        S = ajout_queue_basique(j,S);

        L_ARC p = tab_sommets[j].voisins;


		/*boucle sommets k adjacents*/
        while (!est_vide_arc(p)) {
            k=p->val.arrivee;
			cout=p->val.cout;
			a=tab_sommets[k].tas;
			b=tab_sommets[j].tas;
			if(pcc[a]> pcc[b]+cout) {
				pcc[a] = pcc[b]+cout;
				pere[k]=j;
			}
			p = p->suiv;
		}

		constructiontas(pcc, x-c, C, tab_sommets);

	} while (!appartient_liste(numero_arrivee, S) && j!=INF);
    fin=clock();

    /*recuperation du + court chemin*/
    chemin(pere,numero_depart,numero_arrivee,&trajet);
    if(pcc[tab_sommets[numero_arrivee].tas]==INF){
        printf("Il n'y a pas de chemin possible pour aller de %s à %s.\n\n",tab_sommets[numero_depart].nom,tab_sommets[numero_arrivee].nom);
    }
    else {
        printf("Chemin : ");
        visualiser_pile_char(trajet,tab_sommets);
        printf("Cout : %lf\n\n", pcc[tab_sommets[numero_arrivee].tas]);
    }

    /*liberation*/
    liberer_basique(S);
	free(pcc);
	free(C);
    free(pere);
    liberer_pile(trajet);

    return ((double)fin-debut)/CLOCKS_PER_SEC;
}
