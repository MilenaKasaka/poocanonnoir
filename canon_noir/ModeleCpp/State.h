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
