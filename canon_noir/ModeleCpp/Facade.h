#pragma once

#include <vector>
#include <utility>
#include "enumerations.h"
#include "Moteur.h"

#define WANTDLLEXP

#ifdef WANTDLLEXP		//exportation dll 
		#define DLL  __declspec( dllexport ) 
		#define EXTERNC extern "C"
#else
		#define DLL		//standard
		#define EXTERNC 
		
#endif

using namespace std;
class DLL Facade
{
	private:
		Moteur* moteur;


	public :

		void initMoteur();

		int getNbLigne();
		int getNbColonnes();
		int getNbJoueurs();
		void setNbJoueurs(int size);

		int getTypeBateau(int joueur, int bateau);
		void execute();
		pair<int,int> getPosBateaux(int joueur);
		int getNbTresors(int joueur);
		int getTypeCase(int x, int y);
		void initialiserTir(int angle, int puissance);
		int getLancerDe();
		vector <pair <int,int> > getCasesAccessibles();
		
		// Actions disponibles sur l'interface
		bool dispoLancerDe();
		bool dispoNbJoueurs();
		bool dispoChoixCouleur();
		bool dispoChoixCase();
		bool dispoReglageTir();

};

EXTERNC DLL Facade*  Facade_New();
EXTERNC DLL void  Facade_Delete(Facade* f);

