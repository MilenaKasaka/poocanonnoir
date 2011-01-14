/*
 *  Initialisation.cpp
 *  Code
 *
 *  Created by Grégoire on 04/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Initialisation.h"
//#include "Jeu.h"

/*Initialisation::Initialisation(Jeu* j) {
	jeu = j;
}*/


Initialisation::Initialisation(Jeu* j) : Etat(j) {
	srand(time(NULL));
}

bool Initialisation::initNbJoueurs(int n) {
	if (jeu->initNbJoueurs(n)) {
		jeu->setEtatCourant(DEPLACEMENT);
		return true;
	} else {
		return false;
	}
}

/*int Initialisation::lancerDe() {
	return 0;
}*/