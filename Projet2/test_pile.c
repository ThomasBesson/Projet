#include <stdio.h>
#include "pile.h"

int main(){
	Pile p=creer_pile();
	int i;
	for(i=0;i<5;i++){
		p=empiler(i, p);
	}
	printf("construction pile :");
	visualiser_pile(p);
	puts("depiler");
	while(!pile_vide(p)){
		i=depiler(&p);
		printf("Pile :");
		visualiser_pile(p);
		printf("element dépilé : %d\n",i);
	}
	liberer_pile(p);
}
