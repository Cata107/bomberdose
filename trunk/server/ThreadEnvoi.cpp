#include "ThreadEnvoi.h"
#include <iostream>

ThreadEnvoi::ThreadEnvoi( uint const _portUDP, uint const _numClient, sf::IPAddress const _clientAddress)
{
    m_portUDP = _portUDP;
    m_NumeroClient = _numClient;
    m_clientAddress = _clientAddress;
    /* Par défaut, lorsqu'on construit un thread de communication, c'est parce qu'une partie a commencé */
    m_PartieEnCours = true;
}
ThreadEnvoi::~ThreadEnvoi()
{

}
void ThreadEnvoi::Run()
{
    std::cout << "THREAD ENVOI" << m_NumeroClient << std::endl;
    while ( m_PartieEnCours )
    {
        std::cout << "haha" << std::endl;
    }
}
bool ThreadEnvoi::MGameStop()
{
    m_PartieEnCours = false;
    return true;
}
bool MEnvoiDonnees()
{
    std::cout << "haha" << std::endl;
    return true;
}
