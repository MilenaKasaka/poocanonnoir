#ifndef CASE_H
#define CASE_H

/// <remarks>
/// si type = TRESOR alors nbTresor>=0,
/// sinon nbTresor = 0
/// </remarks>
#include "enumerations.h"

class Case
{
	private :

		int nbTresor;
		TypeCase type;
		// rajouter un attribut pour la hauteur

	public :
		Case();
		void prendreTresor();
		Case(TypeCase t, int n);
		TypeCase getType();
		void setType(TypeCase t);
		int getNbTresor();
		void setNbTresor(int n);

}; 

#endif
