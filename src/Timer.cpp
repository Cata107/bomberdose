#include "Timer.h"




bool Timer::MStartTimer()
{
	m_timer.Reset();
    return true;
}

float Timer::MGetTime()

{
    return m_timer.GetElapsedTime();
}

bool Timer::MRestartTimer()
{
	m_timer.Reset();
    return true;
}
