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
	private :

	public :
		AttenteNbJoueurs(Moteur* m);
		void gerer();

};

#endif

