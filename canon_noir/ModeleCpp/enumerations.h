#ifndef ENUMERATIONS_H
#define ENUMERATIONS_H

#define LARGEUR 11
#define HAUTEUR 8
#define NB_JOUEURS_MAX 4
#define DE 6

#define PUISSANCEMAX 10
#define ANGLEMAX 5

typedef enum {ATTENTE_NB_JOUEURS, CHOIX_COULEUR, LANCER_DE, DEPLACEMENT_BATEAU, TIR_CASE_CANON, TIR_BORDURE} TypeEtat;
typedef enum {CARAVELLE, FREGATE, RADEAU}  TypeBateau;
typedef enum {EAU, ILE, CANON, TRESOR} TypeCase;

#endif