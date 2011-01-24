/**
* \file Joueur.h
* \brief Fichier d'en-tete decrivant la classe Joueur
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/
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
		int numPort;

	public :
		Joueur();

		void init_port(int port);
		/*
		Initialise le nombre de bateaux en fonction du nombre de joueurs :
		2 si le nombre de joueurs est de 2
		1 sinon
		*/
		void initBateaux(int nbJoueurs);		
		void setPosBateau(int x, int y);
		void embarquerTresor();
		void donnerSonTresor();
		int getNbBateaux() const;
		// Retourne le type du bateau courant
		TypeBateau getTypeBateau();
		pair<int,int> getPosBateau();

		bool ramenerTresor(); // retourne vrai si le joueur a gagne
		int getNbTresorPort() const;
		int getNumPort() const;
		pair<int,int> getPosPort();

		void recevoirTir();

}; 

inline int Joueur::getNbBateaux() const { return bateaux.size() ; }
inline TypeBateau Joueur::getTypeBateau() { return bateaux[bateauCourant].getType(); }
inline pair<int,int> Joueur::getPosBateau() { return bateaux[bateauCourant].getPosition(); }
inline int Joueur::getNbTresorPort() const { return nbTresorPort ; }
inline int Joueur::getNumPort() const { return numPort ; }
inline pair<int,int> Joueur::getPosPort() { return bateaux[bateauCourant].getPosPort(); }

#endif