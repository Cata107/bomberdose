#ifndef BonusBombe_h
#define BonusBombe_h

//#include "Joueur.h"
#include "ObjetPrenable.h"


class BonusBombe : public ObjetPrenable {

 public:

	/* Constructeur */		BonusBombe(const sf::Vector2i _coodonnees);

		virtual ObjetFixe*	MClone() const;

};

#endif // BonusBombe_h
