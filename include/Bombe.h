#ifndef Bombe_h
#define Bombe_h
#include "ObjetFixe.h"

class Bombe : public ObjetFixe {

 public:

	/* Constructeur */	Bombe(const sf::Vector2i _coordonnees);

		virtual bool		MCreation();

		virtual ObjetFixe*	MClone() const;

		virtual bool		MDestruction();

 protected:
		int				m_puissance;
};

#endif // Bombe_h
