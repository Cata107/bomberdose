#include "ThreadEcoute.h"
#include "MacroServer.h"
#include <iostream>
sf::Packet& operator >>(sf::Packet& Packet, ToServer& T)
{
    return Packet >> T.str >>T.up >> T.down >> T.right>>T.left>>T.bomb;
}
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
    int i = 0;
    while ( *m_pPartieEnCours )
    {
        MReceptionDonnees();
        i++;
        std::cout<<"Bouclage écoute " << i <<std::endl;
    }
}

bool ThreadEcoute::MReceptionDonnees()
{
    sf::Packet packetReceived;
    ToServer received;
    sf::IPAddress Sender;
    unsigned short Port;
    if ( m_SocketUdp.Receive(packetReceived, Sender, Port) != sf::Socket::Done)
    {
        std::cout<<"Erreur de réception des données UDP "<<std::endl;
    }
    else
    {
        std::cout<<Sender <<":"<<Port<<std::endl;
        if (!(packetReceived >> received))
        {
            std::cout<<"MERDE"<<std::endl;
        }
        else
        {
            MPrintToServer( received );
        }

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
void ThreadEcoute::MPrintToServer( ToServer const T )
{
std::cout<<T.str<<std::endl<<T.up<<T.down<<T.right<<T.left<<T.bomb<<std::endl;
}
