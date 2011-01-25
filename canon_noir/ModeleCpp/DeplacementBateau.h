/**
* \file DeplacementBateau.h
* \brief Fichier d'en-tete decrivant la classe DeplacementBateau
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/
#ifndef DEPLACEMENT_BATEAU_H
#define DEPLACEMENT_BATEAU_H

#include <vector>
#include "State.h"
#include "Case.h"

using namespace std;

/**
* \class DeplacementBateau
* \brief Etat qui affiche les cases accessibles pour le joueur et attend que celui-ci choisisse le déplacement de son bateau
* Calcule les cases accessibles en fonction du résultat du lancer de dé
*/
class DeplacementBateau : public State
{
	private :
		bool caseBonneDistance(pair<int,int> cooCase); // retourne vrai si la case est a la bonne distance par rapport au joueur
		// retourne la liste des cases sur lesquelles il y a un bateau
		//vector <pair<int,int> > casesBateaux();
		// retourne la liste des cases accessibles a l'utilisateur en fonction de son bateau et de son lancer de des
		vector<Case> casesAccessibles();

	public :

		DeplacementBateau(Moteur* m);
		void gerer();

};

#endif

