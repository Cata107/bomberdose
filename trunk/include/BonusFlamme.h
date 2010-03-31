#ifndef BonusFlamme_h
#define BonusFlamme_h

//#include "Joueur.h"
#include "ObjetPrenable.h"


class BonusFlamme : public ObjetPrenable {

 public:
	
	/* Constructeur */		BonusFlamme(const sf::Vector2i _coordonnees);

		virtual ObjetFixe*	MClone() const;	//Permet de cloner le Bonus Flamme
};

#endif // BonusFlamme_h
