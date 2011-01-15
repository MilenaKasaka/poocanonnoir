#include "Bateau.h"

Bateau::Bateau()
{
	posX = 0;
	posY = 0;
	tresor = true;
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
		posX = LARGEUR;
		posY = 0;
		break;
	case 2:
		posX = LARGEUR;
		posY = HAUTEUR;
		break;
	case 3:
		posX = 0;
		posY = HAUTEUR;
		break;
	default:
		posX = 0;
		posY = 0;
		break;
	}
}

void Bateau::ajouterTresor(){
	tresor = true;
}

bool Bateau::enleverTresor()
{
	bool avaitTresor = tresor;
	tresor = false;
	return avaitTresor;
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