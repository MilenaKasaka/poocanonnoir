﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Changes to this file will be lost if the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

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

	public :

		void prendreTresor();
		Case(TypeCase t, int n);
		TypeCase getType();
		void setType(TypeCase t);
		int getNbTresor();
		void setNbTresor(int n);

}; 
