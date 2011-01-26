/**
* \file Case.h
* \brief Fichier d'en-tete decrivant la classe Case
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/
#ifndef CASE_H
#define CASE_H

/// <remarks>
/// si type = TRESOR alors nbTresor>=0,
/// sinon nbTresor = 0
/// </remarks>
#include <utility>
#include "enumerations.h"

using namespace std;

/**
* \class Case
* \brief Representation d'une case
* Une case est définie par une position, une altitude, un type et peut contenir un tresor
*/
class Case
{
	private :
		int nbTresor; /*!< nombre de trésors restants sur la case, initialisé à 0 pour les cases qui ne sont pas de type trésor */
		TypeCase type; /*!< type de la case (eau, ile, canon ou tresor) */
		int altitude; /*!< altitude de la case, pas prise en compte dans cette version du jeu */
		pair<int,int> coordonnees; /*!< coordonnées de la case sur le plateau */

	public :
		/**
		* \fn Case()
		* \brief Construit une case avec comme type par défaut le type eau et aucun trésor
		*/
		Case();

		/**
		* \fn Case(TypeCase t, int n)
		* \brief Construit un case en lui passant son type et son nombre de trésors
		* \param[in] t type de la case (eau, ile, canon ou tresor)
		* \param[in] n nombre de trésors contenu par la case
		*/
		Case(TypeCase t, int n);

		/**
		* \fn TypeCase getType()
		* \brief Permet d'obtenir le type de la case (eau, ile, canon ou tresor)
		* \return type de la case
		*/
		TypeCase getType();

		/**
		* \fn void setType(TypeCase t)
		* \brief Permet de changer le type de la case
		* \param[in] t nouveau type de la case (eau, ile, canon ou tresor)
		*/
		void setType(TypeCase t);
		
		/**
		* \fn int getNbTresor()
		* \brief Permet d'obtenir le nombre de trésors restant sur la case
		* \return nombre de trésors restant sur la case
		*/
		int getNbTresor();

		/**
		* \fn void setNbTresor(int n)
		* \brief Permet de changer le nombre de trésors contenu par la case
		* \param[in] n nouveau nombre de trésors
		*/
		void setNbTresor(int n);

		/**
		* \fn bool prendreTresor()
		* \brief Permet de prendre un trésor sur la case
		* \return vrai si la case contenait un trésor, faux sinon
		*/
		bool prendreTresor();

		/**
		* \fn pair<int,int> getCoordonnees() const
		* \brief Permet d'obtenir les coordonnées de la case
		* \return coordonnées de la case sur le plateau
		*/
		pair<int,int> getCoordonnees() const;

		/**
		* \fn void setCoordonnees(pair<int,int> c)
		* \brief Permet de changer les coordonnées de la case
		* \param[in] c nouvelles coordonnées de la case sur le plateau
		*/
		void setCoordonnees(pair<int,int> c);
};

inline pair<int,int> Case::getCoordonnees() const { return coordonnees; }

#endif
