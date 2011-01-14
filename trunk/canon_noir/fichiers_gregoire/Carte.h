/*
 *  Carte.h
 *  Code
 *
 *  Created by Grégoire on 05/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef CARTE
#define CARTE

#include <iostream>
#include <vector>
#include <utility>

#include "Case.h"
#include "Constantes.h"

using namespace std;

class Carte {
private:
	vector<vector<Case*> > listeCases;
public:
	Carte();
	~Carte();
	Case* obtCase(int i, int j);
	Case* obtCase(pair<int,int> p);
};

#endif