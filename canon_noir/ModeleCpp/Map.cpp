#include "Map.h"

Map::Map()
{
	cases = vector<vector<Case> >(HAUTEUR);
	for (int i = 0; i<HAUTEUR; i++) {
		cases[i].resize(LARGEUR);
		for (int j = 0; j<LARGEUR; j++) {
			cases[i][j].setType(EAU);
			cases[i][j].setNbTresor(0);
		}
	}
}

TypeCase Map::getTypeCase(int x, int y)
{
	return EAU;
}