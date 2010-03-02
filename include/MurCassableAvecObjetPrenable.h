#ifndef MurCassableAvecObjetPrenable_h
#define MurCassableAvecObjetPrenable_h

#include "MurCassable.h"


class MurCassableAvecObjetPrenable : public MurCassable {

 public:

	/*Constructeur */	MurCassableAvecObjetPrenable(sf::Vector2i _coordonnees);

		virtual bool	MCreation();

		virtual bool	MDestruction();
};

#endif // MurCassableAvecObjetPrenable_h
