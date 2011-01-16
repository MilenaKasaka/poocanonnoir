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

