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

/**
* \class Joueur
* \brief Represente un joueur
* Un joueur est caracterise par un port de départ, un ou deux bateaux et un nombre de tresors ramenés à son port
*/
class Joueur
{
	private :

		int nbTresorPort;  /*!< nombre de tresors ramenes au port */
		int bateauCourant; /*!< indice du bateau courant */
		vector<Bateau> bateaux; /*!< collection des bateaux appartenant au joueur */
		int numPort; /*!< numéro du port de départ du joueur */

	public :

		/**
		* \fn Joueur()
		* \brief Construit un objet Joueur en initialisant son nombre de trésors et son bateau courant à 0
		*/
		Joueur();

		/**
		* \fn void init_port(int port)
		* \brief Initialise le numéro de port du joueur
		* \param[in] port numéro de port du joueur
		*/
		void init_port(int port);

		/**
		* \fn void initBateaux(int nbJoueurs)
		* \brief Initialise le nombre de bateaux en fonction du nombre de joueurs :
		* 2 si le nombre de joueurs est de 2, 1 sinon
		* \param[in] nbJoueurs nombre de joueurs
		*/
		void initBateaux(int nbJoueurs);

		/**
		* \fn void setPosBateau(int x, int y)
		* \brief Permet de positionner le bateau courant du joueur
		* \param[in] x abscisse (unité = case) de la nouvelle position
		* \param[in] y ordonnée (unité = case) de la nouvelle position
		*/
		void setPosBateau(int x, int y);

		/**
		* \fn void embarquerTresor()
		* \brief Permet d'embarquer un trésor sur le bateau courant du joueur
		*/
		void embarquerTresor();

		/**
		* \fn void donnerSonTresor()
		* \brief Permet de donner le trésor embarqué dans le bateau courant du joueur
		*/
		void donnerSonTresor();

		/**
		* \fn int getNbBateaux() const
		* \brief Permet d'obtenir le nombre de bateaux du joueur :
		* 2 si le nombre de joueurs est de 2, 1 sinon
		* \return int - nombre de bateaux du joueur
		*/
		int getNbBateaux() const;

		/**
		* \fn TypeBateau getTypeBateau()
		* \brief Retourne le type du bateau courant (caravelle, frégate ou radeau)
		* \return TypeBateau - type du bateau courant
		*/
		TypeBateau getTypeBateau();

		/**
		* \fn pair<int,int> getPosBateau()
		* \brief Permet d'obtenir la position du bateau courant
		* \return coordonnées du bateau courant (unité = case)
		*/
		pair<int,int> getPosBateau();

		/**
		* \fn bool ramenerTresor()
		* \brief Permet de ramener un trésor au port
		* Incrémente le nombre de trésors au port et enlève le trésor porté par le bateau courant
		* \return bool - vrai si le joueur a gagné (nombre de trésors gagnant), faux sinon
		*/
		bool ramenerTresor();

		/**
		* \fn int getNbTresorPort() const
		* \brief Permet d'obtenir le nombre de trésors ramenés au port par le joueur
		* \return int - nombre de trésors ramenés au port par le joueur
		*/
		int getNbTresorPort() const;

		/**
		* \fn bool getTransporteTresor()
		* \brief Vérifie si le bateau courant du joueur transporte un trésor
		* \return bool - vrai si le bateau courant du joueur transporte un trésor, faux sinon
		*/
		bool getTransporteTresor();

		/**
		* \fn int getNumPort() const
		* \brief Permet d'obtenir le numéro du port du joueur
		* \return int - numéro du port du joueur
		*/
		int getNumPort() const;

		/**
		* \fn pair<int,int> getPosPort()
		* \brief Permet d'obtenir les coordonnées du port de départ du joueur
		* \return pair<int,int> - coordonnées du port de départ du joueur
		*/
		pair<int,int> getPosPort();

		/**
		* \fn void recevoirTir()
		* \brief Permet de répercuter les conséquences du tir sur le joueur
		* Retrograde le type de son bateau, donne son trésor et fait repartir le joueur du port de départ
		*/
		void recevoirTir();

}; 

inline int Joueur::getNbBateaux() const { return bateaux.size() ; }
inline TypeBateau Joueur::getTypeBateau() { return bateaux[bateauCourant].getType(); }
inline pair<int,int> Joueur::getPosBateau() { return bateaux[bateauCourant].getPosition(); }
inline int Joueur::getNbTresorPort() const { return nbTresorPort ; }
inline int Joueur::getNumPort() const { return numPort ; }
inline pair<int,int> Joueur::getPosPort() { return bateaux[bateauCourant].getPosPort(); }

#endif