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
		Moteur* moteur; /*!< pointeur vers l'instance de moteur */


	public :

		/**
		* \fn Facade()
		* \brief Crée la facade en appelant l'initialisation du moteur
		*/
		Facade();
		//~Facade();

		/**
		* \fn initMoteur()
		* \brief Crée un nouvel objet moteur qui sera lui-même chargé de l'initialisation de l'ensemble de la partie modèle
		*/
		void initMoteur();

		/**
		* \fn execute()
		* \brief Appelle la méthode requete() du moteur qui elle-même appelle la fonction gerer() propre à chaque état
		*/
		void execute();

		/**
		* \fn getJeuFini()
		* \brief Permet de savoir si la partie est terminée
		* \return bool - vrai si le jeu est fini, faux sinon
		*/
		bool getJeuFini();

		// DES ---------------------------------------------------------------------

		/**
		* \fn int getDe1()
		* \brief Permet d'obtenir la valeur du premier dé
		* \return int - valeur du premier dé
		*/
		int getDe1();

		/**
		* \fn int getDe2()
		* \brief Permet d'obtenir la valeur du deuxième dé
		* \return int - valeur du deuxième dé
		*/
		int getDe2();

		/**
		* \fn getChoixPremier()
		* \brief Permet de savoir si le premier joueur a déjà été tiré au sort
		* \return bool - vrai le premier joueur a été choisi, faux sinon
		*/
		bool getChoixPremier();

		// JOUEURS ---------------------------------------------------------------------

		/**
		* \fn int getNbJoueurs()
		* \brief Permet d'obtenir le nombre de joueurs
		* \return int - nombre de joueurs
		*/
		int getNbJoueurs();

		/**
		* \fn int getJoueurCourant()
		* \brief Permet d'obtenir le joueur courant
		* \return int - joueur courant
		*/
		int getJoueurCourant();

		/**
		* \fn void initJoueurs(int size)
		* \brief Permet d'initialiser le nombre de joueurs	
		* \param[in] size nombre de joueurs
		*/
		void initJoueurs(int size);
		
		/**
		* \fn int getTypeBateau(int joueur)
		* \brief Permet d'obtenir le type du bateau courant d'un joueur
		* \param[in] joueur numero du joueur
		* \return int - type du bateau courant du joueur passé en paramètre
		*/
		int getTypeBateau(int joueur);

		/**
		* \fn int getXBateau(int joueur)
		* \brief Permet d'obtenir l'abscisse (unité = case) du bateau courant d'un joueur
		* \param[in] joueur numero du joueur
		* \return int - abscisse (unité = case) du bateau courant du joueur passé en paramètre
		*/
		int getXBateau(int joueur);

		/**
		* \fn int getYBateau(int joueur)
		* \brief Permet d'obtenir l'ordonnée (unité = case) du bateau courant d'un joueur
		* \param[in] joueur numero du joueur
		* \return int - ordonnée (unité = case) du bateau courant du joueur passé en paramètre
		*/
		int getYBateau(int joueur);

		/**
		* \fn int getNbTresors(int joueur)
		* \brief Permet d'obtenir le nombre de trésors d'un joueur
		* \param[in] joueur numero du joueur
		* \return int - nombre de trésors du joueur passé en paramètre
		*/
		int getNbTresors(int joueur);

		/**
		* \fn bool getTransporteTresor(int joueur)
		* \brief Verifie que le joueur passé en paramètre transporte un trésor sur son bateau
		* \param[in] joueur numero du joueur
		* \return bool - vrai si le bateau du joueur transporte un trésor, faux sinon
		*/
		bool getTransporteTresor(int joueur);

		/**
		* \fn int getXPort(int joueur)
		* \brief Permet d'obtenir l'abscisse (unité = case) du port de départ d'un joueur
		* \param[in] joueur numero du joueur
		* \return int - abscisse (unité = case) du port de départ du joueur passé en paramètre
		*/
		int getXPort(int joueur);

		/**
		* \fn int getYPort(int joueur)
		* \brief Permet d'obtenir l'ordonnée (unité = case) du port de départ d'un joueur
		* \param[in] joueur numero du joueur
		* \return int - ordonnée (unité = case) du port de départ du joueur passé en paramètre
		*/
		int getYPort(int joueur);

		// MAP ---------------------------------------------------------------------

		/**
		* \fn int getNbLignes()
		* \brief Permet d'obtenir le nombre de lignes du plateau
		* \return int - nombre de lignes du plateau
		*/
		int getNbLignes();

		/**
		* \fn int getNbColonnes()
		* \brief Permet d'obtenir le nombre de colonnes du plateau
		* \return int - nombre de colonnes du plateau
		*/
		int getNbColonnes();

		/**
		* \fn int getTypeCase(int x, int y)
		* \brief Permet d'obtenir le type de la case dont les coordonnées sont passées en paramètre
		* \param[in] x abscisse de la case
		* \param[in] y ordonnée de la case
		* \return int - type de la case
		*/
		int getTypeCase(int x, int y);

		/**
		* \fn bool estAccessible(int x, int y)
		* \brief Vérifie si la case dont les coordonnées sont passées en paramètres est accessible
		* \param[in] x abscisse de la case
		* \param[in] y ordonnée de la case
		* \return bool - vrai si la case est accessible, faux sinon
		*/
		bool estAccessible(int x, int y);

		/**
		* \fn void deplacerBateau(int x, int y)
		* \brief Permet de déplacer le bateau du joueur courant à la position passée en paramètre
		* \param[in] x abscisse de la case d'arrivée
		* \param[in] y ordonnée de la case d'arrivée
		*/
		void deplacerBateau(int x, int y);

		// TIR ---------------------------------------------------------------------

		/**
		* \fn void reglerTir(int angle, int puissance, int dirX, int dirY)
		* \brief Permet d'effectuer le réglage du tir en lui passant un angle, une puissance et une direction
		* \param[in] angle angle du tir
		* \param[in] puissance puissance du tir
		* \param[in] dirX abscisse de la direction du tir
		* \param[in] dirY ordonnée de la direction du tir
		*/
		void reglerTir(int angle, int puissance, int dirX, int dirY);

		/**
		* \fn bool getResTir()
		* \brief Permet d'obtenir le résultat du tir
		* \return bool - vrai si le tir a réussi, faux si le tir a échoué
		*/
		bool getResTir();

		/**
		* \fn int getAngleMax()
		* \brief Permet d'obtenir l'angle maximal pour le tir
		* \return int - angle maximal pour le tir
		*/
		int getAngleMax();

		/**
		* \fn int getPuissanceMax()
		* \brief Permet d'obtenir la puissance maximale pour le tir
		* \return int - puissance maximale pour le tir
		*/
		int getPuissanceMax();
		
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
		bool getRamasseTresor();
};

EXTERNC DLL Facade*  Facade_New();
EXTERNC DLL void  Facade_Delete(Facade* f);

