#include "Envoi.h"
#include "MacroClient.h"
#include <iostream>
sf::Packet& operator <<(sf::Packet& Packet, const ToServer& T)
{
    return Packet << T.str <<T.up << T.down << T.right<< T.left<< T.bomb;
}
Envoi::Envoi( sf::IPAddress const _IPAddressServer )
{
    m_portUDPEnvoi = PORT_UDP_ENVOI;
    m_IPAddressServer = _IPAddressServer;
    m_SocketUdp = sf::SocketUDP::SocketUDP();
}
Envoi::~Envoi()
{

}
bool Envoi::MEnvoiInformations( bool const _up, bool const _down, bool const _right, bool const _left, bool const _bomb )
{
    ToServer T;
    MInitialiseToServer ( T, _up,_down,_right,_left,_bomb);
    MEnvoiPacket( T );
    return true;
}
bool Envoi::MEnvoiPacket(ToServer const T)
{
    sf::Packet ToSend;
    ToSend<<T;
    std::cout << "données UDP Client > Serveur envoyées" << std::endl;
    if ( m_SocketUdp.Send(ToSend, m_IPAddressServer, m_portUDPEnvoi ) != sf::Socket::Done)
    {
    std::cout<<"Erreur envoi de données par UDP au serveur"<<std::endl;
        return false;
    }
    return true;
}
bool Envoi::MInitialiseToServer( ToServer& T, bool const _up, bool const _down, bool const _right, bool const _left, bool const _bomb)
{
    T.str = std::string("Client");
    T.up = _up;
    T.down = _down;
    T.right = _right;
    T.left = _left;
    T.bomb = _bomb;
    return true;
}
bool Envoi::MEnvoiPoseBombe()
{
    MEnvoiInformations( false, false, false, false, true);
    return true;
}
bool Envoi::MEnvoiMoveUp()
{
    MEnvoiInformations( true, false, false, false, false);
    return true;
}
bool Envoi::MEnvoiMoveDown()
{
    MEnvoiInformations( false, true, false, false, false);
    return true;
}
bool Envoi::MEnvoiMoveRight()
{
    MEnvoiInformations( false, false, true, false, false);
    return true;
}
bool Envoi::MEnvoiMoveLeft()
{
    MEnvoiInformations( false, false, false, true, false);
    return true;
}

