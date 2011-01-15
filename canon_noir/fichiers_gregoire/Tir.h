/*
 *  Tir.h
 *  Code
 *
 *  Created by GrÃ©goire on 14/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef TI
#define TI

#include "Etat.h"

#include <utility>

using namespace std;

class Tir : public Etat {
private:
	pair<int,int> direction;
	int puissance;
	int angle; // angle

public:
	Tir(Jeu* j);
	bool reglerDirectionTir(int i, int j);
	bool reglerTir(int p, int a);
	pair<int,int> tirer(); // retourne l'impact du tir
	pair<int,int> calculerTir(); // calcule la portée du tir
};

#endif