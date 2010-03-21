#include "ThreadEcoute.h"
#include <iostream>
#include "MacroClient.h"
sf::Packet& operator >>(sf::Packet& Packet, ToClient& P)
{
    return Packet >> P.tab >> P.str;
}

ThreadEcoute::ThreadEcoute( volatile bool const * _partieEnCours )
{
    m_portUDPEcoute = PORT_UDP_ECOUTE;
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
    if (!m_SocketUdp.Bind( m_portUDPEcoute ))
    {
        std::cout<<"Erreur de bind de la socket udp" << std::endl;
        return false;
    }
    return true;
}
bool ThreadEcoute::MReceptionDonnees()
{
    sf::IPAddress Sender;
    unsigned short Port;
    sf::Packet packetReceived;
    ToClient P;
    if ( m_SocketUdp.Receive(packetReceived, Sender, Port) != sf::Socket::Done)
    {
        std::cout<<"Erreur de réception des données UDP "<<std::endl;
    }
    else
    {
        std::cout<<Sender <<":"<<Port<<std::endl;
        if (!(packetReceived >> P))
        {
            std::cout<<"MERDE"<<std::endl;
        }
        else
        {
            MPrintToClient( P );
        }

    }
    return true;
}
void ThreadEcoute::MPrintToClient(ToClient const P)
{
    std::cout<<P.str<<std::endl<<P.tab[0]<<std::endl;
}