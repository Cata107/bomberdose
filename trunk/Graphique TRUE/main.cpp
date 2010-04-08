#include <iostream>
#include "Screen.h"
#include "Animated.h"
#include "Events.h"
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "../client/Client.h"
#include "BomberDose.h";
//#include "TestStruct.h"


int main(int argc, char ** argv)
{

    Screen s;
    /*
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
    */

    Events ev(&(s.GetInput()), argv[1])/*, &test, &first, &second)*/;

    sf::Event real;

    /*
    BomberDose* bomberdose = new BomberDose(4, 5, 5, 5, 3, 5, 5);
    char* ppp;
    ppp=new char[196];
    ppp=bomberdose->MGetPlateau()->MGetPlateauConverti();
    TestStruct xx;
    xx.plateau=bomberdose->MGetPlateau()->MGetPlateauConverti();
    std::cout<<xx.plateau<<std::endl;
    */

    Client myClient(argv[1], s.GetStruct());
    /*
    myClient.MAfficherStatus();
    myClient.MConnect();
    myClient.MAttenteInstruction();
    */
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
