/**
* \file Facade.cpp
* \brief Fichier definissant les fonctions de la classe Facade
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/

#include "Facade.h"

Facade::Facade()
{
	initMoteur();
}

/*Facade::~Facade()
{
	delete moteur;
}*/

void Facade::initMoteur()
{
	moteur = new Moteur();
}

void Facade::execute()
{
	moteur->requete();
}

int Facade::getNbLignes()
{
	return HAUTEUR;
}

int Facade::getNbColonnes()
{
	return LARGEUR;
}

int Facade::getNbJoueurs()
{
	return moteur->getNbJoueurs();
}

void Facade::initJoueurs(int size)
{
	moteur->initJoueurs(size);
}

int Facade::getTypeBateau(int joueur)
{
	return moteur->getTypeBateau(joueur);
}

int Facade::getXBateau(int joueur)
{
	return 0;
}

int Facade::getYBateau(int joueur)
{
	return moteur->getPosJoueurCourant().first;
}

int Facade::getNbTresors(int joueur)
{
	return moteur->getPosJoueurCourant().second;
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
	return moteur->getLancerDe().first;
}

int Facade::getDe2()
{
	return moteur->getLancerDe().second;
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