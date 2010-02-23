#ifndef Timer_h
#define Timer_h

#include "Bombe.h"

class Plateau;
class Flamme;

class Timer {

 public:

    virtual bool MStartTimer();

    virtual float MGetTime();

    virtual bool MRestartTimer();


 protected:
    null m_timer;

 public:

    Plateau *myPlateau;

    Bombe myBombe;

    Bombe *myBombe;

    Flamme *myFlamme;
};

#endif // Timer_h
