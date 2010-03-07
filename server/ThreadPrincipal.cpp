#include "ThreadPrincipal.h"
#include <iostream>

ThreadPrincipal::ThreadPrincipal(uint const _numeroClient, sf::IPAddress const _adresseIpClient, sf::SocketTCP const _socketTCPClient, uint _portUDP)
{
    m_NumeroClient = _numeroClient;
    m_AdresseIpClient = _adresseIpClient;
    m_SocketTCPClient = _socketTCPClient;
    m_PartieEnCours = false;
    m_portUDP = _portUDP;
}

ThreadPrincipal::~ThreadPrincipal()
{
    delete m_pThreadEnvoi;
}

void ThreadPrincipal::Run()
{
    std::cout << "Thread principal du client n° : " << m_NumeroClient << " créé." << std::endl;
    MGameStart();
    m_pThreadEnvoi->Launch();
    MGameStop();
    //m_pThreadEnvoi->Wait();
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
    std::string str = "START";
    m_PartieEnCours = true;
    MCreateFils();
    MEnvoiInstruction( str );
    //m_pThreadEnvoi->Launch();
    return true;
}
bool ThreadPrincipal::MGameStop()
{
    m_PartieEnCours = false;
    m_pThreadEnvoi->MGameStop();
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
    m_pThreadEnvoi = new ThreadEnvoi( m_portUDP, m_NumeroClient, m_AdresseIpClient );
    //m_pThreadEnvoi->Launch();
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
