/*
 *  Constantes.h
 *  Code
 *
 *  Created by Grégoire on 05/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef CONSTANTES
#define CONSTANTES

#define LARGEUR 11
#define HAUTEUR 8
#define NB_JOUEURS_MAX 4
#define DE 6

#define PUISSANCEMAX 10
#define ANGLEMAX 5

//typedef enum {INITIALISATION, DEPLACEMENT, FIN} EtatJeu;
typedef enum {CARAVELLE, FREGATE, RADEAU} TypeBateau;
typedef enum {EAU, ILE, CANON, TRESOR} TypeCase;
typedef enum {INITIALISATION, DEPLACEMENT, TIR, DUEL, FIN, NBEJ} EtatJeu;

#endif