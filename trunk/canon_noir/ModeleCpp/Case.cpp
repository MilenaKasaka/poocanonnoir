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