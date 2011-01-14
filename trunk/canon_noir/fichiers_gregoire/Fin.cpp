/*
 *  Fin.cpp
 *  Code
 *
 *  Created by Grégoire on 04/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Fin.h"
#include "Jeu.h"

/*Fin::Fin(Jeu* j) {
	jeu = j;
}*/

Fin::Fin(Jeu* j) : Etat(j) {
}

int Fin::obtGagnant() {
	return jeu->obtIndJoueurCourant();
}