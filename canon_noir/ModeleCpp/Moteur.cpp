#include "Moteur.h"

Moteur::Moteur()
{
}

void Moteur::initMoteur()
{
	this->changerEtat(ATTENTE_NB_JOUEURS);
}

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
	etats[etatCourant].gerer();
}

void Moteur::changerEtat(int etat)
{
}

int Moteur::getEtatCourant()
{
	return 0;
}

void Moteur::setLancerDe(pair<int,int> lancer)
{
	resLancerDe = lancer;
}

pair<int,int> Moteur::getLancerDe()
{
	return resLancerDe;
}

int Moteur::getNbJoueurs()
{
	return joueurs.size();
}

void Moteur::initJoueurs(int size)
{
	/*joueurs.resize(size);
	for (int i=0 ; i<size ; i++)
	{
		joueurs[i].initBateaux(size);
	}*/
	//cout << "Initialisation à " << size << " joueurs" <<endl;
	this->changerEtat(LANCER_DE);
}

Map Moteur::getMap()
{
	return map;
}

bool Moteur::estAccessible(int x, int y)
{
	if (etatCourant != DEPLACEMENT_BATEAU) return false;
	pair<x,y> posBateau = getPosJoueurCourant();
	if(x >= LARGEUR_PLATEAU || x < 0 || y >= LARGEUR_PLATEAU || y < 0) return false; 
	return false;
}

TypeBateau Moteur::getTypeBateau()
{
	return joueurs[joueurCourant].getTypeBateau();
}

pair<int,int> Moteur::getPosJoueurCourant()
{
	return joueurs[joueurCourant].getPosBateau();
}

/*TypeCase Moteur::getTypeCase(int x, int y)
{
	return map.getTypeCase(x,y);
}*/
