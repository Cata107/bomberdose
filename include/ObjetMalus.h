#ifndef ObjetMalus_h
#define ObjetMalus_h

//#include "Joueur.h"
#include "ObjetPrenable.h"


class ObjetMalus : public ObjetPrenable {

 public:

	/* Constructeur */		ObjetMalus(const sf::Vector2i _coordonnees);

		virtual bool		MCreation();

		virtual ObjetFixe*	MClone() const;

		virtual bool		MDestruction();

		//virtual bool	MAppliquerEffet(Joueur& _joueur);
};

#endif // ObjetMalus_h
