#include "graphes.h"
#include "algo.h"
#include "liste_hachage.h"
#include "dijkstra.h"
#include "dijkstra_tas.h"

//#define nom_graphe "graphe2.txt"

int main(int argc, char* argv[]) {

    argc=2;

    /*initialisation variables*/
    int numero_depart=-1;
    int numero_arrivee=-1;
    int dimension_tab_hach;
    int x; //nombre sommets

    double temps_dijkstra;
    double temps_dijkstra_tas;

    T_SOMMET* tab_sommets = NULL; //tableau sommets
    Liste_hachage* tab_hach = NULL;

    dimension_tab_hach = dimension_tab_hachage();
    tab_hach = calloc(dimension_tab_hach,sizeof(*tab_hach));

    //tab_sommets = lecture_graphe(nom_graphe, &x,dimension_tab_hach,tab_hach);
    //visualiser_graphe(tab_sommets, &x);
    //visualiser_graphe2(tab_sommets, &x);
    tab_sommets = lecture_graphe(argv[1], &x,dimension_tab_hach,tab_hach);

    numero_depart = demande_station_depart(tab_hach,dimension_tab_hach,tab_sommets,x);
    numero_arrivee = demande_station_arrivee(tab_hach,dimension_tab_hach,tab_sommets,x);

    temps_dijkstra = dijkstra(numero_depart, numero_arrivee, tab_sommets, x);

    temps_dijkstra_tas = dijstra_tas(numero_depart, numero_arrivee, tab_sommets, x);

	printf("Temps d'execution Dijkstra : %f\n",temps_dijkstra);
    printf("Temps d'execution Dijkstra avec un tri par tas : %f\n",temps_dijkstra_tas);

    /*liberation*/
    liberer_sommet(tab_sommets, x);
    liberer_tab_hachage(tab_hach, dimension_tab_hach);
}
