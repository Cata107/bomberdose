#ifndef Plateau_h
#define Plateau_h

#include <iostream>
#include <list>
#include "Case.h"
#include "MurCassableAvecObjetPrenable.h"
#include "MurIncassable.h"
#include "Timer.h"
#include "Macro.h"
#include "Bombe.h"

class Plateau {

 public:

 /*	Constructeur */	Plateau();
    
			bool	MCreation(MurCassableAvecObjetPrenable _listeMurCassableAvecObjetPrenable);

			bool	MDestruction();

			bool	MSetBombe(sf::Vector2i coordonnees);

			bool	MPlacerMursIncassables();

			bool	MPlacerMursIncassablesBord();

			bool	MPlacerMursIncassablesMilieu();

			bool	MPlacerMursCassables(MurCassableAvecObjetPrenable _listMurCassableAvecObjetPrenable);

			Case	MGetCase(sf::Vector2i _coordonnees);

			Case	MGetCase(int _coordonneeUniDimensionelle);

			Case	MGetPlateau();

			int*	MGetPlateauConverti();


 protected:

			Case*				m_tCase;

			Timer				m_timer;

			std::list<Bombe*>	m_listBombes;
};

#endif // Plateau_h
