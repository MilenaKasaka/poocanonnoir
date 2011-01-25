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

#include <time.h>
#include <utility>
#include "State.h"
#include "enumerations.h"
#include "Joueur.h"

using namespace std;

/**
* \class Tir
* \brief Etat chargé de calculer le résultat du tir en fonction des réglages de l'utilisateur
* Le résultat du tir sera répercuté sur le moteur et ainsi sur l'ensemble du modèle
*/
class Tir : public State
{
	private :
		int angle;
		int puissance;
		pair<int,int> direction; // coordonnees de la case visee

		pair<int,int> tirer(); // retourne l'impact du tir
		pair<int,int> calculerTir(); // calcule la portée du tir
		Joueur* joueurVise(); // retourne le bateau vise par le tir

	public :

		Tir(Moteur* m);
		// p = puissance, a = angle (hauteur), c = coordonnée de la case visee
		void reglerTir(int p, int a, pair<int,int> c);
		void gerer(); // gere les conséquences du tir sur le jeu

}; 

#endif