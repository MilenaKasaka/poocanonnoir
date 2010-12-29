#include "Facade.h"

Facade::Facade()
{
	initMoteur();
}

void Facade::initMoteur()
{
	moteur = new Moteur();
}

int Facade::getNbLigne()
{
	return 0;
}

int Facade::getNbColonnes()
{
	return 0;
}

int Facade::getNbJoueurs()
{
	return 0;
}

void Facade::setNbJoueurs(int size)
{
	moteur->initJoueurs(size);
}


int Facade::getTypeBateau(int joueur, int bateau)
{
	return 0;
}

void Facade::execute()
{
}

pair<int,int> Facade::getPosBateaux(int joueur)
{
	return make_pair(0,0);
}

int Facade::getNbTresors(int joueur)
{
	return 0;
}

int Facade::getTypeCase(int x, int y)
{
	return 0;
}

void Facade::initialiserTir(int angle, int puissance)
{
}

int Facade::getLancerDe()
{
	return 0;
}

vector <pair <int,int> > Facade::getCasesAccessibles()
{
	vector <pair <int,int> > v;
	return v;
}

bool Facade::dispoLancerDe()
{
	return moteur->dispoLancerDe();
}

bool Facade::dispoNbJoueurs()
{
	return moteur->dispoNbJoueurs();
}

bool Facade::dispoChoixCouleur()
{
	return moteur->dispoChoixCouleur();
}

bool Facade::dispoChoixCase()
{
	return moteur->dispoChoixCase();
}

bool Facade::dispoReglageTir()
{
	return moteur->dispoReglageTir();
}

EXTERNC DLL Facade*   Facade_New(){
	return new Facade();
}

EXTERNC DLL void  Facade_Delete( Facade* f){
	delete f;
}