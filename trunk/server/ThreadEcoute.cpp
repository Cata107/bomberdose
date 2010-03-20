#include "ThreadEcoute.h"
#include "MacroServer.h"
#include <iostream>
ThreadEcoute::ThreadEcoute( volatile const bool *_pPartieEnCours )
{
    m_pPartieEnCours = _pPartieEnCours;
    m_SocketUdp = sf::SocketUDP::SocketUDP();
    m_portUDPEcoute = PORT_UDP_ECOUTE;
}
ThreadEcoute::~ThreadEcoute()
{

}
void ThreadEcoute::Run()
{
    std::cout << "THREAD ECOUTE créé" << std::endl;
    MBindSocket();
    while ( *m_pPartieEnCours )
    {
        usleep( DODO );
        MReceptionDonnees();
    }
}

bool ThreadEcoute::MReceptionDonnees()
{
    char Buffer[128];
    std::size_t Received;
    sf::IPAddress Sender;
    unsigned short Port;
    if ( m_SocketUdp.Receive(Buffer, sizeof(Buffer), Received, Sender, Port) != sf::Socket::Done)
    {
        std::cout<<"Erreur de réception des données UDP "<<std::endl;
    }
    else
    {
        std::cout<<Sender <<":"<<Port<<std::endl;
        std::cout<<Buffer<<std::endl;
    }
    return true;
}
bool ThreadEcoute::MBindSocket()
{
    if (!m_SocketUdp.Bind( m_portUDPEcoute ))
    {
        std::cout<<"Erreur de bind de la socket udp" << std::endl;
        return false;
    }
    return true;
}
