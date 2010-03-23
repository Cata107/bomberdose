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

	/* Destructeur */	~BomberDose();

    virtual bool		MCreatePlayer(int _nbJoueur);	

	virtual bool		MCreateMursAvecObjet(int _nbBonusBombe, int nbBonusFlamme, int _nbBonusRoller, int _nbMalus);
		
    virtual Joueur*		MGetJoueur(int _indice);	//Retourne le joueur a l'indice passe en parametre

			bool		MRecreerPlateau();			//Permet de recreer le plateau a chaque partie

			bool		MFinPartie();

			bool		MStart();

 public:

	Plateau*										m_pPlateau;		//Plateau de jeu

    std::vector< Joueur* >							m_tPJoueurs;	//Un vector qui contient les pointeurs sur les joueurs

	std::vector< MurCassableAvecObjetPrenable* >	m_tPMursCassables;	//Un vector qui contient les murs avec des objets

	int												m_nbBonus;

	int												m_score;	//Score a atteindre pour gagner

};

#endif // BomberDose_h
