#ifndef ObjetBonus_h
#define ObjetBonus_h

#include "Joueur.h"
#include "ObjetPrenable.h"


class ObjetBonus : public ObjetPrenable {

 public:

    virtual bool MDestruction();

    virtual bool MAppliquerEffet(Joueur _joueur)  = 0;
};

#endif // ObjetBonus_h
