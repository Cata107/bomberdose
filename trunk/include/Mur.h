#ifndef Mur_h
#define Mur_h

#include "ObjetFixe.h"


class Mur : public ObjetFixe {

 public:

    virtual bool MCreation();

    virtual bool MDestruction()  = 0;
};

#endif // Mur_h
