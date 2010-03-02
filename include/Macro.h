#ifndef Macro_h
#define Macro_h


//-----------------------------------Info du Plateau et Case---------------------------------------------


//nb de colonnes du plateau de jeu
#define NB_COLONNES 10
//nb de lignes du plateau de jeu
#define NB_LIGNES 8
//nb de case du plateau de jeu
#define NB_CASE (NB_COLONNES*NB_LIGNES)

//Taille d'une Case
#define LONGUEUR_CASE 1	//A remplacer par la vrai Longueur
#define LARGEUR_CASE 1	//A remplacer par la vrai Largeur


#define CASE_VIDE 0x01
#define CASE_AVECMURINCASSABLE 0x02
#define CASE_AVECMURCASSABLE 0x03
#define CASE_AVECMALUS 0x04
#define CASE_AVECBONUS_FLAMME 0x05
#define CASE_AVECBONUS_ROLLER 0x06
#define CASE_AVECBONUS_BOMBE 0x07
//il reste à définir les constantes des cases avec les différents bonus


/*-----------------------------------Maximum et Minimum-------------------------------------------------*/
#define MAX_BOMBE 6
#define MAX_PUISSANCE 6
#define MAX_SPEED 9


#define MIN_BOMBE 1
#define MIN_PUISSANCE 1
#define MIN_SPEED 1

/*-------------------------------------------Defaut-----------------------------------------------------*/

#define DEFAUT_BOMBE 1
#define DEFAUT_PUISSANCE 2
#define DEFAUT_SPEED 5
#define DEFAUT_SCORE 0

#endif //Macro_h
