#ifndef ObjetMalus_h
#define ObjetMalus_h

#include "Joueur.h"
#include "ObjetCassableEtPrennable.h"


class ObjetMalus : public ObjetCassableEtPrennable {

 public:

    virtual bool MDestruction();

    virtual bool MAppliquerEffet(Joueur _joueur);
};

#endif // ObjetMalus_h
