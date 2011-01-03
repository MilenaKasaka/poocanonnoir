#include <vector>
#include <iostream>
#include <utility>
#include "Bateau.h"

using namespace std;

class Joueur
{
	private :

		int nbTresorPort;
		int bateauCourant;
		vector<Bateau> bateaux;

	public :
		TypeBateau getTypeBateau();

		/*
		Initialise le nombre de bateaux en fonction du nombre de joueurs :
		2 si le nombre de joueurs est de 2
		1 sinon
		*/
		void initBateaux(int nbJoueurs);

		pair<int,int> getPosBateau();

}; 

