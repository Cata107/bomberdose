#include "Screen.h"
#define HAUTEUR 50
#define LARGEUR 50
#include "BomberDose.h"


Screen::Screen(/*sf::VideoMode v, std::string s*/) :
    sf::RenderWindow(sf::VideoMode(13*50,15*50), "try"), imageFond(1000,900,sf::Color::Green), m_cassable(LARGEUR, HAUTEUR,sf::Color(51,51,51)),
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

 void Screen::Refresh(ToClient* fromServ)
 {
 // Rafraichit la fenètre
    Clear();
    Draw(fond);
    Wall(fromServ);
    SetPosPlayer(fromServ);


 }

void Screen::Wall(ToClient* fromServ){
	// Place les murs selon de tableau de char
    /*
    *   Partie test
    */
//    BomberDose* bomberdose = new BomberDose(4, 5, 5, 5, 3, 5, 5);
//    char* ppp;
//    ppp=new char[196];
//    ppp=bomberdose->MGetPlateau()->MGetPlateauConverti();
//    Joueur* j1=bomberdose->MGetJoueur(0);
//    Joueur* j2=bomberdose->MGetJoueur(1);
//    Joueur* j3=bomberdose->MGetJoueur(2);
//    Joueur* j4=bomberdose->MGetJoueur(3);

//    SetPosPlayer(j1);
//    SetPosPlayer(j2);
//    SetPosPlayer(j3);
//    SetPosPlayer(j4);


    bool passe=false;
    /*
    *   Fin partie test
    */

    for(int i=0; i<(15*13);i++){
        if(fromServ->plateau[i]==CASE_AVECMURCASSABLE){
            m_listSprites[i].SetImage(m_cassable);
            m_listSprites[i].SetPosition(XPos(i), YPos(i));
            Draw(m_listSprites[i]);
        }
        else if(fromServ->plateau[i]==CASE_AVECMURINCASSABLE){
            m_listSprites[i].SetImage(m_incassable);
            m_listSprites[i].SetPosition(XPos(i), YPos(i));

          Draw(m_listSprites[i]);
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

void Screen::SetPosPlayer(ToClient* fromServ){
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
/*
void Screen::SetPosPlayer(Joueur* jj1){

//    j1.SetPosition(jj1->MGetPositionPixel().x-25, jj1->MGetPositionPixel().y-25);
//    j1.Resize(50,50);
//    Draw(j1);


}
*/

int Screen::XPos(int i){
    return (i%15) * LARGEUR;
 }
int Screen::YPos(int i){
    return (i/15)* HAUTEUR;
 }

ToClient* Screen::GetStruct(){
// Retourne la structure
    return &m_fromServ;
}





