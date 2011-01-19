#ifndef CASE_H
#define CASE_H

/// <remarks>
/// si type = TRESOR alors nbTresor>=0,
/// sinon nbTresor = 0
/// </remarks>
#include <utility>
#include "enumerations.h"

using namespace std;

class Case
{
	private :

		int nbTresor;
		TypeCase type;
		int altitude;
		pair<int,int> coordonnees;

	public :
		Case();
		void prendreTresor();
		Case(TypeCase t, int n);
		TypeCase getType();
		void setType(TypeCase t);
		int getNbTresor();
		void setNbTresor(int n);
		pair<int,int> getCoordonnees() const;
		void setCoordonnees(pair<int,int> c);
};

inline pair<int,int> Case::getCoordonnees() const { return coordonnees; }

#endif
