﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Changes to this file will be lost if the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------
#include <utility>
#include "enumerations.h"

using namespace std;

class Bateau
{
	private :

		int posX;
		int posY;
		bool tresor;
		TypeBateau type;

	public :
		Bateau();
		void init_port(int port);
		void ajouterTresor();
		bool enleverTresor();
		void setPosition(int x, int y);
		TypeBateau getType();
		void setType(TypeBateau t);
		void retrograderType();
		pair<int,int> getPosition();

}; 
