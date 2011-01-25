/**
* \file TirBordure.h
* \brief Fichier d'en-tete decrivant la classe TirBordure
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/
#ifndef TIR_BORDURE_H
#define TIR_BORDURE_H

#include "Tir.h"

/**
* \class TirBordure
* \brief Définit un tir de type duel à partir d'une case à la bordure du plateau
*/
class TirBordure : public Tir
{

	public :
		TirBordure(Moteur* m);
		void gerer();

}; 

#endif