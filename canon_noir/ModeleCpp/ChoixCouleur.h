/**
* \file ChoixCouleur.h
* \brief Fichier d'en-tete decrivant la classe ChoixCouleur
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/
#ifndef CHOIX_COULEUR_H
#define CHOIX_COULEUR_H

#include "State.h"

/**
* \class ChoixCouleur
* \brief Etat qui correspond a l'attente du choix de la couleur pour chaque joueur
*/
class ChoixCouleur : public State
{
public:
	ChoixCouleur(Moteur* m);
	~ChoixCouleur();
	void gerer();
};

#endif

