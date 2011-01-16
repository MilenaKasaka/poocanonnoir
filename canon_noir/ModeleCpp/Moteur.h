#ifndef MOTEUR_H
#define MOTEUR_H

#include <vector>
#include <utility>

#include "enumerations.h"
#include "Map.h"
#include "Joueur.h"
#include "AttenteNbJoueurs.h"
#include "ChoixCouleur.h"
#include "LancerDe.h"
#include "DeplacementBateau.h"
#include "TirCaseCanon.h"
#include "TirBordure.h"

using namespace std;

class Moteur
{
	private :

		int joueurCourant;
		pair<int,int> resLancerDe;
		vector<State* > etats;
		int etatCourant;
		bool initialise; 
		vector<pair<int,int> > casesAccessibles;
		Map map;
		vector<Joueur> joueurs;

		void initEtats();

	public :

		Moteur();

		// Actions disponibles sur l'interface
		bool dispoLancerDe();
		bool dispoNbJoueurs();
		bool dispoChoixCouleur();
		bool dispoChoixCase();
		bool dispoReglageTir();

		void requete();

		void setEtatCourant(int etat);
		int getEtatCourant();

		// DES
		void setLancerDe(pair<int,int> lance);
		pair<int,int> getLancerDe();

		// JOUEURS
		int getNbJoueurs();
		// Initialise le vecteur des joueurs
		void initJoueurs(int size);
		Joueur* getJoueur(int i);
		Joueur* getJoueurCourant();
		void joueurSuivant();

		// MAP
		Map* getMap();
		// Prend en compte l'état du moteur
		bool estAccessible(int x, int y);
		TypeBateau getTypeBateau();
		pair<int,int> getPosJoueurCourant();
		//TypeCase getTypeCase(int x, int y);
};

/*inline pair<int,int> Moteur::getLancerDe() const { return resLancerDe; }
inline int Moteur::getEtatCourant() const { return etatCourant; }*/

#endif