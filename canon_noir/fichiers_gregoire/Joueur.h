/*
 *  Joueur.h
 *  Code
 *
 *  Created by Grégoire on 05/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
#include<utility>
using namespace std;

class Joueur {
private:
	pair<int,int> position;
	pair<int,int> positionInit;//invariant !
	int typeBateau;
	bool tresorSurBateau;
	int nbTresorPort;//invariant !
public:
	Joueur(int pos);
	
	void initPosition(int pos);
	void deplacer(int i, int j);
	int obtPositionI();
	int obtPositionJ();
	
	bool mettreTresorBateau();
	bool tresorBateau();
	bool enleverTresorBateau();
	
	bool dechargerTresor();
	int obtNbTresorPort();
	
	bool aGagne();
};