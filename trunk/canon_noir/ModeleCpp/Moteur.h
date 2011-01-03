#pragma once

#include <vector>

#include "enumerations.h"
#include "State.h"
#include <utility>
#include "Map.h"
#include "Joueur.h"

using namespace std;

class Moteur
{
	private :

		int joueurCourant;
		pair<int,int> resLancerDe;
		State* etats;
		int etatCourant;
		bool initialise; 
		vector<pair<int,int> > casesAccessibles;

		// agregations
		Map map;
		vector<Joueur> joueurs;

	public :

		Moteur();
		void initMoteur();

		// Actions disponibles sur l'interface
		bool dispoLancerDe();
		bool dispoNbJoueurs();
		bool dispoChoixCouleur();
		bool dispoChoixCase();
		bool dispoReglageTir();

		void requete();
		void changerEtat(int etat);
		int getEtatCourant();
		void setLancerDe(pair<int,int> lance);
		pair<int,int> getLancerDe();
		int getNbJoueurs();
		// Initialise le vecteur des joueurs
		void initJoueurs(int size);
		Map getMap();
		// Prend en compte l'état du moteur
		bool estAccessible(int x, int y);
		TypeBateau getTypeBateau();
		pair<int,int> getPosJoueurCourant();
		//TypeCase getTypeCase(int x, int y);

}; 
