#include "ThreadEcoute.h"
#include "MacroServer.h"
#include <iostream>
#include "Server.h"
sf::Packet& operator >>(sf::Packet& Packet, ToServer& T)
{
    return Packet >> T.str >>T.up >> T.down >> T.right>>T.left>>T.bomb;
}
ThreadEcoute::ThreadEcoute( volatile const bool *_pPartieEnCours, int* _tabCorrespondanceIP, BomberDose* _pointeurBomberdose )
{
    m_pPartieEnCours = _pPartieEnCours;
    m_SocketUdp = sf::SocketUDP::SocketUDP();
    m_portUDPEcoute = PORT_UDP_ECOUTE;
    m_tableauIP = _tabCorrespondanceIP;
    m_pBomberdose = _pointeurBomberdose;
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
            MCommitToServer( received, MGetNumJoueur ( Sender.ToInteger() ) );
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
int ThreadEcoute::MGetNumJoueur ( int const _addresseIP )
{
    int i=0;
    while ( m_tableauIP[i] != _addresseIP )
    {
        i++;
        std::cout<<"Boucle pas infinie..."<<std::endl;
    }
    return i;
}
bool ThreadEcoute::MCommitToServer ( ToServer const T, int const _numJoueur )
{
    if ( T.up )
    {

        std::cout<<"Joueur "<< _numJoueur << "MOVE UP "<<std::endl;
        //m_pBomberdose->MGetJoueur( _numJoueur )->MMoveUp();
    }
    else if ( T.down )
    {
        std::cout<<"Joueur "<< _numJoueur << "MOVE DOWN "<<std::endl;
        //m_pBomberdose->MGetJoueur( _numJoueur )->MMoveDown();
    }
    else if ( T.right )
    {
        std::cout<<"Joueur "<< _numJoueur << "MOVE RIGHT "<<std::endl;
        //m_pBomberdose->MGetJoueur( _numJoueur )->MMoveRight();
    }
    else if ( T.left )
    {
        std::cout<<"Joueur "<< _numJoueur << "MOVE LEFT "<<std::endl;
        //m_pBomberdose->MGetJoueur( _numJoueur )->MMoveLeft();
    }
    else if ( T.bomb )
    {
        std::cout<<"Joueur "<< _numJoueur << " POSE BOMBE "<<std::endl;
        //m_pBomberdose->MGetJoueur( _numJoueur )->MPoserBombe();
    }
    return true;
}
