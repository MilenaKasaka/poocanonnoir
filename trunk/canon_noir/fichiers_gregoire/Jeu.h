/*
 *  Jeu.h
 *  Code
 *
 *  Created by Grégoire on 04/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef JEU
#define JEU
#include<iostream>
#include<vector>

#include "Joueur.h"
#include "Etat.h"
#include "Carte.h"

using namespace std;

class Jeu {
private:
	vector<Joueur*> vectJ;
	vector<Etat*> vectE;
	int joueurCourant;
	int etatCourant;
	Carte* carte;
	
public:
	Jeu();
	bool initNbJoueurs(int n);
	void incrJoueurCourant();
	void setEtatCourant(int etat);
	Etat* obtEtat(int i);
	Etat* obtEtatCourant();
	Carte* obtCarte();
	Joueur* obtJoueur(int i);
	Joueur* obtJoueurCourant();
	int obtIndJoueurCourant();
};

#endif
	

