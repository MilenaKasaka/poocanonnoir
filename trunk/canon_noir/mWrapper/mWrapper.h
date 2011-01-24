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

	int getNbLignes()
	{
		return f->getNbLignes();
	}

	int getNbColonnes()
	{
		return f->getNbColonnes();
	}

	int getNbJoueurs()
	{
		return f->getNbJoueurs();
	}

	int getJoueurCourant()
	{
		return f->getJoueurCourant();
	}

	void initJoueurs(int size)
	{
		f->initJoueurs(size);
	}

	int getTypeBateau(int joueur)
	{
		return ((int)f->getTypeBateau(joueur));
	}

	void execute()
	{
		f->execute();
	}

	int getXBateau(int joueur)
	{
		return f->getXBateau(joueur);
	}

	int getYBateau(int joueur)
	{
		return f->getYBateau(joueur);
	}

	int getNbTresors(int joueur)
	{
		return f->getNbTresors(joueur);
	}

	int getXPort(int joueur)
	{
		return f->getXPort(joueur);
	}

	int getYPort(int joueur)
	{
		return f->getYPort(joueur);
	}

	int getTypeCase(int x, int y)
	{
		return ((int)f->getTypeCase(x,y));
	}

	void initialiserTir(int angle, int puissance)
	{
		f->initialiserTir(angle,puissance);
	}

	int getDe1()
	{
		return f->getDe1();
	}

	int getDe2()
	{
		return f->getDe2();
	}

	bool getChoixPremier()
	{
		return f->getChoixPremier();
	}

	bool estAccessible(int x, int y)
	{
		return f->estAccessible(x,y);
	}

	void deplacerBateau(int x, int y)
	{
		f->deplacerBateau(x,y);
	}

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
