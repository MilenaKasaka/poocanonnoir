#include "Tir.h"

using namespace std;

Tir::Tir(Moteur* m) : State(m) {
	direction.first = 0;
	direction.second = 0;
	angle = 0;
	puissance = 0;
}

void Tir::gerer()
{
}

bool Tir::reglerTir(int i, int j, pair<int,int> c) {
	if (i >= 1 &&
		i <= HAUTEUR &&
		j >= 1 &&
		j <= LARGEUR) {
		direction.first = i;
		direction.second = j;
		return true;
	} else {
		return false;
	}
}

bool Tir::reglerTir(int p, int a) { //faire des contrôles
	if (puissance >= 1 &&
		puissance <= PUISSANCEMAX &&
		angle >= 1 &&
		angle <= ANGLEMAX) {
		puissance = p;
		angle = a;
		return true;
	} else {
		return false;
	}	
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
	}
	if (moteur->getJoueur(i)->recevoirTir()) {
		moteur->getJoueurCourant()->donnerSonTresor();
	}
	moteur->joueurSuivant();
	moteur->setEtatCourant(DEPLACEMENT_BATEAU);
	//gérer la situation où le bateau qui tire a déjà un trésor
	//imaginer une conception où l'échange de trésor se passe entièrement dans la classe joueur
	return impact;*/
	return make_pair(0,0);
}

pair<int,int> Tir::calculerTir() { //to be completed
	pair<int,int> res;
	res.first = 0;
	res.second = 0;
	return res;
}