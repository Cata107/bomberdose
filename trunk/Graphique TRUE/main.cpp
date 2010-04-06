#include <iostream>
#include "Screen.h"
#include "Animated.h"
#include "Events.h"
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Client.h"


int main()
{

    Screen s;

    Anim first;
    first.PushFrame(sf::IntRect(0,0,20,20));
    first.PushFrame(sf::IntRect(10,0,30,20));

    Anim second;
    second.PushFrame(sf::IntRect(10,10,30,30));
    second.PushFrame(sf::IntRect(20,20,40,40));

    sf::Image img;
    img.LoadFromFile("bombermanBlanc copy.png");

    Animated test(0.5f);
    test.SetImage(img);
    test.SetAnim(&first);
    test.SetRect(0);
    test.SetPosition(10,10);


    Events ev(&(s.GetInput()), &test, &first, &second);

    sf::Event real;

    /*
    Client myClient("127.0.0.1", s.GetStruct());
    myClient.MAfficherStatus();
    myClient.MConnect();
    myClient.MAttenteInstruction();
    */


    while(s.IsOpened()){

        while(s.GetEvent(real)){
            if (real.Type == sf::Event::Closed){
                s.Close();
            }
        }
        ev.Try(s.GetFrameTime());

        s.Refresh(s.GetStruct());
        s.Display();

    }


    return 0;
}
