/*
 *  Tir.cpp
 *  Code
 *
 *  Created by Grégoire on 14/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Tir.h"
#include "Jeu.h"

using namespace std;

Tir::Tir(Jeu* j) : Etat(j) {
	direction.first = 0;
	direction.second = 0;
}

bool Tir::reglerDirectionTir(int i, int j) {
	if (i >= 1 &&
		i <= HAUTEUR &&
		j >= 1 &&
		j <= LARGEUR) {
		direction.first = i;
		direction.second = j;
		return true;
	} else {
		return false;
	}
}

bool Tir::reglerTir(int puissance, int angle) { //faire des contrôles
	if (puissance >= 1 &&
		puissance <= PUISSANCEMAX &&
		angle >= 1 &&
		angle <= ANGLEMAX) {
		p = puissance;
		a = angle;
		return true;
	} else {
		return false;
	}	
}

pair<int,int> Tir::tirer() {
	pair<int,int> impact = calculerTir();
	//gérer les conséquences du tir et le changement d'état ICI
	//recherche du joueur touché
	//changement de bateau, transfert du trésor
	//modification du joueur courant, changement d'état
	int bateauTrouve = -1;
	int i = 0;
	while (bateauTrouve == -1 && i < (jeu->obtNbJoueurs())) {
		if (jeu->obtJoueur(i)->obtPosition() == impact) {
			bateauTrouve = i;
		}
		i++;
	}
	if (jeu->obtJoueur(i)->recevoirTir()) {
		jeu->obtJoueurCourant()->mettreTresorBateau();
	}
	jeu->incrJoueurCourant();
	jeu->setEtatCourant(DEPLACEMENT);
	//gérer la situation où le bateau qui tire a déjà un trésor
	//imaginer une conception où l'échange de trésor se passe entièrement dans la classe joueur
	return impact;
}

pair<int,int> Tir::calculerTir() { //to be completed
	pair<int,int> res;
	res.first = 0;
	res.second = 0;
	return res;
}