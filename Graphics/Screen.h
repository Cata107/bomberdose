#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED
#include <iostream>
#include <string>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


class Screen : public sf::RenderWindow
{

public :

    Screen(/*sf::VideoMode v, std::string name*/);
    ~Screen();
    int Disp();
    void Wall();



private :
    std::string hasard;
    sf::Sprite fond;
    sf::Image img;
    sf::Image whiteBomberIMG;
    sf::Sprite whiteBomber;


};


#endif // SCREEN_H_INCLUDED
