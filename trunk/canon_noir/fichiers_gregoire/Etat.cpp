/*
 *  Etat.cpp
 *  Code
 *
 *  Created by Grégoire on 09/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#include "Etat.h"

Etat::Etat() {
}

Etat::Etat(Jeu* j) : jeu(j) {
}

bool Etat::initNbJoueurs(int n) {
	return false;
}

int Etat::lancerDe() {
	return 0;
}

list<pair<int,int> > Etat::obtListeCasesAccessibles() {
	return list<pair<int,int> >(0);
}

bool Etat::deplacerBateau(int i, int j) {
	return false;
}

int Etat::obtGagnant() {
	return 0;
}

bool Etat::reglerDirectionTir(int i, int j) {
	return false;
}

bool Etat::reglerTir(int puissance, int angle) {
	return false;
}

pair<int,int> Etat::tirer() {
	pair<int,int> res;
	res.first = res.second = -1; //verifier indexation
	return res;
}

pair<int,int> Etat::calculerTir() {
	pair<int,int> res;
	res.first = res.second = -1; //verifier indexation
	return res;
}
