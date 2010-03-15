#ifndef MurCassable_h
#define MurCassable_h

#include "ObjetFixe.h"


class MurCassable : public ObjetFixe {

 public:

	/*Constructeur */	MurCassable(sf::Vector2i _coordonnees);
    
		virtual bool	MCreation();

		virtual bool	MDestruction()  = 0;
};

#endif // MurCassable_h
