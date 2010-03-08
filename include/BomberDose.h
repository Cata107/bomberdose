#ifndef BomberDose_h
#define BomberDose_h

#include <vector>

#include "Joueur.h"
#include "Plateau.h"

class BomberDose {

 public:

    virtual bool	MCreatePlayer(Joueur _joueurs, Plateau _plateau);

    virtual bool	MGetJoueur(int _indice);

 public:

	Plateau					*myPlateau;

    std::vector< Joueur* >	myJoueur;
};

#endif // BomberDose_h
