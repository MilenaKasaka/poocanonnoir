/**
* \file LancerDe.h
* \brief Fichier d'en-tete decrivant la classe LancerDe
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/
#ifndef LANCER_DE_H
#define LANCER_DE_H

#include <vector>
#include <time.h>
#include <utility>
#include "State.h"

using namespace std;

/**
* \class LancerDe
* \brief Etat chargé du tirage aléatoire du résultat du lancer de dés
*/
class LancerDe : public State
{

	private :
		int cptJoueur; /*!< indice du joueur qui lance le de pour tenter de jouer le premier */
		vector<int> tabScores; /*!< tableau des lancers de des pour la selection du premier joueur */
		
		/**
		* \fn void tirerDes()
		* \brief Effectue le lancer de dé en faisant un tirage aléatoire.
		* Gère le type du bateau pour savoir si on a le droit à 1 ou 2 dés.
		* Si on le droit à un seul dé, l'autre dé est initialisé à 0
		*/
		void tirerDes();

		/**
		* \fn prototype de la fonction
		* \brief Gère les scores de lancers de dés des joueurs afin de désigner le joueur qui va commencer
		*/
		void selectionPremierJoueur();

	public :
		/**
		* \fn LancerDe(Moteur* m)
		* \brief Construit un état LancerDe en lui passant l'instance de Moteur.
		* Initialise le tableau des scores.
		* \param[in] m instance de Moteur
		*/
		LancerDe(Moteur* m);

		/**
		* \fn void gerer()
		* \brief Appele le lancer de dé et si besoin la sélection du premier joueur
		* Met à jour l'objet Moteur en fonction du résultat
		*/
		void gerer();
}; 

#endif

