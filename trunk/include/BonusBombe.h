#ifndef BonusBombe_h
#define BonusBombe_h

//#include "Joueur.h"
#include "ObjetPrenable.h"


class BonusBombe : public ObjetPrenable {

 public:

	/* Constructeur */		BonusBombe(const sf::Vector2i _coodonnees);

		virtual bool		MCreation();

		virtual ObjetFixe*	MClone() const;


		//virtual bool		MAppliquerEffet(Joueur& _joueur);
};

#endif // BonusBombe_h
