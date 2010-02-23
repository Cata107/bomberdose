#ifndef Bombe_h
#define Bombe_h

#include "ObjetFixe.h"
#include "Timer.h"


class Bombe : public ObjetFixe {

 public:

    virtual bool MCreation();

    virtual bool MDestruction();


 protected:
    int m_puissance;

 public:

    Timer *myTimer;

    Timer myTimer;
};

#endif // Bombe_h
