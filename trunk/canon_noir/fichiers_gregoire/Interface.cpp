/*
 *  Interface.cpp
 *  Code
 *
 *  Created by Grégoire on 10/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Interface.h"

Interface::Interface() {
	jeu = new Jeu();
}

Interface::~Interface() {
	delete jeu;
}

bool Interface::initNbJoueurs(int n) {
	return jeu->obtEtatCourant()->initNbJoueurs(n);
}

TypeCase Interface::obtTypeCase(int i, int j) {
	return jeu->obtCarte()->obtCase(i,j)->obtType();
}

int Interface::obtNbTresorCase(int i, int j) {
	return jeu->obtCarte()->obtCase(i,j)->obtNbTresor();
}

int Interface::obtNbJoueurs() {
	return jeu->obtNbJoueurs();
}

int Interface::obtJoueurCourant() {
	return jeu->obtIndJoueurCourant();
}

int Interface::lanceDe() {
	return jeu->obtEtatCourant()->lancerDe();
}

list<pair<int,int> > Interface::obtListeCasesAccessibles() {
	return jeu->obtEtatCourant()->obtListeCasesAccessibles();
}

bool Interface::deplacerBateau(int i, int j) {
	return jeu->obtEtatCourant()->deplacerBateau(i,j);
}

pair<int,int> Interface::obtPosBateau(int joueur) {
	return jeu->obtJoueur(joueur)->obtPosition();
}

bool Interface::tresorBateau(int joueur) {
	return jeu->obtJoueur(joueur)->tresorBateau();
}