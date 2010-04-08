#ifndef Macro_h
#define Macro_h


//-----------------------------------Info du Plateau et Case---------------------------------------------


//nb de colonnes du plateau de jeu
#define NB_COLONNES 15
//nb de lignes du plateau de jeu
#define NB_LIGNES 13
//nb de case du plateau de jeu
#define NB_CASE (NB_COLONNES*NB_LIGNES)

#define NB_MURSCASSABLES 80

//Position des Cases de départ des joueurs
#define POSITION_JOUEUR1 (NB_COLONNES+1)
#define POSITION_JOUEUR2 ((2*NB_COLONNES)-2)
#define POSITION_JOUEUR3 (((NB_LIGNES-2)*NB_COLONNES)+1)
#define POSITION_JOUEUR4 (((NB_LIGNES-1)*NB_COLONNES)-2)

//Position de l'abscisse et de l'ordonnee de depart des joueurs en pixel

#define ABSCISSE_ORIGINE1 (1.5 * LONGUEUR_CASE)	//Pour joueur 1 et 3
#define ORDONNEE_ORIGINE1 (1.5 * LARGEUR_CASE)	//Pour joueur 1 et 2
#define ABSCISSE_ORIGINE2 ((NB_COLONNES * LONGUEUR_CASE) - (1.5*LONGUEUR_CASE))	//Pour joueur 2 et 4
#define ORDONNEE_ORIGINE2 ((NB_LIGNES * LARGEUR_CASE) - (1.5*LARGEUR_CASE))	//Pour joueur 3 et 4

//Case interdite à la construction de case car ca bloquerait le joueur au départ
#define CASE_INTERDITE1 (NB_COLONNES+2)
#define CASE_INTERDITE2 ((2*NB_COLONNES)-3)
#define CASE_INTERDITE3 ((2*NB_COLONNES)+1)
#define CASE_INTERDITE4 ((3*NB_COLONNES)-2)
#define CASE_INTERDITE5 (((NB_LIGNES-3)*NB_COLONNES)+1)
#define CASE_INTERDITE6 (((NB_LIGNES-2)*NB_COLONNES)-2)
#define CASE_INTERDITE7 (((NB_LIGNES-2)*NB_COLONNES)+2)
#define CASE_INTERDITE8 (((NB_LIGNES-1)*NB_COLONNES)-3)

//Taille d'une Case
#define LONGUEUR_CASE 50
#define LARGEUR_CASE 50
#define INVERSE_LONGUEUR_CASE (1.00/LONGUEUR_CASE)
#define INVERSE_LARGEUR_CASE (1.00/LARGEUR_CASE)


#define CASE_VIDE '1'
#define CASE_AVECMURINCASSABLE '2'
#define CASE_AVECMURCASSABLE '3'
#define CASE_AVECMALUS '4'
#define CASE_AVECBONUS_FLAMME '5'
#define CASE_AVECBONUS_ROLLER '6'
#define CASE_AVECBONUS_BOMBE '7'
#define CASE_AVECBOMBE '8'
#define CASE_ENFLAMMEE '9'
//il reste à définir les constantes des cases avec les différents bonus


/*-----------------------------------Maximum et Minimum-------------------------------------------------*/
#define MAX_BOMBE 6
#define MAX_PUISSANCE 6
#define MAX_SPEED 8


#define MIN_BOMBE 1
#define MIN_PUISSANCE 1
#define MIN_SPEED 2

/*-------------------------------------------Defaut-----------------------------------------------------*/

#define DEFAUT_BOMBE 1
#define DEFAUT_PUISSANCE 2
#define DEFAUT_SPEED 5
#define DEFAUT_SCORE 0

/*-----------------------------------------MALUS---------------------------------------------------*/

#define NB_MALUS 6

#define MALUS_RAPIDITE 9
#define MALUS_LENTEUR 1



/*------------------------------------------TEMPS----------------------------------------------------*/

#define TEMPS_BOMBE_DEFAUT 2.5
#define TEMPS_BOMBE_RAPIDE 1.5
#define TEMPS_BOMBE_LENTE 5

#define TEMPS_FLAMME 0.6

/** TEST **/
//#define NB_JOUEURS_MINI_FINPARTIE = 2
//Version partie normale
#define NB_JOUEURS_MINI_FINPARTIE = 1
//VErsion debug

#endif //Macro_h
