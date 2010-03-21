#ifndef BomberDose_h
#define BomberDose_h

#include <vector>
#include <set>

#include "Joueur.h"
#include "Plateau.h"
#include "MurCassableAvecObjetPrenable.h"

class BomberDose {

 public:

	/* Constructeur */	BomberDose(int _nbJoueur,int _nbBonusBombe, int nbBonusFlamme, int _nbBonusRoller, int _nbMalus, int _score);

						~BomberDose();

    virtual bool		MCreatePlayer(int _nbJoueur);

	virtual bool		MCreateMursAvecObjet(int _nbBonusBombe, int nbBonusFlamme, int _nbBonusRoller, int _nbMalus);
		
    virtual Joueur*		MGetJoueur(int _indice);

			bool		MFinPartie();

			bool		MStart();

 public:

	Plateau*										m_pPlateau;

    std::vector< Joueur* >							m_tPJoueurs;

	std::vector< MurCassableAvecObjetPrenable* >	m_tPMursCassables;

	int												m_score;	//Score a atteindre pour gagner
};

#endif // BomberDose_h
