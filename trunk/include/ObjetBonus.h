#ifndef ObjetBonus_h
#define ObjetBonus_h

#include "Joueur.h"
#include "ObjetPrenable.h"


class ObjetBonus : public ObjetPrenable {

 public:

	/* Constructeur */	ObjetBonus(const sf::Vector2i _coordonnees);

		virtual bool	MCreation() = 0;
	
		virtual bool	MDestruction();

		virtual bool	MAppliquerEffet(Joueur& _joueur)  = 0;
};

#endif // ObjetBonus_h
