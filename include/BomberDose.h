#ifndef BomberDose_h
#define BomberDose_h

#include <vector>

#include "Joueur.h"
#include "Plateau.h"
#include "MurCassableAvecObjetPrenable.h"

class BomberDose {

 public:

    virtual bool	MCreatePlayer(std::vector< Joueur* >& _joueurs, Plateau* _plateau);

	virtual bool	MCreateMursAvecObjet();

    virtual bool	MGetJoueur(int _indice);

 public:

	Plateau*										m_pPlateau;

    std::vector< Joueur* >							m_tPJoueur;

	std::vector< MurCassableAvecObjetPrenable* >	m_tPMursCassable;
};

#endif // BomberDose_h
