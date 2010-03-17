#include "Sclient.h"
#include <iostream>
#include "MacroServer.h"
#include <stdio.h>

Sclient::Sclient( uint const _numeroClient, sf::IPAddress const _adresseIpClient, sf::SocketTCP const _socketTCPClient )
{
    m_NumeroClient = _numeroClient;
    m_AdresseIpClient = _adresseIpClient;
    m_SocketTCPClient = _socketTCPClient;
}

Sclient::~Sclient()
{
    m_SocketTCPClient.Close();
}
bool Sclient::MEnvoiInstruction (int const _msg)
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
bool Sclient::MGameStart()
{
    MEnvoiInstruction( START );
    return true;
}
bool Sclient::MGameStop()
{
    MEnvoiInstruction( STOP );
    return true;
}
