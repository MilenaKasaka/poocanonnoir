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

class LancerDe : public State
{

	private :

		vector <pair <int,int> > casesAccessibles();
		void tirerDes();

	public :

		LancerDe(Moteur* m);
		void gerer();
}; 

#endif

