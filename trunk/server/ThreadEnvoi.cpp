#include <iostream>
#include "ThreadEnvoi.h"
#include "MacroServer.h"

ThreadEnvoi::ThreadEnvoi( uint const _portUDP, uint const _numClient, sf::IPAddress const _clientAddress, volatile const bool *_pPartieEnCours)
{
    m_portUDP = _portUDP;
    m_NumeroClient = _numClient;
    m_clientAddress = _clientAddress;
    m_pPartieEnCours = _pPartieEnCours;
    m_SocketUdp = sf::SocketUDP::SocketUDP();
}
ThreadEnvoi::~ThreadEnvoi()
{
    m_SocketUdp.Close();
}
void ThreadEnvoi::Run()
{
    std::cout << "THREAD ENVOI du client : " << m_NumeroClient << " créé" << std::endl;
    while ( *m_pPartieEnCours )
    {
        std::cout<<"Boucle thread envoi "  << m_NumeroClient << std::endl;
        usleep( DODO );
        MEnvoiDonnees();
    }
}
bool ThreadEnvoi::MEnvoiDonnees()
{
    char Buffer[] = "TEST";
    std::cout << "données UDP Serveur > Client envoyées" << std::endl;
    if ( m_SocketUdp.Send(Buffer, sizeof(Buffer), m_clientAddress, m_portUDP ) != sf::Socket::Done)
    {
        std::cout<<"Erreur envoi de données par UDP"<<std::endl;
        return false;
    }

    return true;
}
