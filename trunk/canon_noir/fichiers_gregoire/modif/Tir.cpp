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
}

void Tir::gerer()
{
}

void Tir::reglerTir(int p, int a, pair<int,int> c) {
	// FAIRE PLUTOT CES TESTS AU NIVEAU INTERFACE
	/*if (i < 0 || i >= HAUTEUR || j < 0 || j >= LARGEUR || 
		throw exception("coordonnees de la case visee incorrectes");
	if (puissance < 0 || puissance > PUISSANCEMAX)
		throw exeption("puissance incorrecte");
	if (angle < 0 || angle > ANGLEMAX)
		throw exeption("angle incorrect");*/
	posTireur = moteur->getJoueurCourant()->getPosBateau();
	direction = c;
	puissance = p;
	angle = a;
}

pair<int,int> Tir::tirer() {
	pair<int,int> impact = calculerTir();
	//gérer les conséquences du tir et le changement d'état ICI	
	//recherche du joueur touché
	//changement de bateau, transfert du trésor
	//modification du joueur courant, changement d'état
	if(impact.first != -1) {
		int bateauTrouve = -1;
		int i = 0;
		while (bateauTrouve == -1 && i < (moteur->getNbJoueurs())) {
			if (moteur->getJoueur(i)->getPosBateau() == impact) {
				bateauTrouve = i;
			}
			i++;
		}
		/*if (moteur->getJoueur(i)->recevoirTir()) {
			moteur->getJoueurCourant()->donnerSonTresor();
		}*/
	}
	moteur->joueurSuivant();
	moteur->setEtatCourant(DEPLACEMENT_BATEAU);
	//gérer la situation où le bateau qui tire a déjà un trésor
	//imaginer une conception où l'échange de trésor se passe entièrement dans la classe joueur
	return impact;
	//return make_pair(0,0);
}

pair<int,int> Tir::calculerTir() { //to be completed
// faire la liste des cases traversées
// pour chaque case traversée, comparer la hauteur du boulet à l'altitude de la case
// déterminer alors sur quelle case le boulet arrive

	list<pair<double,double> > intersections;
	list<pair<double,double> > histogramme;
	liste<pair<int,int> > casesTraversees;
	list<pair<double,double> >::iterator it, end;
	list<pair<int,int> >::iterator it2;
	double h, l, xa, ya, xb, yb;
	unsigned int x, y, i, j;
	int x, y, i, j;
	int inc_x, inc_y;
	
	x1 = posTireur.first - 1/2;
	y1 = posTireur.second - 1/2;
	
	x2 = direction.first - 1/2;
	y2 = direction.second - 1/2;
	
	if(x1<x2) {
		inc_x = 1;
		x = ((unsigned int) x1) +1;
	} else {
		inc_x = -1;
		x = (unsigned int) x1;
	}
	
	if(y1<y2) {
		inc_y = 1;
		y = ((unsigned int) y1) + 1;
	} else {
		inc_y = -1;
		y = (unsigned int) y1;
	}
	
	while (x * inc_x < x2 * inc_x && y * inc_y < y2 * inc_y) {
		if(this->f(x) == y) {
			intersections.push_back(pair<double, double>(x, y));
			x += inc_x;
			y += inc_y;
		} else if(this->f(x) * inc_y < y * inc_y) {
			intersections.push_back(pair<double, double>(x, this->f(x)));
			x += inc_x;
		} else {
			intersections.push_back(pair<double, double>(this->g(x), y));
			y += inc_y;
		}
	}
	
	if (intersection.size() >= 1) {
		xb = x1;
		yb = y1;
		
		intersection.push_back(x2,y2);
		
		it = intersection.begin();
		end = intersection.end();
		
		for (; it != end; ++it) {
			xa = xb;
			ya = yb;
			xb = it->first;
			yb = it->second;
			
			i = (unsigned int) min(xa, xb) + 1;
			j = (unsigned int) min(ya, yb) + 1;
			
			h = moteur->getMap()->getCase(i,j)->getAltitude();
			l = sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya));
			histogramme.push_back(pair(<double,double>(l,h));
			casesTraversees.push_back(pair<int,int>(i,j));
		}
	}
	
	/*list<pair<double,double> > hauteurBoulet;
	//remplir hauteurBoulet et comparer à chaque fois la hauteur du boulet avec l'altitude de la case
	*/
	bool collision = false;
	pair<int,int> res;
	
	if(histogramme.size() > 1) {
		it = histogramme.begin();
		end = histogramme.end();
		it2 = casesTraversees.begin();
		
		h = it->second;
		d = it->first;
		it++;
		
		for(; it != end && !collision; it++, it2++) {
			if(this->z(d) || this->z(d) <= it->second) {
				collision = true;
				res = *it2;
			}
			d += it->first;
		}
		
	}	
	
	if(!collision) {
		res.first = -1;
		res.second = -1;
	}
	return res;
}

double Tir::f(unsigned int x) {
	x1 = posTireur.first - 1/2;
	y1 = posTireur.second - 1/2;
	
	x2 = direction.first - 1/2;
	y2 = direction.second - 1/2;
	
	double res = (y2 - y1)*x;
	res += (x2*y1 - x1*y2);
	res /= (x2 - x1);

	return res;
}

double Tir::g(unsigned int y) {
	x1 = posTireur.first - 1/2;
	y1 = posTireur.second - 1/2;
	
	x2 = direction.first - 1/2;
	y2 = direction.second - 1/2;
	
	double res = (x2 - x1)*y;
	res += (x2*y1 - x1*y2);
	res /= (y2 - y1);

	return res;
}

double Tir::z(double d) {
	double vx = puissance*cos(angle);
	double vz = puissanve*sin(angle);
	
	double res = vz*d/vx;
	res -= (1/2)*9.81*(d/vx)*(d/vx);
	
	return res;
}