#ifndef Flamme_h
#define Flamme_h

#include "ObjetFixe.h"


class Flamme : public ObjetFixe {

 public:
	
	/* Constructeur */		Flamme(const sf::Vector2i _coordonnees);

		virtual bool		MCreation();

		virtual ObjetFixe*	MClone() const;

		virtual bool		MDestruction();

 public:

				
};

#endif // Flamme_h
