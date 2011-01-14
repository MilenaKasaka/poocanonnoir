/*
 *  Etat.h
 *  Code
 *
 *  Created by Grégoire on 04/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef ETAT
#define ETAT
#include <vector>
#include <list>
#include <utility>

//#include "Jeu.h" // problème d'insertion circulaire
#include "Constantes.h"
class Jeu;

using namespace std;

class Etat {
protected:
	Jeu* jeu;
public:
	Etat();
	Etat(Jeu* j);
	virtual bool initNbJoueurs(int n);
	virtual int lancerDe();
	virtual list<pair<int,int> > obtListeCasesAccessibles();
	virtual bool deplacerBateau(int i, int j);
	virtual int obtGagnant();
	//virtual bool execute();
	
	virtual bool reglerDirectionTir(int i, int j);
	virtual bool reglerTir(int puissance, int angle);
	virtual pair<int,int> tirer();
	virtual pair<int,int> calculerTir();
	
};

#endif