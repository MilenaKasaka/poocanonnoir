/*
 *  Jeu.cpp
 *  Code
 *
 *  Created by Grégoire on 04/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Jeu.h"

Jeu::Jeu() {
	vectE = vector<Etat*>(NBEJ);
	vectE[INITIALISATION] = new Initialisation(this);
	vectE[DEPLACEMENT] = new Deplacement(this);
	vectE[FIN] = new Fin(this);
	carte = new Carte();
	
	joueurCourant = 0;
	etatCourant = 0;
}

Jeu::~Jeu() {
	for (int i = 0; i<vectE.size(); i++) delete vectE[i];
	for (int i = 0; i<vectJ.size(); i++) delete vectJ[i];
	delete carte;
}

bool Jeu::initNbJoueurs(int n) {
	if (n>NB_JOUEURS_MAX || n<1) {
		return false;
	}
	else {
		vectJ = vector<Joueur*>(n);
		for (int i = 0; i<n; i++) vectJ[i] = new Joueur(i);
		return true;
	}
}

void Jeu::incrJoueurCourant() {
	joueurCourant = (joueurCourant + 1) % obtNbJoueurs();
}

void Jeu::setEtatCourant(int e) {
	etatCourant = e;
}

Etat* Jeu::obtEtat(int i) {
	return vectE[i];
}

Etat* Jeu::obtEtatCourant() {
	return vectE[etatCourant];
}

Carte* Jeu::obtCarte() {
	return carte;
}

Joueur* Jeu::obtJoueur(int i) {
	return vectJ[i];
}

Joueur* Jeu::obtJoueurCourant() {
	return vectJ[joueurCourant];
}

int Jeu::obtNbJoueurs() {
	return vectJ.size();
}

int Jeu::obtIndJoueurCourant() {
	return joueurCourant;
}
