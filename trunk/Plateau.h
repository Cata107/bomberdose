#ifndef Plateau_h
#define Plateau_h

#include "Case.h"
#include "MurCassableAvecObjetPrenable.h"
#include "Timer.h"

class BomberDose;

class Plateau {

 public:

    virtual bool MCreation(MurCassableAvecObjetPrenable _listeMurCassableAvecObjetPrenable);

    virtual bool MDestruction();

    virtual bool MSetBombe();

    virtual bool MPlacerMursIncassables();

    virtual bool MPlacerMursCassables(MurCassableAvecObjetPrenable _listMurCassableAvecObjetPrenable);

    virtual Case getCase(void _coordonnees);

    virtual Case MGetPlateau();

 public:

    Case myCase;

    Timer myTimer;

    BomberDose *myBomberDose;
};

#endif // Plateau_h
