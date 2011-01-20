/**
* \file Bateau.h
* \brief Fichier d'en-tete decrivant la classe Bateau
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/
#ifndef BATEAU_H
#define BATEAU_H

#include <utility>
#include "enumerations.h"

using namespace std;

/**
* \class Bateau
* \brief Representation d'un bateau
* Le bateau est defini par une position, un type et peut contenir un tresor
*/
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
