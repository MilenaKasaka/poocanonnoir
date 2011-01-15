#pragma once

#include "Moteur.h"

class State
{
	protected :
		Moteur* moteur;

	public :
		State(Moteur* m);
		virtual void gerer()=0;

}; 

