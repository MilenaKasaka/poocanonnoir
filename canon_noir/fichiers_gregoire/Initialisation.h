/*
 *  Initialisation.h
 *  Code
 *
 *  Created by Grégoire on 04/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Etat.h"


class Initialisation : public Etat {
public:
	bool initNbJoueurs(int n);
	//int lancerDe(); //sera pour l'initialisation
};