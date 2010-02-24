#include "Timer.h"



//Demarre le Timer
bool Timer::MStartTimer()
{
	m_timer.Reset();
    return true;
}

//Recupere le temps depuis la creation
float Timer::MGetTime()

{
    return m_timer.GetElapsedTime();
}

//Recommence le Timer
bool Timer::MRestartTimer()
{
	m_timer.Reset();
    return true;
}
