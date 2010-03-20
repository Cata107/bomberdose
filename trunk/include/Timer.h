#ifndef Timer_h
#define Timer_h

#include <SFML/System.hpp>

class Timer {

 public:

	/* Constructeur */			Timer();

	/* Destructeur */			~Timer();

    virtual bool				MStartTimer();

    virtual float				MGetTime();


 protected:

		sf::Clock*	m_pTimer;

};

#endif // Timer_h
