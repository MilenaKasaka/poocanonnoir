#include "Moteur.h"

bool Moteur::dispoLancerDe()
{
	return (etatCourant == LANCER_DE);
}

bool Moteur::dispoNbJoueurs()
{
	return (etatCourant == ATTENTE_NB_JOUEURS);
}

bool Moteur::dispoChoixCouleur()
{
	return (etatCourant == CHOIX_COULEUR);
}

bool Moteur::dispoChoixCase()
{
	return (etatCourant == DEPLACEMENT_BATEAU);
}

bool Moteur::dispoReglageTir()
{
	return ((etatCourant ==  TIR_CASE_CANON) || (etatCourant == TIR_BORDURE));
}

void Moteur::requete()
{
}

void Moteur::changerEtat(int etat)
{
}

int Moteur::getEtatCourant()
{
	return 0;
}

void Moteur::setLancerDe(int nb)
{
}

int Moteur::getLancerDe()
{
	return 0;
}

int Moteur::getNbJoueurs()
{
	return joueurs.size();
}

void Moteur::initJoueurs(int size)
{
	joueurs.resize(size);
	for (int i=0 ; i<size ; i++)
	{
		joueurs[i].initBateaux(size);
	}
	//cout << "Initialisation à " << size << " joueurs" <<endl;
}

Map Moteur::getMap()
{
	return map;
}

vector<pair <int,int> > Moteur::getCasesAccessibles()
{
	return casesAccessibles;
}

TypeBateau Moteur::getTypeBateau()
{
	return joueurs[joueurCourant].getTypeBateau();
}

/*TypeCase Moteur::getTypeCase(int x, int y)
{
	return map.getTypeCase(x,y);
}*/
