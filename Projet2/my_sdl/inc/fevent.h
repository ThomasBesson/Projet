/*
 * fevent.h
 *
 *  Created on: 29 avr. 2018
 *      Author: student
 */

#ifndef INC_FEVENT_H_
#define INC_FEVENT_H_

#include "struct.h"
#include "config.h"
#include "dijkstra.h"

/* Generation des evenements dynamiques et mise a jour l'affichage */
void UpdateEvents(Input* in);

/* Initialisation de la structure d'evenements */
void InitEvents(Input* in);

/* Attente de le pression d'une touche */
void attendreTouche(void);

/* Actualisation de l'interface grapĥique */
void actualiser(void);

/* Correspondance entre les coordonnes graphiques et ceux propres aux sommets */
void correspondanceDepart(int dilatation, double r, Input* in);
void correspondanceArrivee(int dilatation, double r, Input* in);

/* Verification si les conditions sont remplies pour lancer Dijkstra */
void testDijkstra(Input* in);

#endif /* INC_FEVENT_H_ */
