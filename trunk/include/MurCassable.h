#ifndef MurCassable_h
#define MurCassable_h

#include "ObjetFixe.h"


class MurCassable : public ObjetFixe {

 public:
							MurCassable();

	/*Constructeur */		MurCassable(sf::Vector2i _coordonnees);

		virtual ObjetFixe*	MClone() const;
    
		virtual bool		MCreation();

		virtual bool		MDestruction();

		virtual bool		MSetCoordonnees(sf::Vector2i _coordonnees);
};

#endif // MurCassable_h
