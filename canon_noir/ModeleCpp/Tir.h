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
		pair<int,int> direction;

		pair<int,int> tirer(); // retourne l'impact du tir
		pair<int,int> calculerTir(); // calcule la portée du tir

	public :

		Tir(Moteur* m);
		bool reglerDirectionTir(int i, int j);
		bool reglerTir(int p, int a);
		void gerer(); // gere les conséquences du tir sur le jeu
		void initialiserTir(int angle, int puissance);

}; 

#endif