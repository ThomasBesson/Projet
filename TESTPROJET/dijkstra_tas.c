#include "dijkstra_tas.h"

#define INF 0xFFFFFFF

double dijstra_tas(int numero_depart, int numero_arrivee,T_SOMMET*tab_sommets,int x){

    /*initialisation variables*/
    clock_t debut,fin;
    double* pcc = NULL; //tableau pcc
    int* pere = NULL; //tableau pere
    int* C = NULL;
    Pile trajet = creer_pile(); //Pile court
    int i; //indice boucle
    int j; //numero sommmet avec + petit pcc et son indice
    int c=0; //taille tableau court
    int k;
	int max;
	int borne;
    int cout;
    Liste S = creer_liste_basique();

    /*allocation des tableaux*/
    pcc = calloc(x, sizeof(*pcc));
    C = calloc(x,sizeof(*C));
    pere = alloue(x);

    /*initialisation algo*/
    for (i=0; i<x; i++) {
        pcc[i] = INF;
        pere[i] = -1;
    }

    pcc[numero_depart]=0;
    construction_tab(C,x);
    tri(pcc,x-c,C,tab_sommets);

    /*boucle faire algo*/
    debut = clock();
    do {
        j=C[0];
	//max=0;
        c=c+1;
	//visualiser_tab(C, x);
	//visualiser_tab2(pcc, x);
	swap(pcc,pcc+x-c);
	swap_tab(C, 0, x-c);
	swap_tab_T_SOMMET(tab_sommets,C,0,x-c);

        S = ajout_queue_basique(j,S);

        L_ARC p = tab_sommets[j].voisins;

        /*boucle sommets k adjacents*/
        while (!est_vide_arc(p)) {
            k=p->val.arrivee;
            cout=p->val.cout;
            if(pcc[tab_sommets[k].tas] > pcc[x-c]+cout) {
                pcc[tab_sommets[k].tas] = pcc[x-c]+cout;
		/*if(tab_sommets[k].tas>max){
			max=tab_sommets[k].tas;
		}*/
                pere[k] = j;
            }
            p = p->suiv;
        }
//		printf("%d\n",max);
		//visualiser_tab(C, x);
		//visualiser_tab2(pcc, x);
//		borne=minimum(x-c,max);
		tri(pcc,x-c,C,tab_sommets);
//		printf("\n");
	} while (!appartient_liste(numero_arrivee, S) && pcc[x-c]!=INF);
    fin = clock();

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
    free(C);
    free(pcc);
    free(pere);
    liberer_pile(trajet);

    return ((double)fin-debut)/CLOCKS_PER_SEC;
}
