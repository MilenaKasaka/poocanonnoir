#ifndef DEPLACEMENT_BATEAU_H
#define DEPLACEMENT_BATEAU_H

#include "State.h"

class DeplacementBateau : public State
{

	public :

		DeplacementBateau(Moteur* m);
		void gerer();

};

#endif

