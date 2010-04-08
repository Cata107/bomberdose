#include "Events.h"



    Events::Events(const sf::Input *i, char* ip, Animated *a, Anim *first, Anim *second): envoi(ip) {
        m_input=i;
        m_animated=a;
        m_first=first;
        m_second=second;

    }
    Events::~Events(){
        delete m_input;
    }

    void Events::Try(float Ftime){

        if(m_input->IsKeyDown(sf::Key::Down)){
            std::cout<<"DOWN"<<std::endl;
            envoi.MEnvoiMoveDown();

        }
        if(m_input->IsKeyDown(sf::Key::Up)){
             envoi.MEnvoiMoveUp();
        }
        if(m_input->IsKeyDown(sf::Key::Left)){
             envoi.MEnvoiMoveLeft();
        }
        if(m_input->IsKeyDown(sf::Key::Right)){
             envoi.MEnvoiMoveRight();
        }
        if(m_input->IsKeyDown(sf::Key::Space)){
            envoi.MEnvoiPoseBombe();
        }
    }

    void Events::Try2(){

    }

