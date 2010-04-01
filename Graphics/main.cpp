#include <iostream>
#include "Screen.h"
#include "Animated.h"
#include "Events.h"
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


int main()
{

    Screen s;

    sf::Image img;
    img.LoadFromFile("bombermanBlanc copy.png");

    Anim first;
    first.PushFrame(sf::IntRect(0,0,20,20));
    first.PushFrame(sf::IntRect(10,0,30,20));

    Anim second;
    second.PushFrame(sf::IntRect(10,10,30,30));
    second.PushFrame(sf::IntRect(20,20,40,40));

    Animated test(0.5f);
    test.SetImage(img);
    test.SetAnim(&first);
    test.SetRect(0);

     sf::Sprite fond;
     fond.SetColor(sf::Color::Black);

     Events ev(&(s.GetInput()), &test, &first, &second);

    sf::Event real;

    while(s.IsOpened()){


        while(s.GetEvent(real)){
            if (real.Type == sf::Event::Closed){
                s.Close();
            }
        }
        std::cout<<"FRAME TIME MAIN : "<<s.GetFrameTime()<<std::endl;
        ev.Try(s.GetFrameTime());

        s.Clear();
        s.Draw(fond);

        test.anim(s.GetFrameTime());


        s.Draw(test);
        s.Display();


    }









    return 0;
}
