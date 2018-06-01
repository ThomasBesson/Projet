#ifndef _STRUCT
#define _STRUCT

/* Structure d'arc contenant le sommet d'arrivee et le cout pour y parvenir */
typedef struct {
    int arrivee;
    double cout; } T_ARC;

/* Structure de liste d'arcs contenant l'arc actuel et le lien pour parvenir au suivant */
typedef struct lsucc {
    T_ARC val;
    struct lsucc* suiv; } * L_ARC;

/* Structure de tableau de sommets contenant les informations relatives à chaque sommmet
   (nom, ligne, coordonnees...) ainsi que la liste d'arcs voisins */
typedef struct {
    char* nom;
    char ligne[128];
    double x,y;
    int tas;
  L_ARC voisins; } T_SOMMET;

#endif
