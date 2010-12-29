/*
 *  Joueur.cpp
 *  Code
 *
 *  Created by Grégoire on 05/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Joueur.h"
#include "Constantes.h"

using namespace std;

Joueur::Joueur(int pos) : typeBateau(CARAVELLE), tresorSurBateau(false), nbTresorPort(0) {
	initPosition(pos);
}

void Joueur::initPosition(int pos) {
	switch (pos) {
		case 1:
			positionInit.first = 1;
			positionInit.second = 1;
			break;
		case 2:
			positionInit.first = 1;
			positionInit.second = HAUTEUR;
			break;
		case 3:
			positionInit.first = LARGEUR;
			positionInit.second = HAUTEUR;
			break;
		case 4:
			positionInit.first = LARGEUR;
			positionInit.second = 1;
			break;
	}
	position = positionInit;
}

void Joueur::deplacer(int i, int j) {
	position.first = i;
	position.second = j;
}

int Joueur::obtPositionI() {
	return position.first;
}

int Joueur::obtPositionJ() {
	return position.second;
}

bool Joueur::mettreTresorBateau() {
	if(tresorBateau()) {
		return false;
	} else {
		tresorSurBateau = true;
		return true;
	}
}

bool Joueur::tresorBateau() {
	return tresorSurBateau;
}

bool Joueur::enleverTresorBateau() {
	if(tresorBateau()) {
		tresorSurBateau = false;
		return true;
	} else {
		return false;
	}
}

bool Joueur::dechargerTresor() {
	if(!(tresorBateau() || position == positionInit)) {
		return false;
	}
	else {
		nbTresorPort++;
		enleverTresorBateau();
		return true;
	}
}

int Joueur::obtNbTresorPort() {
	return nbTresorPort;
}

bool Joueur::aGagne() {
	return obtNbTresorPort() >= 3;
}