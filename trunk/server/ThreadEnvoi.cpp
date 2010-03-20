#include <iostream>
#include "ThreadEnvoi.h"
#include "MacroServer.h"
sf::Packet& operator <<(sf::Packet& Packet, const Plateau& P)
{
    return Packet << P.tab[0] << P.str;
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
    while ( *m_pPartieEnCours )
    {
        std::cout<<"Boucle thread envoi "<< std::endl;
        usleep( DODO );
        MEnvoiDonnees();
    }
}
bool ThreadEnvoi::MEnvoiDonnees()
{
    char Buffer[] = "SERVEUR";
    sf::Packet toSend;
    Plateau P;
    MInitialise(P);
    toSend << P;
    std::cout << "données UDP Serveur > Clients envoyées" << std::endl;
    for (uint i = 0; i < m_ListeClients.size(); i++)
    {
        /*if ( m_SocketUdp.Send(Buffer, sizeof(Buffer), m_ListeClients[i]->MGetIP(), m_portUDPEnvoi ) != sf::Socket::Done)
        {
            std::cout<<"Erreur envoi de données par UDP au client :"<< m_ListeClients[i]->MGetIP().ToString() <<std::endl;
            return false;
        }*/
        if ( m_SocketUdp.Send(toSend, m_ListeClients[i]->MGetIP(), m_portUDPEnvoi ) != sf::Socket::Done)
        {
            std::cout<<"Erreur envoi de données par UDP au client :"<< m_ListeClients[i]->MGetIP().ToString() <<std::endl;
            return false;
        }
    }
    return true;
}
bool ThreadEnvoi::MInitialise( Plateau& P )
{
    P.str = "Serveur";
    P.tab[0]=1;
    return true;
}

