/**
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

/**
* \class Facade
* \brief Classe chargée de la communication entre le moteur et l'interface graphique.
* Permet à l'interface d'accéder à l'état du moteur et de le modifier
*/
class DLL Facade
{
	private:
		Moteur* moteur;


	public :

		Facade();
		//~Facade();

		void initMoteur();
		void execute();

		bool getJeuFini();

		// DES
		int getDe1();
		int getDe2();
		bool getChoixPremier();

		// JOUEURS
		int getNbJoueurs();
		int getJoueurCourant();
		void initJoueurs(int size);
		int getTypeBateau(int joueur);
		int getXBateau(int joueur);
		int getYBateau(int joueur);
		int getNbTresors(int joueur);
		bool getTransporteTresor(int joueur);
		int getXPort(int joueur);
		int getYPort(int joueur);

		// MAP
		int getNbLignes();
		int getNbColonnes();
		int getTypeCase(int x, int y);
		bool estAccessible(int x, int y);
		void deplacerBateau(int x, int y);

		// TIR
		void reglerTir(int angle, int puissance, int dirX, int dirY);
		bool getResTir();
		int getAngleMax();
		int getPuissanceMax();
		
		// Actions disponibles sur l'interface
		bool dispoLancerDe();
		bool dispoNbJoueurs();
		bool dispoChoixCouleur();
		bool dispoChoixCase();
		bool dispoReglageTir();
		bool getRamasseTresor();
};

EXTERNC DLL Facade*  Facade_New();
EXTERNC DLL void  Facade_Delete(Facade* f);

