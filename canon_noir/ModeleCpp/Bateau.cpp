#include "Bateau.h"

Bateau::Bateau()
{
	posX = 0;
	posY = 0;
	nbTresor = 0;
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
		posX = LARGEUR_PLATEAU;
		posY = 0;
		break;
	case 2:
		posX = LARGEUR_PLATEAU;
		posY = HAUTEUR_PLATEAU;
		break;
	case 3:
		posX = 0;
		posY = HAUTEUR_PLATEAU;
		break;
	default:
		posX = 0;
		posY = 0;
		break;
	}
}

void Bateau::ajouterTresor(){
	nbTresor++;
}

void Bateau::enleverTresor()
{
	nbTresor--;
}

void Bateau::changerPosition(int x, int y)
{
	posX = x;
	posY = y;
}

TypeBateau Bateau::getType()
{
	return type;
}

pair<int,int> Bateau::getPosition()
{
	return make_pair(posX,posY);
}