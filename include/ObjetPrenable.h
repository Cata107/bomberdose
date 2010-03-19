#ifndef ObjetPrenable_h
#define ObjetPrenable_h

class Joueur;
#include "ObjetFixe.h"


class ObjetPrenable : public ObjetFixe {

 public:

	/* Constructeur */	ObjetPrenable(const sf::Vector2i _coordonnees);

		virtual	bool	MCreation() = 0;

		virtual bool	MObjetPris();

		virtual bool	MDestruction();

		virtual bool	MAppliquerEffet(Joueur& _joueur);
};
#endif // ObjetPrenable_h
