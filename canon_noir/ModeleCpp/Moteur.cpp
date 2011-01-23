/**
* \file Moteur.cpp
* \brief Fichier definissant les fonctions de la classe Moteur
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/
#include "Moteur.h"

Moteur::Moteur() : joueurCourant(0), resLancerDe(make_pair(0,0)), etatCourant(ATTENTE_NB_JOUEURS), premierInit(false), choixPremier(false)
{
	initEtats();
}

Moteur::~Moteur()
{
	vector<State*>::iterator it;
	for(it=etats.begin() ; it!=etats.end(); it++){
		delete (*it);
	}
}

void Moteur::initEtats()
{
	etats.resize(NB_ETATS);
	etats[ATTENTE_NB_JOUEURS] = new AttenteNbJoueurs(this);
	etats[CHOIX_COULEUR] = new AttenteNbJoueurs(this);
	etats[LANCER_DE] = new LancerDe(this);
	etats[DEPLACEMENT_BATEAU] = new DeplacementBateau(this);
	etats[TIR_CASE_CANON] = new TirCaseCanon(this);
	etats[TIR_BORDURE] = new TirBordure(this);
}

void Moteur::initPorts()
{
	int i=0;
	vector<Joueur>::iterator it;
	for(it = joueurs.begin() ; it!=joueurs.end(); it++)
	{
		(*it).init_port(i);
		i++;
	}	
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
	etats[etatCourant]->gerer();
}

void Moteur::setEtatCourant(int etat)
{
	etatCourant = etat;
}

void Moteur::setLancerDe(pair<int,int> lancer)
{
	resLancerDe = lancer;
}

void Moteur::setPremierInit()
{
	premierInit = true;
	choixPremier = true;
}

void Moteur::choixPremierFini()
{
	choixPremier = false;
}

int Moteur::getNbJoueurs()
{
	return joueurs.size();
}

void Moteur::initJoueurs(int size)
{
	joueurs.resize(size);
	initPorts();
	for (int i=0 ; i<size ; i++)
	{
		joueurs[i].initBateaux(size);
	}
	this->setEtatCourant(LANCER_DE);
}

Joueur* Moteur::getJoueur(int i)
{
	return (&joueurs[i]);
}

Joueur* Moteur::getJoueurCourant()
{
	return (&joueurs[joueurCourant]);
}

int Moteur::getNumJoueurCourant()
{
	return joueurCourant;
}

void Moteur::setNumJoueurCourant(int i)
{
	joueurCourant = i;
}

void Moteur::joueurSuivant()
{
	joueurCourant = (joueurCourant + 1) % joueurs.size();
}

vector<pair<int,int> > Moteur::getCooBateaux()
{
	vector<pair<int,int> > coo;
	vector<Joueur>::iterator it;
	for (it = joueurs.begin() ; it!=joueurs.end(); it++)
	{
		coo.push_back((*it).getPosBateau());
	}
	return coo;
}

int Moteur::getNbTresors(int joueur)
{
	return joueurs[joueur].getNbTresorPort();
}

Map* Moteur::getMap()
{
	return &map;
}

void Moteur::setCasesAccessibles(vector<Case> ca)
{
	casesAccessibles = ca;
}

bool Moteur::estAccessible(int x, int y)
{
	vector<Case>::iterator it;
	/*for (it = casesAccessibles.begin() ; it!=casesAccessibles.end(); it++)
	{
		if (((*it). == x) && ((*it).second == y))
			return true;
	}*/
	for (it = casesAccessibles.begin() ; it!=casesAccessibles.end(); it++)
	{
		if (((*it).getCoordonnees().first == x) && ((*it).getCoordonnees().second == y))
			return true;
	}
	return false;
}

TypeBateau Moteur::getTypeBateau()
{
	return joueurs[joueurCourant].getTypeBateau();
}

TypeBateau Moteur::getTypeBateau(int joueur)
{
	return joueurs[joueur].getTypeBateau();
}

pair<int,int> Moteur::getPosJoueurCourant()
{
	return joueurs[joueurCourant].getPosBateau();
}

pair<int,int> Moteur::getPosJoueur(int i)
{
	return joueurs[i].getPosBateau();
}

TypeCase Moteur::getTypeCase(int x, int y)
{
	return map.getTypeCase(x,y);
}

bool Moteur::contientBateau(Case c)
{
	vector<Joueur>::iterator it;
	for (it = joueurs.begin() ; it!=joueurs.end(); it++)
	{
		/*if ( ((*it).getPosBateau().first == x) || ((*it).getPosBateau().second == y) )
			return true;*/
		if ( (*it).getPosBateau() == c.getCoordonnees() )
			return true;
	}
	return false;
}
