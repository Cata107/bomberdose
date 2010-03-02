#ifndef MurIncassable_h
#define MurIncassable_h

#include "Mur.h"


class MurIncassable : public Mur {

 public:

	/* Constructeur */	MurIncassable(sf::Vector2i _coordonnees);

		virtual bool	MCreation();

		virtual bool	MDestruction();
};

#endif // MurIncassable_h
