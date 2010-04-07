#ifndef EVENTS_H_INCLUDED
#define EVENTS_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Screen.h"
#include "Animated.h"
#include "../client/Envoi.h"
#include "../client/ToServer.h"

class Events{

    public :

        Events(const sf::Input *i, Animated *a, Anim *first, Anim *second);
        ~Events();
        void Try(float Ftime);
        void Try2();

    private :

        const sf::Input* m_input;
        const sf::Event* m_event;
        Animated* m_animated;

        sf::Clock* m_timer;

        Anim* m_first;
        Anim* m_second;

        Envoi envoi;

};


#endif // EVENTS_H_INCLUDED
