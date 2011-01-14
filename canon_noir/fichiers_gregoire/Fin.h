 /*
 *  Fin.h
 *  Code
 *
 *  Created by Grégoire on 04/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef FI
#define FI

#include "Etat.h"

class Fin : public Etat {
public:
	Fin(Jeu* j);
	int obtGagnant();
};

#endif