#include "ThreadEcoute.h"
#include <iostream>
#include "MacroClient.h"
sf::Packet& operator >>(sf::Packet& Packet, ToClient& T)
{
    return Packet >> T.plateau >> T.j1 >> T.x1 >> T.y1 >> T.t1 >>T.j2 >> T.x2 >> T.y2 >> T.t2>> T.j3 >> T.x3 >> T.y3 >>T.t3>> T.j4 >> T.x4 >> T.y4>>T.t4;
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
    int i = 0;
     while ( *m_pPartieEnCours )
    {
        MReceptionDonnees();
        i++;
        std::cout<<"Bouclage ecoute " <<i<<std::endl;
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
    ToClient received;
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
            MPrintToClient( received );
        }

    }
    return true;
}
void ThreadEcoute::MPrintToClient(ToClient const T)
{
    std::cout<<T.plateau;
    std::cout<<std::endl<< T.j1 << T.x1 << T.y1 <<std::endl<< T.j2 << T.x2 << T.y2 <<std::endl<< T.j3 << T.x3 << T.y3 <<std::endl<< T.j4 << T.x4 << T.y4<<std::endl;
}