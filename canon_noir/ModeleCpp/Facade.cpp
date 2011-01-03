#include "Facade.h"

Facade::Facade()
{
	initMoteur();
}

void Facade::initMoteur()
{
	moteur = new Moteur();
}

void Facade::execute()
{
	moteur->requete();
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

int Facade::getXBateau(int joueur)
{
	return 0;
}

int Facade::getYBateau(int joueur)
{
	return 0;
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

int Facade::getDe1()
{
	return 0;
}

int Facade::getDe2()
{
	return 0;
}

bool Facade::estAccessible(int x,int y)
{
	return moteur->estAccessible(x,y);
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