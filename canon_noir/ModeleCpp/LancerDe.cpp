#include "LancerDe.h"

LancerDe::LancerDe(Moteur* m) : State(m)
{
	srand ( time(NULL) );
}

void LancerDe::gerer()
{
	tirerDes();
}

void LancerDe::tirerDes()
{
	/*int lancer1 = rand() % 6 + 1;
	if(moteur->getNbJoueurs()  == 2)
	{
		int lasncer2 = rand() % 6 + 1;
		moteur->setLancerDe(make_pair(lancer1,lancer2));
	}
	else
	{
		moteur->setLancerDe(make_pair(lancer1,0));
	}*/
}