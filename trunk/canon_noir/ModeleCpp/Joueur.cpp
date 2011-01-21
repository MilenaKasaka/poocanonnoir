/**
* \file Joueur.cpp
* \brief Fichier definissant les fonctions de la classe Joueur
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/
#include "Joueur.h"

using namespace std;

Joueur::Joueur() : nbTresorPort(0), bateauCourant(0)
{
}

void Joueur::init_port(int port)
{
	numPort = port;
}

void Joueur::initBateaux(int nbJoueurs)
{
	if (nbJoueurs == 2)
		bateaux.resize(2);
	else
		bateaux.resize(1);
	vector<Bateau>::iterator it;
	for(it = bateaux.begin() ; it!=bateaux.end() ; it++)
	{
		(*it).init_port(numPort);
	}
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


