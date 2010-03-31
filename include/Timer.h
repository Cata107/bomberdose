#ifndef Timer_h
#define Timer_h

#include <SFML/System.hpp>

class Timer {

 public:

	/* Constructeur */			Timer();

	/* Destructeur */			~Timer();

    virtual bool				MStartTimer();	//Demarrer le timer

    virtual float				MGetTime();		//Recuperer le temps ecoule depuis le demarrage


 protected:

		sf::Clock*	m_pTimer;		//Un objet de type sf::Clock qui permet de gerer le temps

};

#endif // Timer_h
