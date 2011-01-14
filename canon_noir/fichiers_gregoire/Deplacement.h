/*
 *  Deplacement.h
 *  Code
 *
 *  Created by Grégoire on 04/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef DEPL
#define DEPL

#include <utility>

#include "Etat.h"

using namespace std;

class Deplacement : public Etat {
private:
	int resLancerDe;
public:
	Deplacement(Jeu* j);
	int lancerDe();
	bool casePraticable(int i, int j);
	bool caseAccessibleDe(int i, int j);
	list<pair<int,int> > obtListeCasesAccessibles();
	bool deplBateau(int i, int j);
	//bool execute();
};

#endif