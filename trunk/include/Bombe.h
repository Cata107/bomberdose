#ifndef Bombe_h
#define Bombe_h
#include "ObjetFixe.h"

class Bombe : public ObjetFixe {

 public:

	/* Constructeur */				Bombe(const sf::Vector2i _coordonnees);

	/* Destructeur */ virtual		~Bombe();

		virtual bool				MCreation();

		virtual ObjetFixe*			MClone() const;	//Permet de cloner une bombe

		virtual bool				MDestruction();

 protected:

		int							m_puissance;	//La puissance de la bombe
};

#endif // Bombe_h
