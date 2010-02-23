#ifndef BonusBombe_h
#define BonusBombe_h

#include "Joueur.h"
#include "ObjetBonus.h"


class BonusBombe : public ObjetBonus {

 public:

    virtual bool MAppliquerEffet(Joueur _joueur);
};

#endif // BonusBombe_h
