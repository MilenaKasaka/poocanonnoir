#include "LancerDe.h"

LancerDe::LancerDe(Moteur* m)
{
	srand ( time(NULL) );
	moteur = m;
}

void LancerDe::gerer()
{
	tirerDes();
}

void LancerDe::tirerDes()
{
	int lancer1 = rand() % 6 + 1;
	if(moteur->getNbJoueurs()  == 2)
	{
		int lancer2 = rand() % 6 + 1;
		moteur->setLancerDe(make_pair(lancer1,lancer2));
	}
	else
	{
		moteur->setLancerDe(make_pair(lancer1,0));
	}
}