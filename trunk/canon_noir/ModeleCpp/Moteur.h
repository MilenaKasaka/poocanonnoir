/**
* \file Moteur.h
* \brief Fichier d'en-tete decrivant la classe Moteur
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/
#ifndef MOTEUR_H
#define MOTEUR_H

#include <vector>
#include <utility>

#include "enumerations.h"
#include "Map.h"
#include "Joueur.h"
#include "AttenteNbJoueurs.h"
#include "ChoixCouleur.h"
#include "LancerDe.h"
#include "DeplacementBateau.h"
#include "TirCaseCanon.h"
#include "TirBordure.h"

using namespace std;

/**
* \class Moteur
* \brief Classe principale du moteur qui coordonne tous les éléments de la partie modèle du jeu
*/
class Moteur
{
	private :

		int joueurCourant; /*!< indice du joueur courant */
		pair<int,int> resLancerDe; /*!< résultat du lancer de dés */
		vector<State* > etats; /*!< liste des états */
		int etatCourant; /*!< indice de l'état courant */
		bool premierInit; /*!< permet de différencier le lancer permettant de selectionner le 1er joueur */
		bool choixPremier ; /*!< vrai seulement au moment precis au le premier joueur vient d'etre selectionné */
		vector<Case> casesAccessibles; /*!< liste des cases accessibles pour le joueur courant */
		Map map; /*!< plateau du jeu */
		vector<Joueur> joueurs; /*!< liste des joueurs */
		bool ramasseTresor; /*!< vrai si le joueur vient de ramasser un trésor */
		bool resTir; /*!< vrai si le tir vient de réussir, faux sinon */
		bool jeuFini; /*!< vrai si le jeu est fini, faux sinon */

		/**
		* \fn void initEtats()
		* \brief Initialise la liste des états du jeu
		*/
		void initEtats();

		/**
		* \fn void initPorts()
		* \brief Initialise les ports de chacun des joueurs
		*/
		void initPorts();

	public :

		/**
		* \fn Moteur()
		* \brief Construit l'objet Moteur
		*/
		Moteur();

		/**
		* \fn ~Moteur()
		* \brief Détruit l'objet moteur
		*/
		~Moteur();

		// Actions disponibles sur l'interface

		/**
		* \fn bool dispoLancerDe()
		* \brief Verifie si les dés sont activés
		* \return bool - vrai si les dés sont activés, faux sinon
		*/
		bool dispoLancerDe();

		/**
		* \fn bool dispoNbJoueurs()
		* \brief Verifie si le choix du nombre de joueurs est disponible
		* \return bool - vrai si le choix du nombre de joueurs est disponible, faux sinon
		*/
		bool dispoNbJoueurs();

		/**
		* \fn dispoChoixCouleur()
		* \brief Verifie si le choix de la couleur est disponible
		* (NON UTILISE DANS CETTE VERSION DU JEU)
		* \return bool - vrai si le choix de la couleur est disponible, faux sinon
		*/
		bool dispoChoixCouleur();

		/**
		* \fn bool dispoChoixCase()
		* \brief Verifie si le choix de la case d'arrivée pour le déplacement d'un bateau est disponible
		* \return bool - vrai si le choix de la case d'arrivée pour le déplacement d'un bateau est disponible, faux sinon
		*/
		bool dispoChoixCase();

		/**
		* \fn bool dispoReglageTir()
		* \brief Verifie si le réglage du tir est disponible
		* \return bool - vrai si le réglage du tir est disponible, faux sinon
		*/
		bool dispoReglageTir();

		/**
		* \fn bool getRamasseTresor()
		* \brief Vérifie si le joueur vient de ramasser un trésor
		* \return bool - vrai si le joueur vient de ramasser un trésor, faux sinon
		*/
		bool getRamasseTresor() const;

		/**
		* \fn void setRamasseTresor(bool b)
		* \brief Permet d'indiquer si le joueur vient de ramasser un trésor
		* \param[in] b - indique si le joueur vient de ramasser un trésor
		*/
		void setRamasseTresor(bool b);


		/**
		* \fn void requete()
		* \brief Permet d'exécuter la fonction de gestion d'un état suite à une requete de l'interface
		*/
		void requete();

		/**
		* \fn void setEtatCourant(int etat)
		* \brief Permet de changer l'état courant du moteur
		* \param[in] etat nouvel état courant du moteur
		*/
		void setEtatCourant(int etat);

		/**
		* \fn int getEtatCourant() const
		* \brief Permet d'obtenir l'état courant du moteur
		* \return int - état courant du moteur
		*/
		int getEtatCourant() const;

		// DES

