/*
 *  Joueur.cpp
 *  Code
 *
 *  Created by Grégoire on 05/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Joueur.h"

using namespace std;

Joueur::Joueur(int pos) : type(CARAVELLE), tresorSurBateau(false), nbTresorPort(0) {
	initPosition(pos);
}

void Joueur::initPosition(int pos) {
	switch (pos) {
		case 0:
			positionInit.first = 1;
			positionInit.second = 1;
			break;
		case 1:
			positionInit.first = 1;
			positionInit.second = HAUTEUR;
			break;
		case 2:
			positionInit.first = LARGEUR;
			positionInit.second = HAUTEUR;
			break;
		case 3:
			positionInit.first = LARGEUR;
			positionInit.second = 1;
			break;
	}
	position = positionInit;
}

void Joueur::deplacer(int i, int j) {
	position.first = i;
	position.second = j;
	
	if (position == positionInit) {
		dechargerTresor();
		type = CARAVELLE;
	}
	//dechargerTresor();
}

int Joueur::obtPositionI() {
	return position.first;
}

int Joueur::obtPositionJ() {
	return position.second;
}

pair<int,int> Joueur::obtPosition() {
	return position;
}

bool Joueur::mettreTresorBateau() {
	if(tresorBateau() || type == RADEAU) {
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
/*
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
*/
bool Joueur::dechargerTresor() {
	if (enleverTresorBateau()) {
		nbTresorPort++;
		return true;
	} else {
		return false;
	}
}

int Joueur::obtNbTresorPort() {
	return nbTresorPort;
}

bool Joueur::recevoirTir() {
	//gérer la reception du tir (changement de bateau)
	if (type != RADEAU) type = (TypeBateau)((int)(type)-1);
	//indiquer si il y avait un trésor sur le bateau, et l'enlever le cas échéant
	return enleverTresorBateau();
}

bool Joueur::aGagne() {
	return obtNbTresorPort() >= 3;
}