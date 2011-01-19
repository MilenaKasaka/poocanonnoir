#include "Moteur.h"

Moteur::Moteur() : joueurCourant(0), resLancerDe(make_pair(0,0)), etatCourant(ATTENTE_NB_JOUEURS), premierInit(false)
{
	initEtats();
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
		if (((*it).getCoordonnees().first == x) && ((*it).getCoordonnees().second == x))
			return true;
	}
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
