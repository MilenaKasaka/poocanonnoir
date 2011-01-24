/**
* \file Case.cpp
* \brief Fichier definissant les fonctions de la classe Case
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/
#include "Case.h"


Case::Case() : type(EAU) , nbTresor(0), altitude(0)
{
}

Case::Case(TypeCase t, int n) : type(t) , nbTresor(n)
{
	if (t == TRESOR)
		nbTresor = 4;
}

TypeCase Case::getType()
{
	return type;
}

void Case::setType(TypeCase t)
{
	type = t;
	if (t == TRESOR)
		nbTresor = 4;
}

int Case::getNbTresor()
{
	return nbTresor;
}

void Case::setNbTresor(int n)
{
	nbTresor = n;
}

bool Case::prendreTresor()
{
	if(nbTresor > 0)
	{
		nbTresor--;
		return true;
	}
	else
		return false;
}

void Case::setCoordonnees(pair<int,int> c)
{
	coordonnees = c;
}