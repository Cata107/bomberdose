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

class Plateau {

 public:

 /*	Constructeur */	Plateau(std::vector<MurCassableAvecObjetPrenable>& _listeMurCassableAvecObjetPrenable);
    
			bool	MCreation();

			bool	MDestruction();

			bool	MSetBombe(sf::Vector2i _coordonnees, int _puissance);

			bool	MPlacerMursIncassables();

			bool	MPlacerMursIncassablesBord();

			bool	MPlacerMursIncassablesMilieu();

			bool	MPlacerMursCassables();

			Case	MGetCase(sf::Vector2i _coordonnees);

			Case	MGetCase(int _coordonneeUniDimensionelle);

			Case*	MGetPlateau();

			int*	MGetPlateauConverti();


 protected:

			Case*					m_tCase;

			Timer					m_timer;

			std::list<Bombe*>		m_listPBombes;			//La liste de bombes posees par les joueurs

			std::vector<MurCassable*>	m_listPMursCassables;	//La liste des murs cassables pour la construction du plateau

			std::set<int>			m_setIndiceCaseVide;	//L'ensemble des cases vides
};

#endif // Plateau_h
