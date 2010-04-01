#include "Screen.h"

Screen::Screen(/*sf::VideoMode v, std::string s*/) :
    sf::RenderWindow(sf::VideoMode(800,600), "try")
{
    SetFramerateLimit(60);
    img.LoadFromFile("cute_image.jpg");
    whiteBomberIMG.LoadFromFile("bombermanBlanc copy.png");
   // fond.SetImage(img);
    fond.SetColor(sf::Color(255,255,255,255));
    whiteBomber.SetImage(whiteBomberIMG);
    whiteBomber.SetSubRect(sf::IntRect(20,20,50,50));
    whiteBomber.SetPosition(100,100);

}
 Screen::~Screen(){
 }



 int Screen::Disp()
 {
    Clear();
    Draw(fond);
    Wall();
    Display();




        return 0;
 }

 void Screen::Wall(){
  //  Get
    Draw(whiteBomber);

 }






