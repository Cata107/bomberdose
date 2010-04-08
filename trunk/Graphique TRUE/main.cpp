#include <iostream>
#include "Screen.h"
#include "Animated.h"
#include "Events.h"
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "../client/Client.h"

int main(int argc, char ** argv)
{

    Screen s;
    Events ev(&(s.GetInput()), argv[1]);
    sf::Event real;
    Client myClient(argv[1], s.GetStruct());
    myClient.Launch();
    while(s.IsOpened()){
        if(myClient.MGetPointeurPartieEncours()){
        while(s.GetEvent(real)){
            if (real.Type == sf::Event::Closed){
                s.Close();
                myClient.Terminate();
            }
        }
        ev.Try(s.GetFrameTime());
        s.Refresh(s.GetStruct());
        s.Display();
        }
    }
    return 0;
}
