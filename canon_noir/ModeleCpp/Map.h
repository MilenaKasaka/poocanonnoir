/**
* \file Map.h
* \brief Fichier d'en-tete decrivant la classe Map
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/
#ifndef MAP_H
#define MAP_H

/// <remarks>Les cases sont stockées dans un vecteur à 2 dimensions</remarks>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Case.h"
#include "enumerations.h"

using namespace std;

/**
* \class Map
* \brief Contient l'ensemble des cases, permet d'effectuer des opérations sur ces cases et d'y accéder
*/
class Map
{
	private :
		vector<Case> cases; /*!< Liste des cases du plateau */


	public :
		/**
		* \fn Map()
		* \brief Construit le plateau du jeu.
		* Initialise la largeur, la hauteur et les différents types de cases
		*/
		Map();

		/**
		* \fn vector<Case>* getCases()
		* \brief Permet d'obtenir la liste des cases du plateau
		* \return vector<Case>* - pointeur vers la liste des cases du plateau
		*/
		vector<Case>* getCases();

		/**
		* \fn Case* getCase(int x, int y)
		* \brief Permet d'obtenir la case dont les coordonnées sont passées en paramètre
		* \param[in] x abscisse de la case
		* \param[in] y ordonnée de la case
		* \return Case* - pointeur vers la case dont les coordonnées sont passées en paramètre
		*/
		Case* getCase(int x, int y);

		/**
		* \fn TypeCase getTypeCase(int x, int y)
		* \brief Permet d'obtenir le type de la case dont les coordonnées sont passées en paramètre
		* \param[in] x abscisse de la case
		* \param[in] y ordonnée de la case
		* \return TypeCase - type de la case dont les coordonnées sont passées en paramètre
		*/
		TypeCase getTypeCase(int x, int y);
};

inline vector<Case>* Map::getCases() { return &cases; }

/**
* \class coo_find
* \brief Foncteur pour retrouver une case grace à ses coordonnées
*/
class coo_find { // objet fonction de type prédicat
pair<int,int> coo;
public:
coo_find(pair<int,int> c) {coo=c;};
bool operator()(Case c) { return c.getCoordonnees() == coo; }
};

#endif
