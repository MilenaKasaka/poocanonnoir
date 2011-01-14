/*
 *  Duel.h
 *  Code
 *
 *  Created by Grégoire on 14/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef DU
#define DU

#include "Etat.h"

#include <utility>

using namespace std;

class Duel : public Etat {
private:
private:
	pair<int,int> direction;
	int p;
	int a;
	bool premierTir;
	Joueur* adversaire;
public:
	Duel(Jeu* j);
	bool reglerDirectionTir(int i, int j);
	bool reglerTir(int puissance, int angle);
	pair<int,int> tirer();
	pair<int,int> calculerTir();	
};


#endif