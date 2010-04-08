#include "Screen.h"
#define HAUTEUR 50
#define LARGEUR 50
#include "../client/MacroClient.h";

Screen::Screen() :
    sf::RenderWindow(sf::VideoMode(15*50,13*50), "BomberDose Final 0.90"), imageFond(15*50,13*50,sf::Color::Green),
    m_cassable(LARGEUR, HAUTEUR), m_incassable(LARGEUR,HAUTEUR), m_bombe(LARGEUR,HAUTEUR), m_flamme(LARGEUR,HAUTEUR),
    m_bonusBombe(LARGEUR, HAUTEUR),m_bonusFlamme(LARGEUR, HAUTEUR), m_bonusRoller(LARGEUR, HAUTEUR)
{
    SetFramerateLimit(60);
    fond.SetImage(imageFond);

    m_listSprites=new sf::Sprite[15*13];


    /*
    * On charge les images des cases et bonus
    */
    m_flamme.LoadFromFile("flamme.png");
    m_bombe.LoadFromFile("bomb.png");
    m_incassable.LoadFromFile("incassable.png");
    m_cassable.LoadFromFile("cassable.png");
    m_bonusRoller.LoadFromFile("bonus roller.png");
    m_bonusBombe.LoadFromFile("bonus bombe.png");
    m_bonusFlamme.LoadFromFile("bonus flamme.png");
    m_malus.LoadFromFile("malus.png");

    /*
    *  On charge les images des joueurs
    */
    joueur1.LoadFromFile("char1.png");
    joueur2.LoadFromFile("char2.png");
    joueur3.LoadFromFile("char3.png");
    joueur4.LoadFromFile("char4.png");



    j1.SetImage(joueur1);
    j1.Resize(50,50);

    j2.SetImage(joueur2);
    j2.Resize(50,50);

    j3.SetImage(joueur3);
    j2.Resize(50,50);

    j4.SetImage(joueur4);
    j2.Resize(50,50);


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
            m_listSprites[i].SetImage(m_malus);
            m_listSprites[i].SetPosition(XPos(i), YPos(i));
            m_listSprites[i].Resize(50,50);
            Draw(m_listSprites[i]);
        }
        else if(fromServ->plateau[i]==CASE_AVECBONUS_FLAMME){
            m_listSprites[i].SetImage(m_bonusFlamme);
            m_listSprites[i].SetPosition(XPos(i), YPos(i));
            m_listSprites[i].Resize(50,50);
            Draw(m_listSprites[i]);
        }
        else if(fromServ->plateau[i]==CASE_AVECBONUS_BOMBE){
            m_listSprites[i].SetImage(m_bonusBombe);
            m_listSprites[i].SetPosition(XPos(i), YPos(i));
            m_listSprites[i].Resize(50,50);
            Draw(m_listSprites[i]);
        }
        else if(fromServ->plateau[i]==CASE_AVECBONUS_ROLLER){
            m_listSprites[i].SetImage(m_bonusRoller);
            m_listSprites[i].SetPosition(XPos(i), YPos(i));
            m_listSprites[i].Resize(50,50);
            Draw(m_listSprites[i]);
        }
        else if(fromServ->plateau[i]==CASE_AVECBOMBE){

       //     std::cout<<XPos(i)<<" - "<<YPos(i)<<std::endl;
            m_listSprites[i].SetImage(m_bombe);
            m_listSprites[i].SetPosition(XPos(i), YPos(i));
            m_listSprites[i].Resize(50,50);
            Draw(m_listSprites[i]);
        }
        if(fromServ->plateau[i]==CASE_ENFLAMMEE){
            m_listSprites[i].SetImage(m_flamme);
            m_listSprites[i].SetPosition(XPos(i), YPos(i));
            m_listSprites[i].Resize(50,50);
            Draw(m_listSprites[i]);
        }
    }


 }

void Screen::SetPosPlayer(ToClient* fromServ){
// Place les joueurs sur le terrain

    if(fromServ->j1){
        j1.SetPosition((fromServ->x1)-25,(fromServ->y1)-25);
        Draw(j1);
    }
    if(fromServ->j2){
        j2.SetPosition(fromServ->x2-25,fromServ->y2-25);
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
    return (i%15) * LARGEUR;
 }
int Screen::YPos(int i){
    return (i/15)* HAUTEUR;
 }

ToClient* Screen::GetStruct(){
// Retourne la structure
    return &m_fromServ;
}





