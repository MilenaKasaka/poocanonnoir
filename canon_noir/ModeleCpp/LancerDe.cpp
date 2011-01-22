/**
* \file LancerDe.cpp
* \brief Fichier definissant les fonctions de la classe LancerDe
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/
#include "LancerDe.h"
#include "Moteur.h"

LancerDe::LancerDe(Moteur* m) : State(m), cptJoueur(0)
{
	srand ( time(NULL) );
	tabScores.resize(moteur->getNbJoueurs());
}

void LancerDe::gerer()
{
	if (moteur->getPremierInit())
	{
		if (moteur->getChoixPremier())
			moteur->choixPremierFini();
		tirerDes();
		moteur->setEtatCourant(DEPLACEMENT_BATEAU);
	}
	else
	{
		selectionPremierJoueur();
	}
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
}

void LancerDe::selectionPremierJoueur()
{
	tirerDes();
	pair<int,int> lancerDe = moteur->getLancerDe();
	int sommeDes = lancerDe.first + lancerDe.second;
	tabScores.push_back(sommeDes);
	cptJoueur++;
	if (cptJoueur == moteur->getNbJoueurs())
	{
		int maxScore = 0;
		int premJoueur = 0;
		for (int i=0; i<tabScores.size(); i++)
		{
			if (tabScores[i] > maxScore)
			{
				maxScore = tabScores[i];
				premJoueur = i;
			}
		}
		moteur->setPremierInit();
		moteur->setNumJoueurCourant(premJoueur);
	}
	else
	{
		moteur->joueurSuivant();
	}

}