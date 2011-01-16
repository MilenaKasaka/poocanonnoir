#ifndef BATEAU_H
#define BATEAU_H

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
		void enleverTresor();
		void setPosition(int x, int y);
		TypeBateau getType();
		void setType(TypeBateau t);
		void retrograderType();
		pair<int,int> getPosition();

}; 

#endif
