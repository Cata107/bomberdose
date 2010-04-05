#include "Events.h"



    Events::Events(const sf::Input *i, Animated *a, Anim *first, Anim *second): envoi("127.0.0.1") {
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
    //        std::cout<<"DOWN"<<std::endl;
            if(m_animated->GetAnim()!=m_first){
                m_animated->SetAnim(m_first);
            }
            envoi.MEnvoiMoveDown(0);
            m_animated->Move(0, 100*Ftime);

        }
        if(m_input->IsKeyDown(sf::Key::Up)){
 //           std::cout<<"UP"<<std::endl;
            if(m_animated->GetAnim()!=m_second){
                m_animated->SetAnim(m_second);
            }
             envoi.MEnvoiMoveUp(0);
            m_animated->Move(0, -100*Ftime);
        }
        if(m_input->IsKeyDown(sf::Key::Left)){
   //         std::cout<<"LEFT"<<std::endl;
             envoi.MEnvoiMoveLeft(0);
            m_animated->Move(-100*Ftime, 0);
        }
        if(m_input->IsKeyDown(sf::Key::Right)){
   //         std::cout<<"RIGHT"<<std::endl;
             envoi.MEnvoiMoveRight(0);
            m_animated->Move(100*Ftime, 0);
        }
    }

    void Events::Try2(){

    }

