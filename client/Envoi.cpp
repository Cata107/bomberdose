#include "Envoi.h"
#include "MacroClient.h"
#include <iostream>
sf::Packet& operator <<(sf::Packet& Packet, const ToServer& T)
{
    return Packet <<T.up << T.down << T.right<< T.left<< T.bomb<<T.elapsed_time;
}
Envoi::Envoi( sf::IPAddress const _IPAddressServer )
{
    m_portUDPEnvoi = PORT_UDP_ENVOI;
    m_IPAddressServer = _IPAddressServer;
    m_SocketUdp = sf::SocketUDP::SocketUDP();
    //std::cout<<"Je suis là"<<std::endl;
}
Envoi::~Envoi()
{

}
bool Envoi::MEnvoiInformations( bool const _up, bool const _down, bool const _right, bool const _left, bool const _bomb, unsigned int const _elapsed_time)
{
    ToServer T;
    MInitialiseToServer ( T, _up,_down,_right,_left,_bomb,_elapsed_time);
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
bool Envoi::MInitialiseToServer( ToServer& T, bool const _up, bool const _down, bool const _right, bool const _left, bool const _bomb, unsigned int const _elapsed_time)
{
    T.up = _up;
    T.down = _down;
    T.right = _right;
    T.left = _left;
    T.bomb = _bomb;
    T.elapsed_time = _elapsed_time;
    return true;
}
bool Envoi::MEnvoiPoseBombe()
{
    MEnvoiInformations( false, false, false, false, true, 0);
    return true;
}
bool Envoi::MEnvoiMoveUp(unsigned int const _elapsed_time)
{
    MEnvoiInformations( true, false, false, false, false, _elapsed_time);
    return true;
}
bool Envoi::MEnvoiMoveDown(unsigned int const _elapsed_time)
{
    MEnvoiInformations( false, true, false, false, false, _elapsed_time);
    return true;
}
bool Envoi::MEnvoiMoveRight(unsigned int const _elapsed_time)
{
    MEnvoiInformations( false, false, true, false, false, _elapsed_time);
    return true;
}
bool Envoi::MEnvoiMoveLeft(unsigned int const _elapsed_time)
{
    MEnvoiInformations( false, false, false, true, false, _elapsed_time);
    return true;
}

