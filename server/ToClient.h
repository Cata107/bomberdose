#ifndef ToClient_h
#define ToClient_h
#include <iostream>
#include "../include/Macro.h"
struct ToClient
{
    char* plateau;
    //Le plateau de jeu représenté par un tableau de char pour simplicité d'envoi
    bool j1;
    //L'état du joueur1 : true = vivant, false = mort
	unsigned int x1;
	//l'abscisse du joueur 1
    unsigned int y1;
    //l'ordonnée du joueur 1
    bool j2;
    unsigned int x2;
    unsigned int y2;
    bool j3;
    unsigned int x3;
    unsigned int y3;
    bool j4;
    unsigned int x4;
    unsigned int y4;
};
#endif //ToClient_h
