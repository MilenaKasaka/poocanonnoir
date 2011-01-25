/**
* \file Tir.h
* \brief Fichier d'en-tete decrivant la classe Tir
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/
#ifndef TIR_H
#define TIR_H

#include <utility>
#include <math.h>

#include "State.h"
#include "enumerations.h"

using namespace std;

class Tir : public State
{
	private :
		int angle;
		int puissance;
		pair<int,int> posTireur;
		pair<int,int> direction; // coordonnees de la case visee

		pair<int,int> tirer(); // retourne l'impact du tir
		pair<int,int> calculerTir(); // calcule la portée du tir
		
		double f(unsigned int x);
		double g(unsigned int y);
		double z(double d);

	public :

		Tir(Moteur* m);
		// p = puissance, a = angle (hauteur), c = coordonnée de la case visee
		void reglerTir(int p, int a, pair<int,int> c);
		void gerer(); // gere les conséquences du tir sur le jeu

}; 

#endif