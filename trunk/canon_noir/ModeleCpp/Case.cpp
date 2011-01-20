/**
* \file Case.cpp
* \brief Fichier definissant les fonctions de la classe Case
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/
#include "Case.h"

void Case::prendreTresor()
{
}

Case::Case() : type(EAU) , nbTresor(0), altitude(0)
{
}

Case::Case(TypeCase t, int n) : type(t) , nbTresor(n)
{
}

TypeCase Case::getType()
{
	return EAU;
}

void Case::setType(TypeCase t)
{
	type = t;
}

int Case::getNbTresor()
{
	return nbTresor;
}

void Case::setNbTresor(int n)
{
	nbTresor = n;
}

void Case::setCoordonnees(pair<int,int> c)
{
	coordonnees = c;
}