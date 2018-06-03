#include "graphes.h"

/* Visualisation du graphe */
void visualiser_graphe2(T_SOMMET* tab_sommets, int* k) {
  int i;
  for (i=0; i<(*k); i++) {
      visualiser_liste_arc(tab_sommets[i].voisins);
  }
}

void visualiser_graphe(T_SOMMET* tab_sommets, int* k) {
  int i;
  for (i=0; i<(*k); i++) {
      printf("Indice : %d, Nom : %s, Coordonnées : (%lf, %lf)\n", i,
      tab_sommets[i].nom, tab_sommets[i].x, tab_sommets[i].y);
  }
}

/* Hachage du nom du sommet */
unsigned int hachage(char* mot, int dim_tab_hach){
    int i = 0;
    unsigned long h = 0, a = 1;
    while(mot[i] != '\0'){
        h = ( h+mot[i]*a )%dim_tab_hach;
        a = a*31;
        i = i+1;
    }
    return h;
}


void lecture_sommet(FILE* fp, T_SOMMET* tab_sommets, int* k ,int dimension, Liste_hachage* tab_hach) {

    int numero;
    double lat,longi;
    char line[128];
    char mot[512];

    int n;
    int i;

    fscanf(fp,"%d %lf %lf %s ", &(numero), &(lat), &(longi), line);
    /*numéro contient alors l’entier, lat et longi la position, line le nom de la ligne*/
    fgets(mot, 511, fp);
//    fscanf(fp,"%s",mot);
    if (mot[strlen(mot)-1]<32) mot[strlen(mot)-1]=0;
    /*mot contient le nom du sommet.*/

    (tab_sommets[*k]).nom = calloc(1,512);
    if ((tab_sommets[*k]).nom == NULL) {
        printf("Memory error : T_SOMMET.nom\n");
          exit(1);
    }

    memcpy((tab_sommets[*k]).nom,mot,512);
    memcpy((tab_sommets[*k]).ligne,line,128);
    for (i=0; i<strlen(mot); i++) {
      mot[i]=tolower(mot[i]);
    }
    n = hachage(mot,dimension);
    tab_hach[n] = ajout_tete_hachage(mot,tab_hach[n]);
    (tab_sommets[*k]).x = lat;
    (tab_sommets[*k]).y = longi;
    tab_sommets[*k].tas = *k;
}

void lecture_arc(FILE* fp, T_SOMMET* tab_sommets) {
    int depart, arrivee;
    double cout;
    fscanf(fp,"%d %d %lf", &depart, &arrivee, &cout);
    tab_sommets[depart].voisins = rech_arc(arrivee, cout, tab_sommets[depart].voisins);
}

T_SOMMET* lecture_graphe(char* nom_graphe, int* s, int dimension, Liste_hachage* tab_hach) {
    int x,y;
    int i,j,k = 0;
    char mot[512];
    T_SOMMET* tab_sommets = NULL;
    FILE* fp = NULL;
    fp = fopen(nom_graphe, "rt");
    if (fp == NULL) {
        printf("Error sur l'ouverture du dico\n");
        exit(1);
    }
    fscanf(fp,"%d %d", &x, &y);
    fgets(mot,511,fp);
    tab_sommets = calloc(x, sizeof(*tab_sommets));

    if (tab_sommets == NULL) {
        printf("Memory error : T_SOMMET*\n");
        exit(1);
    }
    fgets(mot,511,fp);
    for (i=0; i<x; i++) {
        lecture_sommet(fp, tab_sommets, &k,dimension,tab_hach);
        k+=1;
    }
    fgets(mot,511,fp);
    for (j=0; j<y; j++) {
        lecture_arc(fp, tab_sommets);
    }
    fclose(fp);
    *s = x;
    return tab_sommets;
}

void liberer_sommet(T_SOMMET* tab_sommets, int x) {
    int i;
    for (i=0; i<x; i++) {
    liberer_arc(tab_sommets[i].voisins);
    free(tab_sommets[i].nom);
    }
    free(tab_sommets);
}

int demande_station_depart(Liste_hachage*tab_hach,int dimension_tab_hach,T_SOMMET*tab_sommets,int x){
    char depart[512];
    int i;
    int valeur;
    int numero;

    puts("De quelle station partez-vous ? (Vous pouvez écrire le nom ou le numero de la station)");
	scanf(" %512[^\n]", depart);
	printf("\n");
    if(isdigit(depart[0])){
        numero=atoi(depart);
        if(numero>(x-1) || numero<0){
            printf("Le numéro entré n'est pas un sommet du graphe\n");
            exit(1);
        }
    }
    else{
        for (i=0; i<strlen(depart); i++) {
            depart[i]=tolower(depart[i]);
        }
        valeur=hachage(depart, dimension_tab_hach);
        numero=rech_hachage(depart,tab_hach[valeur],tab_sommets,x);
        if(numero==-1){
            puts("Vous vous êtes trompé dans le nom de la station de depart");
            exit(1);
        }
    }
    return numero;
}

int demande_station_arrivee(Liste_hachage*tab_hach,int dimension_tab_hach,T_SOMMET*tab_sommets,int x){
    char arrivee[512];
    int i;
    int valeur;
    int numero;

    puts("A quelle station arrivez-vous ? (Vous pouvez écrire le nom ou le numero de la station)");
    scanf(" %512[^\n]",arrivee);
    printf("\n");
    if(isdigit(arrivee[0])){
        numero=atoi(arrivee);
        if(numero>(x-1) || numero<0){
            printf("Le numéro entré n'est pas un sommet du graphe\n");
            exit(1);
        }
    }
    else{
        for (i=0; i<strlen(arrivee); i++) {
            arrivee[i]=tolower(arrivee[i]);
        }
        valeur=hachage( arrivee, dimension_tab_hach);
        numero=rech_hachage(arrivee,tab_hach[valeur],tab_sommets,x);
        if(numero==-1){
            puts("Vous vous êtes trompé dans le nom de la station d'arrivée");
            exit(1);
        }
    }
    return numero;
}
