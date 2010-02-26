#ifndef Plateau_h
#define Plateau_h

#include "Case.h"
#include "MurCassableAvecObjetPrenable.h"
#include "Timer.h"
#include "Macro.h"

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

    int * MGetPlateauConverti();


 protected:

    Case* m_Case;

    Timer m_timer;
};

#endif // Plateau_h
