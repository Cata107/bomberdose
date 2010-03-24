#ifndef BomberDose_h
#define BomberDose_h

#include <vector>
#include <set>

#include "Joueur.h"
#include "Plateau.h"
#include "MurCassableAvecObjetPrenable.h"

class BomberDose {

 public:

	/* Constructeur */	BomberDose(int _nbJoueur,int _nbBonusBombe, int nbBonusFlamme, int _nbBonusRoller, int _nbMalus, int _score, int _temps);

	/* Destructeur */	~BomberDose();

    virtual bool		MCreatePlayer(int _nbJoueur);	

	virtual bool		MCreateMursAvecObjet(int _nbBonusBombe, int nbBonusFlamme, int _nbBonusRoller, int _nbMalus);
		
    virtual Joueur*		MGetJoueur(int _indice);	//Retourne le joueur a l'indice passe en parametre

			bool		MRecreerPlateau();			//Permet de recreer le plateau a chaque partie

			int			MFinMatch();				//Renvoi 1 si le match est gagn� par un joueur, 0 si match nul(tous mort, ou temps ecoule)
			
			Joueur*		MGetGagnant();				//Renvoi le pointeur sur le joueur Gagnant, uniquement si MFinMatch retourne 1 

			bool		MStart();

 public:

	Plateau*										m_pPlateau;		//Plateau de jeu

    std::vector< Joueur* >							m_tPJoueurs;	//Un vector qui contient les pointeurs sur les joueurs

	std::vector< MurCassableAvecObjetPrenable* >	m_tPMursCassables;	//Un vector qui contient les murs avec des objets

	int												m_nbBonus;

	int												m_temps;			//Temps limite d'un match

	int												m_score;	//Score a atteindre pour gagner

};

#endif // BomberDose_h