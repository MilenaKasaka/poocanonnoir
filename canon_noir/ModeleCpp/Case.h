/**
* \file Case.h
* \brief Fichier d'en-tete decrivant la classe Case
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/
#ifndef CASE_H
#define CASE_H

/// <remarks>
/// si type = TRESOR alors nbTresor>=0,
/// sinon nbTresor = 0
/// </remarks>
#include <utility>
#include "enumerations.h"

using namespace std;

/**
* \class Case
* \brief Representation d'une case
* Une case est définie par une position, une altitude, un type et peut contenir un tresor
*/
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
