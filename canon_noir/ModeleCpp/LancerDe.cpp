#include "LancerDe.h"
#include "Moteur.h"

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
	// ERREUR A L_EXECUTION ICI
	int lancer1 = rand() % 6 + 1;
	if(moteur->getJoueurCourant()->getTypeBateau() == CARAVELLE)
	{
		int lancer2 = rand() % 6 + 1;
		moteur->setLancerDe(make_pair(lancer1,lancer2));
	}
	else
	{
		moteur->setLancerDe(make_pair(lancer1,0));
	}
	
	if (moteur->getPremierInit())
		moteur->setEtatCourant(DEPLACEMENT_BATEAU);
	else
		moteur->setPremierInit();
}