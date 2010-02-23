#ifndef Timer_h
#define Timer_h

#include <sfml/System.hpp>

class Timer {

 public:

    virtual bool MStartTimer();

    virtual float MGetTime();

    virtual bool MRestartTimer();


 protected:

	sf::Clock m_timer;

};

#endif // Timer_h
