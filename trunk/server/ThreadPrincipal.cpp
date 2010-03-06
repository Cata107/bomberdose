#include "ThreadPrincipal.h"
#include <iostream>

ThreadPrincipal::ThreadPrincipal(int const _numeroClient, sf::IPAddress const _adresseIpClient, sf::SocketTCP const _socketTCPClient, Server const * _pServer):sf::Thread::Thread()
{
    m_NumeroClient = _numeroClient;
    m_AdresseIpClient = _adresseIpClient;
    m_SocketTCPClient = _socketTCPClient;
    m_pServer = _pServer;
}

ThreadPrincipal::~ThreadPrincipal()
{
    m_pServer=NULL;
}

void ThreadPrincipal::Run()
{
    std::cout << "Thread principal du client n° : " << m_NumeroClient << " créé." << std::endl;
    if (!ThreadPrincipal::MEnvoiInstruction("TEST"))
    {
        std::cout<<"ERREUR D'ENVOI D'INSTRUCTION AU CLIENT" << std::endl;
    }
}

bool ThreadPrincipal::MEnvoiInstruction (std::string const _msg)
{
    char const*  Buffer = _msg.data();
    if (m_SocketTCPClient.Send(Buffer, sizeof(Buffer)) != sf::Socket::Done)
    {
        std::cout<<"ERREUR d'envoi d'instructions au client" << std::endl;
        return false;
    }
    std::cout<<"Instruction " << Buffer << " correctement envoyée au client" << std::endl;
    return true;
}
