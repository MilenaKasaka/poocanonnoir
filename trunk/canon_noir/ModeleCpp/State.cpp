/**
* \file State.cpp
* \brief Fichier definissant les fonctions de la classe State
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/
#include "State.h"

State::State(Moteur* m)
{
	moteur = m;
}

State::~State()
{
	delete moteur;
}

