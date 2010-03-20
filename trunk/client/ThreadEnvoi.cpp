#include "ThreadEnvoi.h"
#include "MacroClient.h"
#include <iostream>
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
    while ( *m_pPartieEnCours )
    {
        usleep( DODO );
        MEnvoiDonnees();
    }
}
bool ThreadEnvoi::MEnvoiDonnees()
{
    char Buffer[] = "CLIENT";
    std::cout << "données UDP Client > Serveur envoyées" << std::endl;
    if ( m_SocketUdp.Send(Buffer, sizeof(Buffer), m_IPAddressServer, m_portUDPEnvoi ) != sf::Socket::Done)
    {
    std::cout<<"Erreur envoi de données par UDP au serveur"<<std::endl;
        return false;
    }
    return true;

}
