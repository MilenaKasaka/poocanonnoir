/**
* \file DeplacementBateau.cpp
* \brief Fichier definissant les fonctions de la classe DeplacementBateau
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/
#include "DeplacementBateau.h"
#include "Moteur.h"

DeplacementBateau::DeplacementBateau(Moteur* m) : State(m)
{
}

void DeplacementBateau::gerer()
{
	vector<Case> caseAcc = casesAccessibles();
	if (caseAcc.empty())
	{
		moteur->setEtatCourant(LANCER_DE);
	}
	else
	{
		moteur->setCasesAccessibles(caseAcc);
	}
	//moteur->setCasesAccessibles(casesAccessibles());
}

/*vector< pair<int,int> > DeplacementBateau::casesBateaux()
{

}*/

bool DeplacementBateau::caseBonneDistance(pair<int,int> cooCase)
{
	pair<int,int> posJoueur = moteur->getPosJoueurCourant();
	//cout << "CooCase = (" << cooCase.first << "," << cooCase.second << ") - posJoueur = (" << posJoueur.first << "," << posJoueur.second << ")" << endl; 
	int de1 = moteur->getLancerDe().first;
	int sommeDeuxDes = moteur->getLancerDe().first + moteur->getLancerDe().second;
	bool access =
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
			|| // deplacement en diagonale
			(
				(cooCase.first == posJoueur.first + de1) 
				&&
				(
					(cooCase.second == posJoueur.second + de1)
					||
					(cooCase.second == posJoueur.second - de1)
				)
			)
			||
			(
				(cooCase.first == posJoueur.first - de1) 
				&&
				(
					(cooCase.second == posJoueur.second + de1)
					||
					(cooCase.second == posJoueur.second - de1)
				)
			)
			||
			(
				(cooCase.first == posJoueur.first + sommeDeuxDes) 
				&&
				(
					(cooCase.second == posJoueur.second + sommeDeuxDes)
					||
					(cooCase.second == posJoueur.second - sommeDeuxDes)
				)
			)
			||
			(
				(cooCase.first == posJoueur.first - sommeDeuxDes) 
				&&
				(
					(cooCase.second == posJoueur.second + sommeDeuxDes)
					||
					(cooCase.second == posJoueur.second - sommeDeuxDes)
				)
			)
		);

	// Déplacement diagonal => ne marche pas
	/*int XSommet = cooCase.first;
	int YSommet = posJoueur.second;
	int distanceX = 0;
	if (XSommet < posJoueur.first)
	{
		distanceX = posJoueur.first - XSommet;
	}
	else
	{
		distanceX = XSommet - posJoueur.first;
	}

	int distanceY = 0;
	if (YSommet < cooCase.second)
	{
		distanceX = cooCase.second - YSommet;
	}
	else
	{
		distanceX = YSommet - cooCase.second;
	}

	int diag_carre = (distanceX*distanceX) + (distanceY*distanceY);
	access = access || (diag_carre == (de1*de1)) || (diag_carre == (sommeDeuxDes*sommeDeuxDes));*/


		/*if (access)
			cout << "accessible !" << endl;*/
		return access;
}

vector<Case> DeplacementBateau::casesAccessibles()
{
	vector<Case>* cases = moteur->getMap()->getCases();
	vector<Case> casesAcc;

	vector<Case>::iterator it;
	for (it = cases->begin() ; it!=cases->end(); it++)
	{
		if ((*it).getType()== ILE)
			cout << "Ile !!! (" << (*it).getCoordonnees().first << "," << (*it).getCoordonnees().second << ")" << endl;
		if ( ((*it).getType()!= ILE) && (!moteur->contientBateau(*it)) && (caseBonneDistance((*it).getCoordonnees())) )
		{
			casesAcc.push_back(*it);
			cout << "(" << (*it).getCoordonnees().first << "," << (*it).getCoordonnees().second << ")" << endl;
		}
	}

	return casesAcc;
}