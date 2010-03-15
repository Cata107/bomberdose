#ifndef MurIncassable_h
#define MurIncassable_h

#include "ObjetFixe.h"


class MurIncassable : public ObjetFixe {

 public:

	/* Constructeur */	MurIncassable(sf::Vector2i _coordonnees);

		virtual bool	MCreation();

		virtual bool	MDestruction();
};

#endif // MurIncassable_h
