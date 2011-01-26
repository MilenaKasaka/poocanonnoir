/**
* \file DeplacementBateau.h
* \brief Fichier d'en-tete decrivant la classe DeplacementBateau
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/
#ifndef DEPLACEMENT_BATEAU_H
#define DEPLACEMENT_BATEAU_H

#include <vector>
#include "State.h"
#include "Case.h"

using namespace std;

/**
* \class DeplacementBateau
* \brief Etat qui affiche les cases accessibles pour le joueur et attend que celui-ci choisisse le déplacement de son bateau
* Calcule les cases accessibles en fonction du résultat du lancer de dé
*/
class DeplacementBateau : public State
{
	private :

		/**
		* \fn bool caseBonneDistance(pair<int,int> cooCase)
		* \brief Vérifie que la case est a la bonne distance par rapport au joueur
		* \param[in] cooCase coordonnées de la case dont on veut vérifier qu'elle est à la bonne distance par rapport au joueur
		* \return vrai si la case est a la bonne distance par rapport au joueur, faux sinon
		*/
		bool caseBonneDistance(pair<int,int> cooCase);

		/**
		* \fn vector<Case> casesAccessibles()
		* \brief retourne la liste des cases accessibles au joueur en fonction de son bateau et de son lancer de des
		* \return liste des cases accessibles au joueur
		*/
		vector<Case> casesAccessibles();

	public :
		/**
		* \fn DeplacementBateau(Moteur* m)
		* \brief Construit un état DeplacementBateau en lui passant l'instance de Moteur
		* \param[in] m instance de Moteur
		*/
		DeplacementBateau(Moteur* m);

		/**
		* \fn void gerer()
		* \brief Transmet au moteur les cases accessibles à l'utilisateur
		*/
		void gerer();

};

#endif

