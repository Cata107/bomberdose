#include "ThreadPrincipal.h"
#include <iostream>


ThreadPrincipal::ThreadPrincipal(int _numeroClient, sf::IPAddress _adresseIpClient, sf::SocketTCP _socketTCPClient, Server* _pServer)/*:sf::Thread::Thread()*/
{
    m_NumeroClient = _numeroClient;
    m_AdresseIpClient = _adresseIpClient;
    m_SocketTCPClient = _socketTCPClient;
    m_pServer = _pServer;
}

ThreadPrincipal::~ThreadPrincipal()
//Destructeur
{
    delete m_pServer;
}

void ThreadPrincipal::Run()
{
    std::cout << "Thread principal du client n° : " << m_NumeroClient << " créé." << std::endl;
}
