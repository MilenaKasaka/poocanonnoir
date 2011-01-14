/*
 *  Initialisation.h
 *  Code
 *
 *  Created by Grégoire on 04/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INIT
#define INIT

#include<ctime>

#include "Etat.h"
#include "Jeu.h"


class Initialisation : public Etat {
public:
	Initialisation(Jeu* j);
	bool initNbJoueurs(int n);
	//int lancerDe(); //sera pour l'initialisation
};

#endif