		/**
		* \fn void setLancerDe(pair<int,int> lance)
		* \brief Initialise le résultat du lancer de dé
		* \param[in] lance - résultat du lancer de dé
		*/
		void setLancerDe(pair<int,int> lance);

		/**
		* \fn pair<int,int> getLancerDe() const
		* \brief Permet d'obtenir le résultat du lancer de dé
		* \return pair<int,int> - résultat du lancer de dé
		*/
		pair<int,int> getLancerDe() const;

		/**
		* \fn void setPremierInit()
		* \brief Permet d'indiquer que le premier joueur est choisi
		*/
		void setPremierInit();

		/**
		* \fn bool getPremierInit() const
		* \brief Vérifie si le premier joueur est choisi
		* \return bool - vrai si le premier joueur est choisi, faux sinon
		*/
		bool getPremierInit() const;

		/**
		* \fn void choixPremierFini()
		* \brief Indique que le choix du premier joueur vient de se terminer
		*/
		void choixPremierFini();

		/**
		* \fn bool getChoixPremier() const
		* \brief Vérifie si le choix du premier joueur vient de se terminer
		* \return vrai si le choix du premier joueur vient de se terminer, faux sinon
		*/
		bool getChoixPremier() const;

		// JOUEURS

		/**
		* \fn int getNbJoueurs()
		* \brief Permet d'obtenir le nombre de joueurs
		* \return int - nombre de joueurs
		*/
		int getNbJoueurs();

		/**
		* \fn void initJoueurs(int size)
		* \brief Permet d'initialiser le nombre de joueurs	
		* \param[in] size nombre de joueurs
		*/
		void initJoueurs(int size);

		/**
		* \fn Joueur* getJoueur(int i)
		* \brief Permet d'obtenir le joueur dont l'indice est passé en paramètre
		* \param[in] indice du joueur
		* \return Joueur* - pointeur vers le joueur dont l'indice est passé en paramètre
		*/
		Joueur* getJoueur(int i);

		/**
		* \fn Joueur* getJoueurCourant()
		* \brief Permet d'obtenir le joueur courant
		* \return Joueur* - pointeur vers le joueur courant
		*/
		Joueur* getJoueurCourant();

		/**
		* \fn int getNumJoueurCourant()
		* \brief Permet d'obtenir l'indice du joueur courant
		* \return int - indice du joueur courant
		*/
		int getNumJoueurCourant();

		/**
		* \fn void setNumJoueurCourant(int i)
		* \brief Permet de changer de joueur courant
		* \param[in] i indice du nouveau joueur courant
		*/
		void setNumJoueurCourant(int i);

		/**
		* \fn void joueurSuivant()
		* \brief Permet de passer au joueur suivant
		*/
		void joueurSuivant();

		/**
		* \fn vector<pair<int,int> > getCooBateaux()
		* \brief Permet d'obtenir la liste des coordonnées de tous les bateaux sur le plateau
		* \return vector<pair<int,int> > - liste des coordonnées de tous les bateaux sur le plateau
		*/
		vector<pair<int,int> > getCooBateaux();

		/**
		* \fn int getNbTresors(int joueur)
		* \brief Permet d'obtenir le nombre de trésors d'un joueur
		* \param[in] joueur indice du joueur
		* \return int - nombre de trésors du joueur
		*/
		int getNbTresors(int joueur);
		bool getTransporteTresor(int joueur);
		pair<int,int> getPosPort(int joueur);

		// MAP
		Map* getMap();
		// Prend en compte l'état du moteur
		void setCasesAccessibles(vector<Case> ca);
		bool estAccessible(int x, int y);
		TypeBateau getTypeBateau(); // retourne le type de bateau du joueur courant
		TypeBateau getTypeBateau(int joueur);
		pair<int,int> getPosJoueurCourant();
		pair<int,int> getPosJoueur(int i);
		TypeCase getTypeCase(int x, int y);
		bool contientBateau(Case c); // retourne vrai si la case contient un bateau
		void deplacerBateau(int x, int y);

		//TIR
		void reglerTir(int angle, int puissance, pair<int,int> direction);
		bool getResTir() const;
		void setResTir(bool b);

		bool getJeuFini() const;
};

inline int Moteur::getEtatCourant() const { return etatCourant; }
inline pair<int,int> Moteur::getLancerDe() const { return resLancerDe; }
inline bool Moteur::getPremierInit() const { return premierInit; }
inline bool Moteur::getChoixPremier() const { return choixPremier; }
inline bool Moteur::getResTir() const { return resTir; }
inline bool Moteur::getJeuFini() const { return jeuFini; }
inline bool Moteur::getRamasseTresor() const { return ramasseTresor; }

#endif