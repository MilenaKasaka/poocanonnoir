﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Changes to this file will be lost if the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------
#include <vector>
#include <time.h>
#include <utility>
#include "Moteur.h"

using namespace std;

class LancerDe : public State
{

	private :

		vector <pair <int,int> > casesAccessibles();
		void tirerDes();
		Moteur* moteur;

	public :

		LancerDe(Moteur* m);
		void gerer();
}; 
