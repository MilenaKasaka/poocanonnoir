#include "DeplacementBateau.h"
#include "Moteur.h"

DeplacementBateau::DeplacementBateau(Moteur* m) : State(m)
{
}

void DeplacementBateau::gerer()
{
	moteur->setCasesAccessibles(casesAccessibles());
}

/*vector< pair<int,int> > DeplacementBateau::casesBateaux()
{

}*/

vector<Case> DeplacementBateau::casesAccessibles()
{
	vector<Case> casesAcc = moteur->getMap()->getCases();
	//casesAcc = m->getCases(); -> revoir le format du vecteur de cases
	vector<Case>::iterator it;
	for (it = casesAcc.begin() ; it!=casesAcc.end(); it++)
	{
		if ((*it).getType()== ILE)
			casesAcc.erase(it);
		
	}

	return casesAcc;
}