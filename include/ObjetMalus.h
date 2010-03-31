#ifndef ObjetMalus_h
#define ObjetMalus_h

//#include "Joueur.h"
#include "ObjetPrenable.h"


class ObjetMalus : public ObjetPrenable {

 public:

	/* Constructeur */		ObjetMalus(const sf::Vector2i _coordonnees);

		virtual ObjetFixe*	MClone() const;	//Permet de cloner l'objet malus

		
};

#endif // ObjetMalus_h
