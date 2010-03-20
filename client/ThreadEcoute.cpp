#include "ThreadEcoute.h"
#include <iostream>
#include "MacroClient.h"
sf::Packet& operator >>(sf::Packet& Packet, Plateau& P)
{
    return Packet >> P.tab[0] >> P.str;
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
    char Buffer[128];
    std::size_t Received;
    sf::IPAddress Sender;
    unsigned short Port;
    sf::Packet packetReceived;
    Plateau P;
    /*
    if ( m_SocketUdp.Receive(Buffer, sizeof(Buffer), Received, Sender, Port) != sf::Socket::Done)
    {
        std::cout<<"Erreur de réception des données UDP "<<std::endl;
    }
    else
    {
        std::cout<<Sender <<":"<<Port<<std::endl;
        std::cout<<Buffer<<std::endl;
    }*/
    if ( m_SocketUdp.Receive(packetReceived, Sender, Port) != sf::Socket::Done)
    {
        std::cout<<"Erreur de réception des données UDP "<<std::endl;
    }
    else
    {
        std::cout<<Sender <<":"<<Port<<std::endl;
        //std::cout<<Buffer<<std::endl;
        if (!(packetReceived >> P))
        {
            std::cout<<"MERDE"<<std::endl;
        }
        else
        {
            MPrintPlateau( P );
        }

    }
    return true;
}
void ThreadEcoute::MPrintPlateau(Plateau const P)
{
    std::cout<<P.str<<std::endl<<P.tab[0]<<std::endl;
}
