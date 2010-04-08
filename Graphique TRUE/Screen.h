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

    sf::Sprite fond;

    sf::Image imageFond;

    sf::Image whiteBomberIMG;
    sf::Image m_cassable;
    sf::Image m_incassable;
    sf::Image m_bombe;
    sf::Image m_flamme;
    sf::Image m_bonusRoller;
    sf::Image m_bonusBombe;
    sf::Image m_bonusFlamme;
    sf::Image m_malus;

    // Les images des joueurs
    sf::Image joueur1;
    sf::Image joueur2;
    sf::Image joueur3;
    sf::Image joueur4;

    // Les sprites des joueurs
    sf::Sprite j1;
    sf::Sprite j2;
    sf::Sprite j3;
    sf::Sprite j4;


    sf::Sprite* m_listSprites; // Tableau de sprite correspondant au plateau


    ToClient m_fromServ;


};


#endif // SCREEN_H_INCLUDED
