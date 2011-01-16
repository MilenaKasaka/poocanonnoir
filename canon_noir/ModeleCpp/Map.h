#ifndef MAP_H
#define MAP_H

/// <remarks>Les cases sont stockées dans un vecteur à 2 dimensions</remarks>
#include <vector>
#include "Case.h"
#include "enumerations.h"

using namespace std;

class Map
{
	private :
		vector<vector<Case> > cases;


	public :
		Map();
		Case* getCase(int x, int y);
		TypeCase getTypeCase(int x, int y);

}; 

#endif
