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

void UpdateEvents(Input* in);
void InitEvents(Input* in);
void attendreTouche(void);
void actualiser(void);
void correspondanceDepart(int dilatation, double r, Input* in);
void correspondanceArrivee(int dilatation, double r, Input* in);
void testDijkstra(Input* in);

#endif /* INC_FEVENT_H_ */
