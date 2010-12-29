#include "Joueur.h"

TypeBateau Joueur::getTypeBateau()
{
	return bateaux[bateauCourant].getType();
}

void Joueur::initBateaux(int nbJoueurs)
{
	if (nbJoueurs == 2)
		bateaux.resize(2);
	else
		bateaux.resize(1);
}