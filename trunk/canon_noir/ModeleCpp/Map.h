/**
* \file Map.h
* \brief Fichier d'en-tete decrivant la classe Map
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/
#ifndef MAP_H
#define MAP_H

/// <remarks>Les cases sont stockées dans un vecteur à 2 dimensions</remarks>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Case.h"
#include "enumerations.h"

using namespace std;

/**
* \class Map
* \brief Contient l'ensemble des cases, permet d'effectuer des opérations sur ces cases et d'y accéder
*/
class Map
{
	private :
		vector<Case> cases;


	public :
		Map();
		vector<Case>* getCases();
		Case* getCase(int x, int y);
		TypeCase getTypeCase(int x, int y);
		// Retourne la liste des cases sur lesquelles il y a un bateau
};

inline vector<Case>* Map::getCases() { return &cases; }

class coo_find { // objet fonction de type prédicat
pair<int,int> coo;
public:
coo_find(pair<int,int> c) {coo=c;};
bool operator()(Case c) { return c.getCoordonnees() == coo; }
};

#endif
