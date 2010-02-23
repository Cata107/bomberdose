#ifndef Flamme_h
#define Flamme_h

#include "ObjetFixe.h"
#include "Timer.h"


class Flamme : public ObjetFixe {

 public:

    virtual bool MCreation();

    virtual bool MDestruction();

 public:

    Timer myTimer;
};

#endif // Flamme_h
