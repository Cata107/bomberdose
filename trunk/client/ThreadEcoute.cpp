#include "ThreadEcoute.h"
#include <iostream>
#include "MacroClient.h"
sf::Packet& operator >>(sf::Packet& Packet, ToClient& T)
{
    return Packet >> T.plateau >> T.j1 >> T.x1 >> T.y1>>T.j2 >> T.x2 >> T.y2 >> T.j3 >> T.x3 >> T.y3 >> T.j4 >> T.x4 >> T.y4;
}

ThreadEcoute::ThreadEcoute( volatile bool const * _partieEnCours, ToClient* _pStructToClient )
{
    m_portUDPEcoute = PORT_UDP_ECOUTE;
    m_pPartieEnCours = _partieEnCours;
    m_SocketUdp = sf::SocketUDP::SocketUDP();
    m_pVue = _pStructToClient;
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
            std::cout<<"Le packet reçu ne correspond pas à un ToClient"<<std::endl;
        }
        else
        {
            MPrintToClient( received );
			MCommitToClient(&received);
        }

    }
    return true;
}
void ThreadEcoute::MPrintToClient(ToClient const T)
{
    std::cout<<T.plateau;
    std::cout<<std::endl<< T.j1 << T.x1 << T.y1 <<std::endl<< T.j2 << T.x2 << T.y2 <<std::endl<< T.j3 << T.x3 << T.y3 <<std::endl<< T.j4 << T.x4 << T.y4<<std::endl;
}
bool ThreadEcoute::MCommitToClient(ToClient* T)
{
   // std::cout<<"COMMIT"<<std::endl;
   // std::cout<<"PLATEAU THREAD :"<< T->plateau<<std::endl;
    *m_pVue= *T;
  //  std::cout<<"PLATEAU THREAD 2 :" << m_pVue<<std::endl;
    return true;
}
