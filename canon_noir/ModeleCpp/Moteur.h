#pragma once

#include <vector>

#include "enumerations.h"
#include "State.h"
#include "Map.h"
#include "Joueur.h"

using namespace std;

class Moteur
{
	private :

		int joueurCourant;
		int resLancerDe;
		State* etats;
		int etatCourant;
		bool initialise; 
		vector<pair<int,int> > casesAccessibles;

		// agregations
		Map map;
		vector<Joueur> joueurs;

	public :

		// Actions disponibles sur l'interface
		bool dispoLancerDe();
		bool dispoNbJoueurs();
		bool dispoChoixCouleur();
		bool dispoChoixCase();
		bool dispoReglageTir();

		void requete();
		void changerEtat(int etat);
		int getEtatCourant();
		void setLancerDe(int nb);
		int getLancerDe();
		Map getMap();
		vector<pair <int,int> > getCasesAccessibles();
		TypeBateau getTypeBateau();
		//TypeCase getTypeCase(int x, int y);

}; 
