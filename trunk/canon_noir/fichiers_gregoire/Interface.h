/*
 *  Interface.h
 *  Code
 *
 *  Created by Grégoire on 10/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INTERFACE
#define INTERFACE

#include "Jeu.h"
#include "Constantes.h"

#include <vector>
#include <utility>

using namespace std;

class Interface {
private:
	Jeu* jeu;
public:
	Interface();
	~Interface();
	
	bool initNbJoueurs(int n);

	TypeCase obtTypeCase(int i, int j);
	pair<int,int> obtDimPlateau();
	int obtNbTresorCase(int i, int j);
	int obtNbJoueurs();

	int obtJoueurCourant();
	int lanceDe();
	list<pair<int,int> > obtListeCasesAccessibles();
	bool deplacerBateau(int i, int j);

	pair<int,int> obtPosBateau(int joueur);
	int obtNbTrsorPort(int joueur);
	bool tresorBateau(int joueur);
	int obtGagnant();
};

#endif