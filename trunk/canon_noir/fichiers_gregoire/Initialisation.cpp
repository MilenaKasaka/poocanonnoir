/*
 *  Initialisation.cpp
 *  Code
 *
 *  Created by Grégoire on 04/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Initialisation.h"
#include "Jeu.h"

bool Initialisation::initNbJoueurs(int n) {
	jeu->initNbJoueurs(n);
	return true;
}

/*int Initialisation::lancerDe() {
	return 0;
}*/