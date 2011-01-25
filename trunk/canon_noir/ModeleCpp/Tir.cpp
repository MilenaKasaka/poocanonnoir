/**
* \file Tir.cpp
* \brief Fichier definissant les fonctions de la classe Tir
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/
#include "Tir.h"
#include "Moteur.h"

using namespace std;

Tir::Tir(Moteur* m) : State(m) {
	direction.first = 0;
	direction.second = 0;
	angle = 0;
	puissance = 0;
	srand ( time(NULL) );
}

void Tir::gerer()
{
	int resLancer = rand() % 2;
	if(resLancer==1)
	{
		Joueur* j = joueurVise();
		j->recevoirTir();
		moteur->getJoueurCourant()->embarquerTresor();
		moteur->setResTir(true);
	}
	else
	{
		moteur->setResTir(false);
	}

	moteur->joueurSuivant();
	moteur->setEtatCourant(LANCER_DE);
}

void Tir::reglerTir(int p, int a, pair<int,int> c) {
	// FAIRE PLUTOT CES TESTS AU NIVEAU INTERFACE
	/*if (i < 0 || i >= HAUTEUR || j < 0 || j >= LARGEUR || 
		throw exception("coordonnees de la case visee incorrectes");
	if (puissance < 0 || puissance > PUISSANCEMAX)
		throw exeption("puissance incorrecte");
	if (angle < 0 || angle > ANGLEMAX)
		throw exeption("angle incorrect");*/
	direction = c;
	puissance = p;
	angle = a;
}

pair<int,int> Tir::tirer() {
	/*pair<int,int> impact = calculerTir();
	//gérer les conséquences du tir et le changement d'état ICI
	//recherche du joueur touché
	//changement de bateau, transfert du trésor
	//modification du joueur courant, changement d'état
	int bateauTrouve = -1;
	int i = 0;
	while (bateauTrouve == -1 && i < (moteur->getNbJoueurs())) {
		if (moteur->getJoueur(i)->getPosBateau() == impact) {
			bateauTrouve = i;
		}
		i++;
	}*/
	/*if (moteur->getJoueur(i)->recevoirTir()) {
		moteur->getJoueurCourant()->donnerSonTresor();
	}*/


	//gérer la situation où le bateau qui tire a déjà un trésor
	//imaginer une conception où l'échange de trésor se passe entièrement dans la classe joueur
	//return impact;
	return make_pair(0,0);
}

pair<int,int> Tir::calculerTir() { //to be completed
	pair<int,int> res;
	res.first = 0;
	res.second = 0;
	return res;
}

Joueur* Tir::joueurVise()
{
	for(int i=0; i<moteur->getNbJoueurs() ; i++)
	{
		Joueur* j = moteur->getJoueur(i);
		if (j->getPosBateau() == direction)
			return j;
	}
	return NULL;
}