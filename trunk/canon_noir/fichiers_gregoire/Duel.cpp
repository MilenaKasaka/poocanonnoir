/*
 *  Duel.cpp
 *  Code
 *
 *  Created by Grégoire on 14/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Duel.h"
#include "Jeu.h"

using namespace std;

Duel::Duel(Jeu* j) : Etat(j) {
	direction.first = 0;
	direction.second = 0;
	premierTir = true;
	adversaire = NULL;
}

bool reglerDirectionTir(int i, int j) {
}

bool reglerTir(int puissance, int angle) {
}

pair<int,int> tirer() {
}

pair<int,int> calculerTir() {
}