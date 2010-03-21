#include <iostream>
#include "ThreadEnvoi.h"
#include "MacroServer.h"
sf::Packet& operator <<(sf::Packet& Packet, const ToClient& T)
{
    return Packet << T.str <<T.plateau << T.j1 << T.x1 << T.y1 << T.j2 << T.x2 << T.y2 << T.j3 << T.x3 << T.y3 << T.j4 << T.x4 << T.y4;
}

ThreadEnvoi::ThreadEnvoi( volatile const bool *_pPartieEnCours, std::vector<Sclient*> const _ListeClients)
{
    m_pPartieEnCours = _pPartieEnCours;
    m_SocketUdp = sf::SocketUDP::SocketUDP();
    m_ListeClients = _ListeClients;
    m_portUDPEnvoi = PORT_UDP_ENVOI;
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
    for (uint i = 0; i < m_ListeClients.size(); i++)
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
    int i;
    for (i = 0; i < 195; i++)
    {
        T.plateau[i]='h';
    }
    T.plateau[196]='\0';
    T.j1=true;
    T.x1=65000;
    T.y1=60000;
    T.j2=true;
    T.x2=65000;
    T.y2=60000;
    T.j3=true;
    T.x3=65000;
    T.y3=60000;
    T.j4=true;
    T.x4=60000;
    T.y4=44444;
    return true;
}

