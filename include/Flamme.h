#ifndef Flamme_h
#define Flamme_h

#include "ObjetFixe.h"
#include "Timer.h"


class Flamme : public ObjetFixe {

 public:
	
	Flamme(const sf::Vector2i _coordonnees);

    virtual bool MCreation();

    virtual bool MDestruction();

 public:

    Timer m_timer;
};

#endif // Flamme_h
