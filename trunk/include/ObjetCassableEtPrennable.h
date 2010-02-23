#ifndef ObjetCassableEtPrennable_h
#define ObjetCassableEtPrennable_h

#include "ObjetCassable.h"
#include "ObjetPrenable.h"


class ObjetCassableEtPrennable : public ObjetCassable, public ObjetPrenable {

 public:

    virtual bool MCreation();

    virtual bool MObjetPris();

    virtual bool MDestruction()  = 0;

    virtual bool MAppliquerEffetObjet()  = 0;
};

#endif // ObjetCassableEtPrennable_h
