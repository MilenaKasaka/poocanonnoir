/**
* \file AttenteNbJoueurs.h
* \brief Fichier d'en-tete decrivant la classe AttenteNbJoueurs
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/
#ifndef ATTENTE_NB_JOUEURS_H
#define ATTENTE_NB_JOUEURS_H

#include "State.h"

/**
* \class AttenteNbJoueurs
* \brief Etat initial du moteur qui attend que l'utilisateur choisisse le nombre de joueurs.
*/
class AttenteNbJoueurs : public State
{
	public :
		/**
		* \fn AttenteNbJoueurs(Moteur* m)
		* \brief Construit un état AttenteNbJoueurs en lui passant l'instance de Moteur
		* \param[in] m instance de Moteur
		*/
		AttenteNbJoueurs(Moteur* m);

		/**
		* \fn gerer()
		* \brief Permet de gérer l'attente du choix du nombre de joueurs.
		* Dans cette version, cette méthode ne fait rien.
		*/
		void gerer();

};

#endif

