/*
 *  Case.cpp
 *  Code
 *
 *  Created by Grégoire on 05/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Case.h"

Case::Case(TypeCase t, int nb) {
	type = t;
	nbTresor = nb;
}

TypeCase Case::obtType() {
	return type;
}

int Case::obtNbTresor() {
	return nbTresor;
}

bool Case::supprimerTresor() {
	if(nbTresor == 0) {
		return false;
	} else {
		nbTresor--;
		return true;
	}
}