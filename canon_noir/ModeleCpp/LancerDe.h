/**
* \file LancerDe.h
* \brief Fichier d'en-tete decrivant la classe LancerDe
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/
#ifndef LANCER_DE_H
#define LANCER_DE_H

#include <vector>
#include <time.h>
#include <utility>
#include "State.h"

using namespace std;

/**
* \class LancerDe
* \brief Etat chargé du tirage aléatoire du résultat du lancer de dés
*/
class LancerDe : public State
{

	private :
		int cptJoueur; // indice du joueur qui lance le de pour tenter de jouer le premier
		vector<int> tabScores; // tableau des lancers de des pour la selection du premier joueur
		vector <pair <int,int> > casesAccessibles();
		void tirerDes();
		void selectionPremierJoueur();

	public :

		LancerDe(Moteur* m);
		void gerer();
}; 

#endif

