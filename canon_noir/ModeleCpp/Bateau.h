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

#include <iostream>
#include <utility>
#include "enumerations.h"

using namespace std;

/**
* \class Bateau
* \brief Representation d'un bateau.
* Le bateau est defini par une position, un type, un port de depart et peut contenir un tresor.
*/
class Bateau
{
	private :

		int posX; /*!< abscisse du bateau (unité = case) */
		int posY; /*!< ordonnée du bateau (unité = case) */
		bool tresor; /*!< vrai si le bateau transporte un dé trésor */
		TypeBateau type; /*!< type du bateau (caravelle, frégate ou radeau) */
		pair<int,int> posPort; /*!< Coordonnées du port de départ */

	public :
		/**
		* \fn Bateau()
		* \brief Construit un objet Bateau
		*/
		Bateau();

		/**
		* \fn void init_port(int port)
		* \brief Initialise le port du bateau en fonction du joueur auquel il appartient
		* \param[in] port numero du port
		*/
		void init_port(int port);

		/**
		* \fn void ajouterTresor()
		* \brief Change l'état d'un bateau pour lui faire transporter un trésor
		*/
		void ajouterTresor();

		/**
		* \fn void enleverTresor()
		* \brief Change l'état d'un bateau pour lui enlever le trésor qu'il transporte
		*/
		void enleverTresor();

		/**
		* \fn void setPosition(int x, int y)
		* \brief Déplacer le bateau à la position de coordonnées (x,y)
		* \param[in] x abscisse de la nouvelle position (unité = case)
		* \param[in] y ordonnée de la nouvelle position (unité = case)
		*/
		void setPosition(int x, int y);

		/**
		* \fn TypeBateau getType()
		* \brief Permet d'obtenir le type du bateau (caravelle, frégate ou radeau)
		* \return type du bateau
		*/
		TypeBateau getType();

		/**
		* \fn void setType(TypeBateau t)
		* \brief Permet de changer le type du bateau (caravelle, frégate ou radeau)
		* \param[in] t nouveau type du bateau
		*/
		void setType(TypeBateau t);

		/**
		* \fn void retrograderType()
		* \brief Permet à la suite d'un tir, de passer à la catégorie inférieure de bateau
		*/
		void retrograderType();

		/**
		* \fn pair<int,int> getPosition()
		* \brief Permet d'obtenir la position du bateau
		* \return coordonnées du bateau (unité=case)
		*/
		pair<int,int> getPosition();

		/**
		* \fn pair<int,int> getPosPort()
		* \brief Permet d'obtenir la position du port de départ
		* \return coordonnées du port (unité=case)
		*/
		pair<int,int> getPosPort();

		/**
		* \fn bool getTransporteTresor() const
		* \brief Permet de savoir si le bateau transporte ou non un trésor
		* \return vrai si le bateau transporte un trésor, faux sinon
		*/
		bool getTransporteTresor() const;

}; 

// TESTER LE PORT
inline pair<int,int> Bateau::getPosPort() { return posPort; }
inline bool Bateau::getTransporteTresor() const { return tresor; }

#endif
