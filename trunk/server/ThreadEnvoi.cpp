#include "ThreadEnvoi.h"
#include <iostream>

ThreadEnvoi::ThreadEnvoi( uint const _portUDP, uint const _numClient, sf::IPAddress const _clientAddress, volatile const bool *_pPartieEnCours)
{
    m_portUDP = _portUDP;
    m_NumeroClient = _numClient;
    m_clientAddress = _clientAddress;
    m_pPartieEnCours = _pPartieEnCours;

}
ThreadEnvoi::~ThreadEnvoi()
{

}
void ThreadEnvoi::Run()
{
    std::cout << "THREAD ENVOI du client : " << m_NumeroClient << " créé" << std::endl;
    while ( *m_pPartieEnCours )
    {
        //pour dormir, le while true n'est pas bon, testé et approuvé, ça utilise 200% de mon cpu (jsais pas comment c'est possible, mais c'est possible)
        usleep(10000000);
    }
}
bool MEnvoiDonnees()
{
    std::cout << "haha" << std::endl;
    return true;
}
