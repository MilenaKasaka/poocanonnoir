/*
 *  Case.h
 *  Code
 *
 *  Created by Grégoire on 05/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef CASE
#define CASE
#include "Constantes.h";
class Case {
private:
	TypeCase type;
	int nbTresor; //invariant !
public:
	Case(TypeCase t, int nb);
	TypeCase obtType();
	int obtNbTresor();
	bool supprimerTresor();
};

#endif