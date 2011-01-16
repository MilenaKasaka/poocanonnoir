#include "Moteur.h"

Moteur::Moteur()
{
	initEtats();
	setEtatCourant(ATTENTE_NB_JOUEURS);
}

void Moteur::initEtats()
{

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

int Moteur::getEtatCourant() {
	return etatCourant;
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

Map* Moteur::getMap()
{
	return &map;
}

bool Moteur::estAccessible(int x, int y)
{
	if (etatCourant != DEPLACEMENT_BATEAU) return false;
	pair<int,int> posBateau = getPosJoueurCourant();
	if(x >= LARGEUR || x < 0 || y >= HAUTEUR || y < 0) return false; 
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
