#include <iostream>
#include "ThreadEnvoi.h"
#include "MacroServer.h"
sf::Packet& operator <<(sf::Packet& Packet, const ToClient& T)
{
    return Packet << T.str <<T.plateau << T.j1 << T.x1 << T.y1 << T.j2 << T.x2 << T.y2 << T.j3 << T.x3 << T.y3 << T.j4 << T.x4 << T.y4;
}

ThreadEnvoi::ThreadEnvoi( volatile const bool *_pPartieEnCours, std::vector<Sclient*> const _ListeClients, BomberDose* _pointeurBomberdose)
{
    m_pPartieEnCours = _pPartieEnCours;
    m_SocketUdp = sf::SocketUDP::SocketUDP();
    m_ListeClients = _ListeClients;
    m_portUDPEnvoi = PORT_UDP_ENVOI;
    m_pBomberdose = _pointeurBomberdose;

}
ThreadEnvoi::~ThreadEnvoi()
{
    m_SocketUdp.Close();
}
void ThreadEnvoi::Run()
{
    std::cout << "THREAD ENVOI créé" << std::endl;
    int i = 0;
    while ( *m_pPartieEnCours )
    {
        usleep( DODO );
        MEnvoiDonnees();
        i++;
        std::cout<<"Bouclage envoi " <<i <<std::endl;
    }
}
bool ThreadEnvoi::MEnvoiDonnees()
{
    sf::Packet toSend;
    ToClient T;
    MInitialise(T);
    toSend << T;
    std::cout << "données UDP Serveur > Clients envoyées" << std::endl;
    for (unsigned int i = 0; i < m_ListeClients.size(); i++)
    {
        if ( m_SocketUdp.Send(toSend, m_ListeClients[i]->MGetIP(), m_portUDPEnvoi ) != sf::Socket::Done)
        {
            std::cout<<"Erreur envoi de données par UDP au client :"<< m_ListeClients[i]->MGetIP().ToString() <<std::endl;
            return false;
        }
    }
    return true;
}
bool ThreadEnvoi::MInitialise( ToClient& T )
{
    T.str = std::string("Serveur");
    T.plateau = m_pBomberdose->m_pPlateau->MGetPlateauConverti();
    int nbJoueurs = m_ListeClients.size();



    if (!m_pBomberdose->MGetJoueur(0)->MIsDead())
        //penser au pointeur null
    {
        T.j1= true ;
        T.x1= m_pBomberdose->MGetJoueur(0)->MGetPositionPixel().x ;
        T.y1= m_pBomberdose->MGetJoueur(0)->MGetPositionPixel().y ;
    }
    else
    {
        T.j1 = false ;
    }
    if ( nbJoueurs > 1 )
    {
        if (!m_pBomberdose->MGetJoueur(1)->MIsDead())
        {
            T.j2= true;
            T.x2= m_pBomberdose->MGetJoueur(1)->MGetPositionPixel().x ;
            T.y2= m_pBomberdose->MGetJoueur(1)->MGetPositionPixel().y ;
        }
        else
        {
            T.j2=false;
        }
        if(nbJoueurs > 2)
        {
            if (!m_pBomberdose->MGetJoueur(2)->MIsDead())
            {
                T.j3= true;
                T.x3= m_pBomberdose->MGetJoueur(2)->MGetPositionPixel().x ;
                T.y3= m_pBomberdose->MGetJoueur(2)->MGetPositionPixel().y ;
            }
            else
            {
                T.j3=false;
            }
            if (nbJoueurs >3 )
            {
                if (!m_pBomberdose->MGetJoueur(3)->MIsDead())
                {
                    T.j4=true;
                    T.x4=m_pBomberdose->MGetJoueur(3)->MGetPositionPixel().x ;
                    T.y4=m_pBomberdose->MGetJoueur(3)->MGetPositionPixel().y ;
                    }
                else
                {
                    T.j4=false;
                }
            }
        }
    }
    return true;
}

