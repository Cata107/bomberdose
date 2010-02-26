#ifndef Mur_h
#define Mur_h

#include "ObjetFixe.h"


class Mur : public ObjetFixe {

 public:

	Mur(sf::Vector2i _coordonnees);

    virtual bool MCreation() = 0;
};

#endif // Mur_h
