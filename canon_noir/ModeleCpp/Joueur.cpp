#include <iostream>
#include "Joueur.h"

using namespace std;

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
	cout << "initBateaux pour " << nbJoueurs << " joueurs" << endl;
}