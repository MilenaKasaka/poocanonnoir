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
	getCase(2,2)->setType(ILE);
	getCase(2,3)->setType(ILE);
	getCase(2,4)->setType(ILE);
	getCase(2,5)->setType(ILE);
	getCase(3,2)->setType(ILE);
	getCase(3,3)->setType(ILE);
	getCase(3,4)->setType(ILE);
	getCase(3,5)->setType(ILE);

	getCase(7,2)->setType(ILE);
	getCase(7,3)->setType(ILE);
	getCase(7,4)->setType(ILE);
	getCase(7,5)->setType(ILE);
	getCase(8,2)->setType(ILE);
	getCase(8,3)->setType(ILE);
	getCase(8,4)->setType(ILE);
	getCase(8,5)->setType(ILE);

	getCase(4,2)->setType(TRESOR);
	getCase(4,5)->setType(TRESOR);
	getCase(6,3)->setType(TRESOR);
	getCase(6,6)->setType(TRESOR);
}

TypeCase Map::getTypeCase(int x, int y)
{
	/*if (x<0 || x>LARGEUR - 1 || y<0 || y>HAUTEUR-1)
		throw exception("Coordonnees incorrectes");*/
	vector<Case>::iterator it;
	it = find_if(cases.begin(),cases.end(),coo_find(make_pair(x,y)));
	if (it == cases.end()) // la case n'est pas trouvee
		return ILE;
	else
		return (*it).getType();
}

Case* Map::getCase(int x, int y)
{
	vector<Case>::iterator it;
	it = find_if(cases.begin(),cases.end(),coo_find(make_pair(x,y)));
	return &(*it);
}