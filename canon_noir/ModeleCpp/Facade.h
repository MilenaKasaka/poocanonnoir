﻿/**
* \file Facade.h
* \brief Fichier d'en-tete decrivant la classe Facade
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/
#pragma once

#define WANTDLLEXP

#ifdef WANTDLLEXP		//exportation dll 
		#define DLL  __declspec( dllexport ) 
		#define EXTERNC extern "C"
#else
		#define DLL		//standard
		#define EXTERNC 
		
#endif

#include "enumerations.h"
#include "Moteur.h"

using namespace std;
class DLL Facade
{
	private:
		Moteur* moteur;


	public :

		Facade();
		//~Facade();

		void initMoteur();
		void execute();

		int getDe1();
		int getDe2();
		bool getChoixPremier();

		int getNbLignes();
		int getNbColonnes();
		int getNbJoueurs();
		int getJoueurCourant();
		void initJoueurs(int size);

		int getTypeBateau(int joueur);
		int getXBateau(int joueur);
		int getYBateau(int joueur);
		int getNbTresors(int joueur);
		int getTypeCase(int x, int y);
		void initialiserTir(int angle, int puissance);

		bool estAccessible(int x, int y);
		
		// Actions disponibles sur l'interface
		bool dispoLancerDe();
		bool dispoNbJoueurs();
		bool dispoChoixCouleur();
		bool dispoChoixCase();
		bool dispoReglageTir();

};

EXTERNC DLL Facade*  Facade_New();
EXTERNC DLL void  Facade_Delete(Facade* f);
