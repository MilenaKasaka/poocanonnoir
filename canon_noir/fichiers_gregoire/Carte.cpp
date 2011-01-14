/*
 *  Carte.cpp
 *  Code
 *
 *  Created by Grégoire on 05/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Carte.h"
//#include "Constantes.h"

Carte::Carte() {
	listeCases = vector<vector<Case*> >(HAUTEUR);
	for (int i = 0; i<HAUTEUR; i++) {
		listeCases[i].resize(LARGEUR);
		for (int j = 0; j<LARGEUR; j++) {
			listeCases[i][j] = new Case(EAU,0);
		}
	}
}

Carte::~Carte() {
	for (int i = 0; i<HAUTEUR; i++) {
		listeCases[i].resize(LARGEUR);
		for (int j = 0; j<LARGEUR; j++) {
			delete listeCases[i][j];
		}
	}
	
}

Case* Carte::obtCase(int i, int j) {
	return listeCases[i][j];
}

Case* Carte::obtCase(pair<int,int> p) {
	return listeCases[p.first][p.second];
}