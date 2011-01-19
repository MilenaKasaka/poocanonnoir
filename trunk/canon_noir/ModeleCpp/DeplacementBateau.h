#ifndef DEPLACEMENT_BATEAU_H
#define DEPLACEMENT_BATEAU_H

#include <vector>
#include "State.h"
#include "Case.h"

using namespace std;

class DeplacementBateau : public State
{
	private :
		// retourne la liste des cases sur lesquelles il y a un bateau
		//vector <pair<int,int> > casesBateaux();
		// retourne la liste des cases accessibles a l'utilisateur en fonction de son bateau et de son lancer de des
		vector<Case> casesAccessibles();

	public :

		DeplacementBateau(Moteur* m);
		void gerer();

};

#endif

