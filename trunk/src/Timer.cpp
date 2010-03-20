#include "Timer.h"

Timer::Timer()
{
	m_pTimer = new sf::Clock();
}

Timer::~Timer()
{
	delete m_pTimer;
}

//Demarre le Timer
bool Timer::MStartTimer()
{
	m_pTimer->Reset();
    return true;
}

//Recupere le temps depuis la creation
float Timer::MGetTime()

{
    return m_pTimer->GetElapsedTime();
}
