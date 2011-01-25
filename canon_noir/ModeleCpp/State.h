/**
* \file State.h
* \brief Fichier d'en-tete decrivant la classe State
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/
#ifndef STATE_H
#define STATE_H

class Moteur;

/**
* \class State
* \brief Classe abstraite qui définit un état du jeu
* Chaque état possède une référence vers l'objet Moteur et peut ainsi y accéder et le modifier
*/
class State
{
	protected :
		Moteur* moteur;

	public :
		State(Moteur* m);
		~State();
		virtual void gerer()=0;

}; 

#endif
