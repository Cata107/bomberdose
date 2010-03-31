#ifndef BonusRoller_h
#define BonusRoller_h

//#include "Joueur.h"
#include "ObjetPrenable.h"


class BonusRoller : public ObjetPrenable {

 public:
	
	/* Constructeur */		BonusRoller(const sf::Vector2i _coordonnees);

		virtual ObjetFixe*	MClone() const;

};

#endif // BonusRoller_h
