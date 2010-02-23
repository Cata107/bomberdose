#ifndef MurCassable_h
#define MurCassable_h

#include "Mur.h"
#include "ObjetCassable.h"


class MurCassable : public Mur, public ObjetCassable {

 public:

    virtual bool MCreation();

    virtual bool MDestruction()  = 0;
};

#endif // MurCassable_h
