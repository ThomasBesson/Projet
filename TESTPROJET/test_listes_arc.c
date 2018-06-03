#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "liste_arc.h"

int main() {
  	T_ARC c;
	L_ARC l1,l2,l3,l4,l5,l6;
	l1=creer_liste_arc();
	l2=creer_liste_arc();
	l3=creer_liste_arc();
	l4=creer_liste_arc();
	l5=creer_liste_arc();

	puts("Test de l'ajout en tete d'un arc et de l'affichage");
	puts("Ajout en tete de l'arc (1,2)");
	c.arrivee=1;    c.cout=2;
	l1=ajout_tete_arc(c,l1);
	printf("Liste : ");    visualiser_liste_arc(l1);
	puts("Ajout en tete de l'arc (1,-3)");
	c.arrivee=1;    c.cout=-3;
	l1=ajout_tete_arc(c,l1);
	printf("Liste : ");    visualiser_liste_arc(l1);
	puts("Ajout en tete de l'arc (3,3)");
	c.arrivee=3;    c.cout=3;
	l1=ajout_tete_arc(c,l1);
	printf("Liste : ");    visualiser_liste_arc(l1);
	puts("Ajout en tete de l'arc (4,-5)");
	c.arrivee=4;    c.cout=-5;
	l1=ajout_tete_arc(c,l1);
	printf("Liste : ");    visualiser_liste_arc(l1);

	l2=creer_liste_arc();
	printf("\nNouvelle Liste : Test de l'ajout en queue d'un arc et de l'affichage\n");
	puts("Ajout en queue de l'arc (1,2)");
	c.arrivee=1;    c.cout=2;
	l2=ajout_queue_arc(c,l2);
	printf("Liste : ");    visualiser_liste_arc(l2);
	puts("Ajout en queue de l'arc (1,-3)");
	c.arrivee=1;    c.cout=-3;
	l2=ajout_queue_arc(c,l2);
	printf("Liste : ");    visualiser_liste_arc(l2);
	puts("Ajout en queue de l'arc (3,3)");
	c.arrivee=3;    c.cout=3;
	l2=ajout_queue_arc(c,l2);
	printf("Liste : ");    visualiser_liste_arc(l2);
	puts("Ajout en queue de l'arc (4,-5)");
	c.arrivee=4;    c.cout=-5;
	l2=ajout_queue_arc(c,l2);
	printf("Liste : ");    visualiser_liste_arc(l2);

	puts("\nTest de la suppression en tete d'un arc et de l'affichage");
	printf("Liste : ");    visualiser_liste_arc(l1);
	puts("Suppression en tete");
	l1=supprimer_tete_arc(l1);
	printf("Liste : ");    visualiser_liste_arc(l1);
	puts("Suppression en tete");
	l1=supprimer_tete_arc(l1);
	printf("Liste : ");    visualiser_liste_arc(l1);
	puts("Suppression en tete");
	l1=supprimer_tete_arc(l1);
	printf("Liste : ");    visualiser_liste_arc(l1);
	puts("Suppression en tete");
	l1=supprimer_tete_arc(l1);
	printf("Liste : ");    visualiser_liste_arc(l1);
	puts("Suppression en tete");
	l1=supprimer_tete_arc(l1);
	printf("Liste : ");    visualiser_liste_arc(l1);

	puts("\nTest des concatenations");

	c.arrivee=1; c.cout=2; l1=ajout_tete_arc(c,l1);
	c.arrivee=2; c.cout=3; l1=ajout_tete_arc(c,l1);
	c.arrivee=3; c.cout=4; l1=ajout_tete_arc(c,l1);
	c.arrivee=5; c.cout=6; l1=ajout_tete_arc(c,l1);
	c.arrivee=7; c.cout=8; l1=ajout_tete_arc(c,l1);
	printf("Liste l1: "); visualiser_liste_arc(l1);

	c.arrivee=-1; c.cout=-2; l2=ajout_tete_arc(c,l2);
	c.arrivee=-2; c.cout=-3; l2=ajout_tete_arc(c,l2);
	c.arrivee=-3; c.cout=-4; l2=ajout_tete_arc(c,l2);
	c.arrivee=-5; c.cout=-6; l2=ajout_tete_arc(c,l2);
	printf("Liste l2: "); visualiser_liste_arc(l2);

	l4=copie_arc(l1);
	puts("Copie de l1 dans l4");
	printf("Liste l1: "); visualiser_liste_arc(l1);
	printf("Liste l4: "); visualiser_liste_arc(l4);

	l5=l1;
	puts("Affectation de la liste l1 dans l5");
	printf("Liste l5: "); visualiser_liste_arc(l5);
	printf("Liste l1: "); visualiser_liste_arc(l1);

	puts("Concatenation de l2 a la suite de l1 dans l3");
	l3=concat_arc(l1,l2);
	printf("Liste l1: "); visualiser_liste_arc(l1);
	printf("Liste l2: "); visualiser_liste_arc(l2);
	printf("Liste l3: "); visualiser_liste_arc(l3);
	printf("Liste l4: "); visualiser_liste_arc(l4);
	printf("Liste l5: "); visualiser_liste_arc(l5);

  liberer_arc(l1);
  liberer_arc(l2);
  liberer_arc(l3);
  liberer_arc(l4);

	puts("\nTest de suppression du maillon n");

  l1=creer_liste_arc();
  l2=creer_liste_arc();
  l3=creer_liste_arc();
  l4=creer_liste_arc();
  l5=creer_liste_arc();
  l6=creer_liste_arc();

	c.arrivee=1; c.cout=1; l1=ajout_queue_arc(c,l1);
	c.arrivee=2; c.cout=-2; l1=ajout_queue_arc(c,l1);
	c.arrivee=3; c.cout=3; l1=ajout_queue_arc(c,l1);
	c.arrivee=4; c.cout=-4; l1=ajout_queue_arc(c,l1);
	c.arrivee=5; c.cout=5; l1=ajout_queue_arc(c,l1);
	c.arrivee=6; c.cout=-6; l1=ajout_queue_arc(c,l1);
	c.arrivee=7; c.cout=7; l1=ajout_queue_arc(c,l1);

	puts("Liste l1 avant modification :"); visualiser_liste_arc(l1);
	l2=supprimen_arc(4,l1);
	puts("Liste l1 après modification sur le maillon 4 :"); visualiser_liste_arc(l2);
	l3=supprimen_arc(5,l2);
	puts("Liste l1 après modification sur le maillon 5 :"); visualiser_liste_arc(l3);
	l4=supprimen_arc(1,l3);
	puts("Liste l1 après modification sur le maillon 1 :"); visualiser_liste_arc(l4);
	l5=supprimen_arc(2,l4);
	puts("Liste l1 après modification sur le maillon 2 :"); visualiser_liste_arc(l5);
	l6=supprimen_arc(0,l5);
	puts("Liste l1 après essai de modification sur le maillon 0 :"); visualiser_liste_arc(l6);

	puts("\nLiberation de toutes les listes");
	liberer_arc(l1);
	liberer_arc(l2);
	liberer_arc(l3);
	liberer_arc(l4);
	liberer_arc(l5);
	liberer_arc(l6);
}
