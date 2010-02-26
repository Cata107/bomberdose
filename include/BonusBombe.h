#ifndef BonusBombe_h
#define BonusBombe_h

#include "Joueur.h"
#include "ObjetBonus.h"


class BonusBombe : public ObjetBonus {

 public:

	BonusBombe(const sf::Vector2i _coodonnees);

	virtual bool MCreation();

    virtual bool MAppliquerEffet(Joueur& _joueur);
};

#endif // BonusBombe_h
