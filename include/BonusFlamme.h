#ifndef BonusFlamme_h
#define BonusFlamme_h

#include "Joueur.h"
#include "ObjetBonus.h"


class BonusFlamme : public ObjetBonus {

 public:

    virtual bool MAppliquerEffet(Joueur _joueur);
};

#endif // BonusFlamme_h
