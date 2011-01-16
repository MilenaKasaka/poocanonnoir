#ifndef ATTENTE_NB_JOUEURS_H
#define ATTENTE_NB_JOUEURS_H

#include "State.h"
class AttenteNbJoueurs : public State
{
	private :

	public :
		AttenteNbJoueurs(Moteur* m);
		void gerer();

};

#endif

