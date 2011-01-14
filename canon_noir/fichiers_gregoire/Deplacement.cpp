/*
 *  Deplacement.cpp
 *  Code
 *
 *  Created by Grégoire on 04/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Deplacement.h"
#include "Jeu.h"

/*Deplacement::Deplacement(Jeu* j) {
	jeu = j;
}*/

Deplacement::Deplacement(Jeu* j) : Etat(j) {
	resLancerDe = 0;
}

int Deplacement::lancerDe() {
	if (resLancerDe == 0) {
		resLancerDe = (int)((rand()%DE)+1);
	}	
	return resLancerDe;
}

bool Deplacement::casePraticable(int i, int j) {
	return (i >= 1 &&
		   i <= HAUTEUR &&
		   j >= 1 &&
		   j <= LARGEUR &&
		   jeu->obtCarte()->obtCase(i,j)->obtType() != ILE);
}	

bool Deplacement::caseAccessibleDe(int i, int j) {
	int ic = jeu->obtJoueurCourant()->obtPositionI();
	int jc = jeu->obtJoueurCourant()->obtPositionJ();
	return ((i == ic && ((j == jc + resLancerDe) || (j == jc - resLancerDe))) ||
			(j == jc && ((i == ic + resLancerDe) || (i == ic - resLancerDe))));
}

list<pair<int,int> > Deplacement::obtListeCasesAccessibles() {
	list<pair<int,int> > lr = list<pair<int,int> >(0);
	for (int i = 1; i<= HAUTEUR; i++) {
		for (int j = 1; j<= LARGEUR; j++) {
			if (caseAccessibleDe(i,j) && casePraticable(i,j)) {
				lr.push_front(pair<int,int>(i,j));
			}
		}
	}
	return lr;
}

bool Deplacement::deplBateau(int i, int j) {
	Joueur* jc = jeu->obtJoueurCourant();
	if (caseAccessibleDe(i,j) && casePraticable(i,j)) {
		jc->deplacer(i,j);
		//jeu->incrJoueurCourant();
		//un éventuel déchargement du trésor est fait dans la classe jeu
		if (!jc->tresorBateau()) {
			if (jeu->obtCarte()->obtCase(i,j)->supprimerTresor()) {
				jc->mettreTresorBateau();
			}
		}
		if (jc->aGagne()) {
			jeu->setEtatCourant(FIN);
		} else {
			if (jeu->obtCarte()->obtCase(jc->obtPosition())->obtType() == CANON) {
				jeu->setEtatCourant(TIR);
			} else {
				jeu->incrJoueurCourant();
			}
		}
		resLancerDe = 0;
		return true;
	} else {
		return false;
	}
}

/*bool execute() {
	lancerDe();
	
}*/