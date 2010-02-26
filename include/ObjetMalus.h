#ifndef ObjetMalus_h
#define ObjetMalus_h

#include "Joueur.h"
#include "ObjetPrenable.h"


class ObjetMalus : public ObjetPrenable {

 public:

    virtual bool MDestruction();

    virtual bool MAppliquerEffet(Joueur _joueur);
};

#endif // ObjetMalus_h
