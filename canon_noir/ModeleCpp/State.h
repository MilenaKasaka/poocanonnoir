#ifndef STATE_H
#define STATE_H

class Moteur;

class State
{
	protected :
		Moteur* moteur;

	public :
		State(Moteur* m);
		virtual void gerer()=0;

}; 

#endif
