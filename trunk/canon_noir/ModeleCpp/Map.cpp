/**
* \file Map.cpp
* \brief Fichier definissant les fonctions de la classe Map
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/
#include "Map.h"

Map::Map()
{
	cases.resize(HAUTEUR*LARGEUR);
	int cptLarg = 0;
	int cptHaut = 0;
	vector<Case>::iterator it;
	for (it = cases.begin() ; it!=cases.end(), cptHaut<HAUTEUR; it++)
	{
		(*it).setCoordonnees(make_pair(cptLarg,cptHaut));
		if (cptLarg < LARGEUR - 1)
			cptLarg++;
		else // derniere case de la ligne
		{
			cptLarg = 0;
			cptHaut++;
		}		
	}
	cases[2,2].setType(ILE);
	cases[2,3].setType(ILE);
	cases[2,4].setType(ILE);
	cases[3,2].setType(ILE);
	cases[3,3].setType(ILE);
	cases[3,4].setType(ILE);

	cases[7,2].setType(ILE);
	cases[7,3].setType(ILE);
	cases[7,4].setType(ILE);
	cases[8,2].setType(ILE);
	cases[8,3].setType(ILE);
	cases[8,4].setType(ILE);
}

TypeCase Map::getTypeCase(int x, int y)
{
	if (x<0 || x>LARGEUR - 1 || y<0 || y>HAUTEUR-1)
		throw exception("Coordonnees incorrectes");
	vector<Case>::iterator it;
	it = find_if(cases.begin(),cases.end(),coo_find(make_pair(x,y)));
	if (it == cases.end()) // la case n'est pas trouvee
		return ILE;
	else
		return (*it).getType();
}