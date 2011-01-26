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
* \brief Etat correspondant au choix de la couleur de son port par chacun des joueurs
* (PAS UTILISE DANS CETTE VERSION DU JEU)
*/
class ChoixCouleur : public State
{
public:
	/**
	* \fn ChoixCouleur(Moteur* m)
	* \brief Construit un �tat ChoixCouleur en lui passant l'instance de Moteur
	* \param[in] m instance de Moteur
	*/
	ChoixCouleur(Moteur* m);

	/**
	* \fn ~ChoixCouleur()
	* \brief Permet de d�truire un objet ChoixCouleur
	*/
	~ChoixCouleur();

	/**
	* \fn void gerer()
	* \brief Permet de g�rer le choix de la couleur du port pour chacun des joueurs
	* (NE FAIT RIEN DANS CETTE VERSION DU JEU)
	*/
	void gerer();
};

#endif

