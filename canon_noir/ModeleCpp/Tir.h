#ifndef TIR_H
#define TIR_H

#include <utility>
#include "State.h"
#include "enumerations.h"

using namespace std;

class Tir : public State
{
	private :
		int angle;
		int puissance;
		pair<int,int> direction; // coordonnees de la case visee

		pair<int,int> tirer(); // retourne l'impact du tir
		pair<int,int> calculerTir(); // calcule la portée du tir

	public :

		Tir(Moteur* m);
		// p = puissance, a = angle (hauteur), c = coordonnée de la case visee
		void reglerTir(int p, int a, pair<int,int> c);
		void gerer(); // gere les conséquences du tir sur le jeu

}; 

#endif