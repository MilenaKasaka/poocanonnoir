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

pair<int,int> Joueur::getPosBateau()
{
	return bateaux[bateauCourant].getPosition();
}

void Joueur::setPosBateau(int x, int y)
{
	bateaux[bateauCourant].setPosition(x,y);
}

bool donnerSonTresor()
{
	bateaux[bateauCourant].setPosition(x,y);
}

bool Joueur::recevoirTir()
{
	bateaux[bateauCourant].retrograderType();
	return false;
}


