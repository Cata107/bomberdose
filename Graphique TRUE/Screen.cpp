#include "Screen.h"
#define HAUTEUR 50
#define LARGEUR 50


Screen::Screen(/*sf::VideoMode v, std::string s*/) :
    sf::RenderWindow(sf::VideoMode(800,600), "try"), imageFond(800,600,sf::Color::Green), m_cassable(LARGEUR, HAUTEUR,sf::Color(51,51,51)),
    m_incassable(LARGEUR,HAUTEUR,sf::Color(0,0,51))
{
    SetFramerateLimit(60);
    fond.SetImage(imageFond);
    m_listSprites=new sf::Sprite[15*13];

    whiteBomberIMG.LoadFromFile("bombermanBlanc copy.png");
    whiteBomber.SetImage(whiteBomberIMG);

    j1.SetImage(whiteBomberIMG);
    j1.SetSubRect(sf::IntRect(6.26,7.14,9.22,10.28));

    j2.SetImage(whiteBomberIMG);
    j2.SetSubRect(sf::IntRect(6.26,7.14,9.22,10.28));

    j3.SetImage(whiteBomberIMG);
    j3.SetSubRect(sf::IntRect(6.26,7.14,9.22,10.28));

    j4.SetImage(whiteBomberIMG);
    j4.SetSubRect(sf::IntRect(6.26,7.14,9.22,10.28));


}
 Screen::~Screen(){
 }

 void Screen::Refresh(const ToClient* fromServ)
 {
 // Rafraichit la fenètre
    Clear();
    Draw(fond);
    Wall(fromServ);
    SetPosPlayer(fromServ);


 }

void Screen::Wall(const ToClient* fromServ){
	// Place les murs selon de tableau de char
    for(int i=0; i<(15*13);i++){
        if(fromServ->plateau[i]==CASE_AVECMURCASSABLE){
            m_listSprites[i].SetImage(m_cassable);
            m_listSprites[i].SetPosition(XPos(i), YPos(i));
        }
        else if(fromServ->plateau[i]==CASE_AVECMURINCASSABLE){
            m_listSprites[i].SetImage(m_incassable);
            m_listSprites[i].SetPosition(XPos(i), YPos(i));
        }
        else if(fromServ->plateau[i]==CASE_AVECMALUS){
        }
        else if(fromServ->plateau[i]==CASE_AVECBONUS_FLAMME){
        }
        else if(fromServ->plateau[i]==CASE_AVECBONUS_BOMBE){
        }
        else if(fromServ->plateau[i]==CASE_AVECBONUS_ROLLER){
        }
        else if(fromServ->plateau[i]==CASE_AVECBOMBE){
        }
        else if(fromServ->plateau[i]==CASE_ENFLAMMEE){
        }
    }

 }

void Screen::SetPosPlayer(const ToClient* fromServ){
// Place les joueurs sur le terrain

    if(fromServ->j1){
        j1.SetPosition(fromServ->x1,fromServ->y1);
        Draw(j1);
    }
    if(fromServ->j2){
        j2.SetPosition(fromServ->x2,fromServ->y2);
        Draw(j2);
    }
    if(fromServ->j3){
        j3.SetPosition(fromServ->x3,fromServ->y3);
        Draw(j3);
    }
    if(fromServ->j4){
        j4.SetPosition(fromServ->x4,fromServ->y4);
        Draw(j4);
    }

}


int Screen::XPos(int i){
    return (i/(13*15)) * LARGEUR;
 }
int Screen::YPos(int i){
    return (i%15)*50;
 }

ToClient* Screen::GetStruct(){
// Retourne la structure
    return &m_fromServ;
}





