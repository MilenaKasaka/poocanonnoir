/**
* \file TirCaseCanon.h
* \brief Fichier d'en-tete decrivant la classe TirCaseCanon
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/
#ifndef TIR_CASE_CANON_H
#define TIR_CASE_CANON_H

#include "Tir.h"

class TirCaseCanon : public Tir
{

	public :
		TirCaseCanon(Moteur* m);
		void gerer();

}; 

#endif