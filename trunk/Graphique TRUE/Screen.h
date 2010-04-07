#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED
#include <iostream>
#include <string>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "../client/ToClient.h"
//#include "..\client\Client.h"
//#include "..\include\Macro.h"
//#include "Joueur.h"
//#include "TestStruct.h"

class Screen : public sf::RenderWindow
{

public :

    Screen(/*sf::VideoMode v, std::string name*/);
    ~Screen();
    void Refresh(ToClient* fromServ);
    void Wall(ToClient* fromServ);
    int XPos(int i);
    int YPos(int i);
    void SetPosPlayer(ToClient* fromServ);

    ToClient* GetStruct();
//    void SetPosPlayer(Joueur* j1);



private :
    std::string hasard;
    sf::Sprite fond;
    sf::Image imageFond;
    sf::Image img;
    sf::Image whiteBomberIMG;
    sf::Sprite whiteBomber;
    sf::Image m_cassable;
    sf::Image m_incassable;
    sf::Sprite* m_listSprites;

    sf::Sprite j1;
    sf::Sprite j2;
    sf::Sprite j3;
    sf::Sprite j4;

    ToClient m_fromServ;


};


#endif // SCREEN_H_INCLUDED
