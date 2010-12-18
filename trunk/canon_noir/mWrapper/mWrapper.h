#pragma once

#include "Facade.h"
#pragma comment (lib,"ModeleCpp.lib")

using namespace System;
namespace mWrapper {
	
public ref class WrapperMoteur
{
private:
	Facade* f;
public :
	WrapperMoteur()
	{
		f = Facade_New();
	}

	~WrapperMoteur()
	{
		Facade_Delete(f);
	}

	int getNbJoueurs()
	{
		return f->getNbJoueurs();
	}

	int getTypeBateau(int joueur, int bateau)
	{
		return ((int)f->getTypeBateau(joueur,bateau));
	}

	void execute()
	{
		f->execute();
	}

	/*pair<int,int> getPosBateaux(int joueur)
	{
		return f->getPosBateaux(joueur);
	}*/

	int getNbTresors(int joueur)
	{
		return f->getNbTresors(joueur);
	}

	int getTypeCase(int x, int y)
	{
		return ((int)f->getTypeCase(x,y));
	}

	void initialiserTir(int angle, int puissance)
	{
		f->initialiserTir(angle,puissance);
	}

	int getLancerDe()
	{
		return f->getLancerDe();
	}

	/*vector<pair <int,int> > getCasesAccessibles()
	{
		return f->getCasesAccessibles();
	}*/

	bool dispoLancerDe()
	{
		return f->dispoLancerDe();
	}

	bool dispoNbJoueurs()
	{
		return f->dispoNbJoueurs();
	}

	bool dispoChoixCouleur()
	{
		return f->dispoChoixCouleur();
	}

	bool dispoChoixCase()
	{
		return f->dispoChoixCase();
	}

	bool dispoReglageTir()
	{
		return f->dispoReglageTir();
	}

	protected:
	!WrapperMoteur(){
		Facade_Delete(f);
	}

};

}
