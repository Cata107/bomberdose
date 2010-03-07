#include "ThreadPrincipal.h"
#include <iostream>

ThreadPrincipal::ThreadPrincipal(uint const _numeroClient, sf::IPAddress const _adresseIpClient, sf::SocketTCP const _socketTCPClient, uint _portUDP):sf::Thread::Thread()
{
    m_NumeroClient = _numeroClient;
    m_AdresseIpClient = _adresseIpClient;
    m_SocketTCPClient = _socketTCPClient;
    m_PartieEnCours = false;
    m_portUDP = _portUDP;
}

ThreadPrincipal::~ThreadPrincipal()
{
}

void ThreadPrincipal::Run()
{
    std::cout << "Thread principal du client n° : " << m_NumeroClient << " créé." << std::endl;
}

bool ThreadPrincipal::MEnvoiInstruction (std::string const _msg)
{
    char const*  Buffer = _msg.data();
    if (m_SocketTCPClient.Send(Buffer, sizeof(Buffer)) != sf::Socket::Done)
    {
        std::cout<<"ERREUR d'envoi d'instructions au client" << std::endl;
        return false;
    }
    std::cout<<"Instruction " << Buffer << " correctement envoyée au client n°" << m_NumeroClient << " d'ip : " << m_AdresseIpClient.ToString() << std::endl;
    return true;
}
bool ThreadPrincipal::MGameStart()
{
    m_PartieEnCours = true;
    MCreateFils();
    return true;
}
bool ThreadPrincipal::MGameStop()
{
    m_PartieEnCours = false;
    MDeleteFils();
    return true;
}
bool ThreadPrincipal::MCreateFils()
{
    MCreateEnvoi();
    MCreateEcoute();
    return true;
}
bool ThreadPrincipal::MDeleteFils()
{
    MDeleteEnvoi();
    MDeleteEcoute();
    return true;
}
bool ThreadPrincipal::MCreateEnvoi()
{
    return true;
}
bool ThreadPrincipal::MCreateEcoute()
{
    return true;
}
bool ThreadPrincipal::MDeleteEcoute()
{
    return true;
}
bool ThreadPrincipal::MDeleteEnvoi()
{
    delete m_pThreadEnvoi;
    return true;
}
