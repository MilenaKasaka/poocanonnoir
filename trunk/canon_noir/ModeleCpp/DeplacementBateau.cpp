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

bool DeplacementBateau::caseBonneDistance(pair<int,int> cooCase)
{
	pair<int,int> posJoueur = moteur->getPosJoueurCourant();
	int de1 = moteur->getLancerDe().first;
	int sommeDeuxDes = moteur->getLancerDe().first + moteur->getLancerDe().second;
	return 
		(
			(	// deplacement vertical
				(cooCase.first == posJoueur.first)
				&& 
				(
					(cooCase.second == posJoueur.second + de1)
				||
					(cooCase.second == posJoueur.second - de1)
				||
					(cooCase.second == posJoueur.second + sommeDeuxDes)
				||
					(cooCase.second == posJoueur.second - sommeDeuxDes)
				)
			)
			||
			(	// deplacement horizontal
				(cooCase.second == posJoueur.second)
				&& 
				(
					(cooCase.first == posJoueur.first + de1)
				||
					(cooCase.first == posJoueur.first - de1)
				||
					(cooCase.first == posJoueur.first + sommeDeuxDes)
				||
					(cooCase.first == posJoueur.first - sommeDeuxDes)
				)
			)
		);
}

vector<Case> DeplacementBateau::casesAccessibles()
{
	vector<Case> casesAcc = moteur->getMap()->getCases();
	vector<Case>::iterator it;
	for (it = casesAcc.begin() ; it!=casesAcc.end(); it++)
	{
		//cooCase = (*it).getCoordonnees();
		if ( ((*it).getType()== ILE) || (moteur->contientBateau(*it)) || !(caseBonneDistance((*it).getCoordonnees())) )
			casesAcc.erase(it);
	}

	return casesAcc;
}