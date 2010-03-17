#include "ThreadPrincipal.h"
#include <iostream>
#include "MacroServer.h"
#include <stdio.h>

ThreadPrincipal::ThreadPrincipal(uint const _numeroClient, sf::IPAddress const _adresseIpClient, sf::SocketTCP const _socketTCPClient, uint _portUDP,  volatile const bool *_pPartieEnCours)
{
    m_NumeroClient = _numeroClient;
    m_AdresseIpClient = _adresseIpClient;
    m_SocketTCPClient = _socketTCPClient;
    m_portUDP = _portUDP;
    m_pPartieEnCours = _pPartieEnCours;
}

ThreadPrincipal::~ThreadPrincipal()
{
    MDeleteFils();
    m_SocketTCPClient.Close();
}

void ThreadPrincipal::Run()
{
    std::cout << "Thread principal du client n° : " << m_NumeroClient << " créé." << std::endl;
    MAttenteFinPartie();
}

bool ThreadPrincipal::MEnvoiInstruction (int const _msg)
{
    char Buffer[2];
    sprintf(Buffer,"%d",_msg);

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
    MCreateFils();
    MEnvoiInstruction( START );
    m_pThreadEnvoi->Launch();
    return true;
}
bool ThreadPrincipal::MGameStop()
{
    MEnvoiInstruction( STOP );
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
    m_pThreadEnvoi = new ThreadEnvoi( m_portUDP, m_NumeroClient, m_AdresseIpClient, m_pPartieEnCours );
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
    m_pThreadEnvoi->Wait();
    delete m_pThreadEnvoi;
    return true;
}
bool ThreadPrincipal::MAttenteFinPartie()
{
    while ( *m_pPartieEnCours )
    {
        usleep( DODO );
    }
    return true;
}
bool ThreadPrincipal::MAttenteFils()
{
    m_pThreadEnvoi->Wait();
    //m_PThreadEcoute->Wait();

    return true;
}
