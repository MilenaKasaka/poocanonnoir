#ifndef CHOIX_COULEUR_H
#define CHOIX_COULEUR_H

#include "State.h"

class ChoixCouleur : public State
{
public:
	ChoixCouleur(Moteur* m);
	~ChoixCouleur();
	void gerer();
};

#endif

