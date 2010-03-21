#include "ThreadEnvoi.h"
#include "MacroClient.h"
#include <iostream>
sf::Packet& operator <<(sf::Packet& Packet, const ToServer& T)
{
    return Packet << T.str <<T.up << T.down << T.right<< T.left<< T.bomb;
}
ThreadEnvoi::ThreadEnvoi( volatile const bool *_pPartieEnCours, sf::IPAddress const _IPAddressServer )
{
    m_portUDPEnvoi = PORT_UDP_ENVOI;
    m_pPartieEnCours = _pPartieEnCours;
    m_IPAddressServer = _IPAddressServer;
    m_SocketUdp = sf::SocketUDP::SocketUDP();
}
ThreadEnvoi::~ThreadEnvoi()
{

}
void ThreadEnvoi::Run()
{
    std::cout << "Thread envoi du client créé." << std::endl;
    int i =0;
    while ( *m_pPartieEnCours )
    {
        usleep( DODO );
        MEnvoiDonnees();
        i++;
        std::cout<<"Bouclage envoi : " <<i<<std::endl;
    }
}
bool ThreadEnvoi::MEnvoiDonnees()
{
    ToServer T;
    sf::Packet ToSend;
    MInitialise( T );
    ToSend<<T;
    std::cout << "données UDP Client > Serveur envoyées" << std::endl;
    if ( m_SocketUdp.Send(ToSend, m_IPAddressServer, m_portUDPEnvoi ) != sf::Socket::Done)
    {
    std::cout<<"Erreur envoi de données par UDP au serveur"<<std::endl;
        return false;
    }
    return true;
}
bool ThreadEnvoi::MInitialise( ToServer& T )
{
    T.str = std::string("Client");
    T.up = true;
    T.down = false;
    T.right = true;
    T.left = true;
    T.bomb = false;
    return true;
}
