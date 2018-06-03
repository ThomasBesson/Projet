#include <stdio.h>
#include <stdlib.h>
#include "tas.h"
#include "struct.h"
#include "graphes.h"
#include "liste_hachage.h"


int main(){
	int*tab=calloc(5,sizeof(*tab));
	int x;
	construction_tab(tab, 5);
	double*pcc=calloc(5,sizeof(*pcc));
	pcc[0]=23;
	pcc[1]=5;
	pcc[2]=7;
	pcc[3]=3;
	pcc[4]=-4;
	Liste_hachage*tab_hach=calloc(3,sizeof(*tab_hach));
	T_SOMMET*tab_sommets;
	char nom_graphe[]="graphe1.txt";
	tab_sommets=lecture_graphe(nom_graphe,&x,3,tab_hach);

	printf("tab ;");
	visualiser_tab(tab, 5);
	printf("pcc :");
	visualiser_tab2(pcc, 5);
	constructiontas(pcc, 5, tab, tab_sommets);

	printf("Apres la construction du tas\n");
	printf("C :");
	visualiser_tab(tab, 5);
	printf("pcc :");
	visualiser_tab2(pcc, 5);

	free(tab);
	free(pcc);
	liberer_sommet(tab_sommets, x);
	liberer_tab_hachage(tab_hach, 3);
}
