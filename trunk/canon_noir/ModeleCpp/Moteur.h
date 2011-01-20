/**
* \file Moteur.h
* \brief Fichier d'en-tete decrivant la classe Moteur
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/
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
		bool premierInit; // permet de différencier le lancer permettant de selectionner le 1er joueur
		vector<Case> casesAccessibles;
		Map map;
		vector<Joueur> joueurs;

		void initEtats();

	public :

		Moteur();
		~Moteur();

		// Actions disponibles sur l'interface
		bool dispoLancerDe();
		bool dispoNbJoueurs();
		bool dispoChoixCouleur();
		bool dispoChoixCase();
		bool dispoReglageTir();

		void requete();

		void setEtatCourant(int etat);
		int getEtatCourant() const;

		// DES
		void setLancerDe(pair<int,int> lance);
		pair<int,int> getLancerDe() const;
		void setPremierInit();
		bool getPremierInit() const;

		// JOUEURS
		int getNbJoueurs();
		// Initialise le vecteur des joueurs
		void initJoueurs(int size);
		Joueur* getJoueur(int i);
		Joueur* getJoueurCourant();
		void joueurSuivant();
		vector<pair<int,int> > getCooBateaux();

		// MAP
		Map* getMap();
		// Prend en compte l'état du moteur
		void setCasesAccessibles(vector<Case> ca);
		bool estAccessible(int x, int y);
		TypeBateau getTypeBateau(); // retourne le type de bateau du joueur courant
		TypeBateau getTypeBateau(int joueur);
		pair<int,int> getPosJoueurCourant();
		TypeCase getTypeCase(int x, int y);
		bool contientBateau(Case c); // retourne vrai si la case contient un bateau
};

inline int Moteur::getEtatCourant() const { return etatCourant; }
inline pair<int,int> Moteur::getLancerDe() const { return resLancerDe; }
inline bool Moteur::getPremierInit() const { return premierInit; }

#endif