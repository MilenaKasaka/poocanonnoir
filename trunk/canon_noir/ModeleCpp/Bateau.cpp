/**
* \file Bateau.cpp
* \brief Fichier definissant les fonctions de la classe Bateau
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/
#include "Bateau.h"

Bateau::Bateau()
{
	posX = 0;
	posY = 0;
	tresor = false;
	type = CARAVELLE;
}

void Bateau::init_port(int port)
{
	switch (port)
	{
	case 0:
		posX = 0;
		posY = 0;
		break;
	case 1:
		posX = LARGEUR-1;
		posY = 0;
		break;
	case 2:
		posX = LARGEUR-1;
		posY = HAUTEUR-1;
		break;
	case 3:
		posX = 0;
		posY = HAUTEUR-1;
		break;
	default:
		posX = 0;
		posY = 0;
		break;
		posPort = make_pair(posX,posY);
	}
	//cout << "Port " << port << " : bateau initialise a la position (" << posX << "," << posY << ")" <<endl; 
}

void Bateau::ajouterTresor()
{
	tresor = true;
}

void Bateau::enleverTresor()
{
	tresor = false;
}

void Bateau::setPosition(int x, int y)
{
	posX = x;
	posY = y;
}

TypeBateau Bateau::getType()
{
	return type;
}

void Bateau::setType(TypeBateau t)
{
	type = t;
}

void Bateau::retrograderType()
{
	if (type == FREGATE) type = RADEAU;
	else if (type == CARAVELLE) type = FREGATE;
}

pair<int,int> Bateau::getPosition()
{
	return make_pair(posX,posY);
}