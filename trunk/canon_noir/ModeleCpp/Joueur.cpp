#include "Joueur.h"

using namespace std;

Joueur::Joueur() : nbTresorPort(0), bateauCourant(0)
{
}

void Joueur::initBateaux(int nbJoueurs)
{
	if (nbJoueurs == 2)
		bateaux.resize(2);
	else
		bateaux.resize(1);
	//cout << "Chaque joueur a bien " << getNbBateaux() << " bateaux" << endl;
}

void Joueur::setPosBateau(int x, int y)
{
	bateaux[bateauCourant].setPosition(x,y);
}

void Joueur::donnerSonTresor()
{
	bateaux[bateauCourant].enleverTresor();
}

void Joueur::recevoirTir()
{
	bateaux[bateauCourant].retrograderType();
}

