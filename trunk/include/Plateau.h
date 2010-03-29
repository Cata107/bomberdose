#ifndef Plateau_h
#define Plateau_h

#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <algorithm>
#include "Case.h"
#include "MurCassableAvecObjetPrenable.h"
#include "MurIncassable.h"
#include "Timer.h"
#include "Macro.h"
#include "Bombe.h"
#include "Flamme.h"
#include "BonusBombe.h"
#include "BonusFlamme.h"
#include "BonusRoller.h"
#include "ObjetMalus.h"
class Joueur;

class Plateau {

 public:

 /*	Constructeur */	Plateau(std::vector<MurCassableAvecObjetPrenable*>& _listeMurCassableAvecObjetPrenable, int _nbBonus);

 /* Destructeur */ 	~Plateau();

			bool	MCreation();

			bool	MDestruction();

			bool	MPlacerMursIncassables();

			bool	MPlacerMursIncassablesBord();

			bool	MPlacerMursIncassablesMilieu();

			bool	MPlacerMursCassables();

			Case*	MGetCase(const sf::Vector2i _coordonnees);				//Renvoi un poiteur sur la case, dont les coordonnees sont en parametre

			Case*	MGetCase(int _coordonneeUniDimensionelle);

			Case*	MGetPlateau();

			char*	MGetPlateauConverti();

			Timer*	MGetTimer();

			bool	MSetBombe(sf::Vector2i _coordonnees, int _puissance, int indiceJoueur, int _maladie = 0);	//Permet de placer une bombe sur les coordonnees de la case en parametre

			bool	MSetJoueurs(std::vector< Joueur* >& _listJoueur);

			bool	MCreerFlamme(sf::Vector2i& _coordonnees, int _puissance);

			bool	MCreerFlammeHaut(sf::Vector2i& _coordonnees, int _puissance);

			bool	MCreerFlammeBas(sf::Vector2i& _coordonnees, int _puissance);

			bool	MCreerFlammeGauche(sf::Vector2i& _coordonnees, int _puissance);

			bool	MCreerFlammeDroite(sf::Vector2i& _coordonnees, int _puissance);

			bool	MDestructionObjetFixe(ObjetFixe* _objetFixe);

			bool	MUpdate();


 protected:

			Case*					m_tCase;

			Timer*					m_pTimer;

			std::list<Bombe*>		m_listPBombes;			//La liste de bombes posees par les joueurs

			std::list<Flamme*>		m_listPFlammes;			//Liste des cases enflammee

			std::vector<MurCassable*>	m_listPMursCassables;	//La liste des murs cassables pour la construction du plateau

			std::set<int>			m_setIndiceCaseVide;	//L'ensemble des cases vides

			std::vector<Joueur*>	m_listJoueurs;
};

#endif // Plateau_h
