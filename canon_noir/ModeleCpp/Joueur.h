#ifndef JOUEUR_H
#define JOUEUR_H

#include <vector>
#include <iostream>
#include <utility>
#include "Bateau.h"

using namespace std;

class Joueur
{
	private :

		int nbTresorPort; // nombre de tresors ramenes au port
		int bateauCourant;
		vector<Bateau> bateaux;

	public :
		Joueur();
		/*
		Initialise le nombre de bateaux en fonction du nombre de joueurs :
		2 si le nombre de joueurs est de 2
		1 sinon
		*/
		void initBateaux(int nbJoueurs);		
		void setPosBateau(int x, int y);
		void donnerSonTresor();
		int getNbBateaux() const;
		// Retourne le type du bateau courant
		TypeBateau getTypeBateau();
		pair<int,int> getPosBateau();

		int getNbTresorPort() const;

		void recevoirTir();

}; 

inline int Joueur::getNbBateaux() const { return bateaux.size() ; }
inline TypeBateau Joueur::getTypeBateau() { return bateaux[bateauCourant].getType(); }
inline pair<int,int> Joueur::getPosBateau() { return bateaux[bateauCourant].getPosition(); }
inline int Joueur::getNbTresorPort() const { return nbTresorPort ; }

#endif