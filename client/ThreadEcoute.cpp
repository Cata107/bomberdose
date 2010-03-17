#include "ThreadEcoute.h"
#include <iostream>
#include "MacroClient.h"
ThreadEcoute::ThreadEcoute( uint _portUdp, volatile bool const * _partieEnCours )
{
    m_PortUDP = _portUdp;
    m_pPartieEnCours = _partieEnCours;
    m_SocketUdp = sf::SocketUDP::SocketUDP();
}

ThreadEcoute::~ThreadEcoute()
{
    m_SocketUdp.Close();
}

void ThreadEcoute::Run()
{
    std::cout << "Thread écoute du client créé." << std::endl;
    MBindSocket();
     while ( *m_pPartieEnCours )
    {
        usleep( DODO );
        MReceptionDonnees();
    }

}
bool ThreadEcoute::MBindSocket()
{
    if (!m_SocketUdp.Bind( m_PortUDP ))
    {
        std::cout<<"Erreur de bind de la socket udp" << std::endl;
        return false;
    }
    return true;
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
