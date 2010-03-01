#ifndef Plateau_h
#define Plateau_h

#include <iostream>
#include <list>
#include "Case.h"
#include "MurCassableAvecObjetPrenable.h"
#include "Timer.h"
#include "Macro.h"
#include "Bombe.h"

class Plateau {

 public:

    virtual bool MCreation(MurCassableAvecObjetPrenable _listeMurCassableAvecObjetPrenable);

    virtual bool MDestruction();

    virtual bool MSetBombe(sf::Vector2i coordonnees);

    virtual bool MPlacerMursIncassables();

    virtual bool MPlacerMursCassables(MurCassableAvecObjetPrenable _listMurCassableAvecObjetPrenable);

	virtual Case MGetCase(sf::Vector2i _coordonnees);

	Case MGetCase(int _coordonneeUniDimensionelle);


    virtual Case MGetPlateau();

    int* MGetPlateauConverti();


 protected:

    Case* m_Case;

    Timer m_timer;

	std::list<Bombe*> m_listBombes;
};

#endif // Plateau_h
