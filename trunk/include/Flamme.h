#ifndef Flamme_h
#define Flamme_h

#include "ObjetFixe.h"


class Flamme : public ObjetFixe {

 public:
	
	/* Constructeur */		Flamme(const sf::Vector2i _coordonnees);

		virtual ObjetFixe*	MClone() const;	//Clone l'objet

 public:

				
};

#endif // Flamme_h
