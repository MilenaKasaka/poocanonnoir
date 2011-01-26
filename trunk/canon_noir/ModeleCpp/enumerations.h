/**
* \file enumerations.h
* \brief Fichier d'en-tete definissant les constantes et les enumerations communes au modele
* \author Sophie Le Corre
* \author Gregoire Lecourt
* \version 1.0
* \date 26/01/2011
*/
#ifndef ENUMERATIONS_H
#define ENUMERATIONS_H

#define NB_TRESORS_GAGNANT 3

#define LARGEUR 11
#define HAUTEUR 8
#define NB_JOUEURS_MAX 4
#define DE 6

#define NB_ETATS 6

#define PUISSANCEMAX 10
#define ANGLEMAX 5

/**
* \enum TypeEtat
* \brief Etats du jeu
*/
typedef enum {ATTENTE_NB_JOUEURS, CHOIX_COULEUR, LANCER_DE, DEPLACEMENT_BATEAU, TIR_CASE_CANON, TIR_BORDURE} TypeEtat;

/**
* \enum TypeEtat
* \brief Les trois types de bateaux
*/
typedef enum {CARAVELLE, FREGATE, RADEAU}  TypeBateau;

/**
* \enum TypeEtat
* \brief Les différentes sortes de cases
*/
typedef enum {EAU, ILE, CANON, TRESOR} TypeCase;

#endif