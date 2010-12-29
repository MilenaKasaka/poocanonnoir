/*
 *  Jeu.cpp
 *  Code
 *
 *  Created by Grégoire on 04/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Jeu.h"

bool Jeu::initNbJoueurs(int n) {
	if (n>NB_JOUEURS_MAX) {
		return false;
	}
	else {
		
	}
}

Carte* Jeu::obtCarte() {
	return carte;
}

Joueur* Jeu::obtJoueurCourant() {
	return vectJ[joueurCourant];
}
int Jeu::obtIndJoueurCourant() {
	return 0;
}
