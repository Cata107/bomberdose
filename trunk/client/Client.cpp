#include "Client.h"
Client::Client(int const _portTCP, char const * _addressIpServer)
{
    m_portTCP = _portTCP;
    m_localAddress = sf::IPAddress::GetLocalAddress();
    m_serverAddress = sf::IPAddress::IPAddress(_addressIpServer);
    m_PartieEnCours = false;
    m_SocketTCP = sf::SocketTCP::SocketTCP();
}
Client::~Client()
{
    m_SocketTCP.Close();
}
void Client::MAfficherStatus()
{
    std::cout<< "Client, Adresse locale et port : " << m_localAddress.ToString() <<":"<< m_portTCP << std::endl;
    std::cout<< "Adresse serveur : "<< m_serverAddress << std::endl;
}
Client::Client* Client::MGetInstance()
{
    return this;
}
bool Client::MGetStatusPartie()
{
    return m_PartieEnCours;
}
void Client::MAttenteFinPartie()
{
    while (m_PartieEnCours)
    {
    }
}
void Client::MConnect()
{
    if (m_SocketTCP.Connect(m_portTCP, m_serverAddress) != sf::Socket::Done)
    {
        std::cout<< "Erreur de connection au serveur" << std::endl;
    }
    else
    {
        std::cout << "Connection au serveur " << m_serverAddress.ToString() << " par le port " << m_portTCP << " effectuée"<< std::endl;
    }

}
void Client::MAttenteInstruction()
{
    while (true)
    {
    char Buffer [5];
    std::size_t Received;
    if (m_SocketTCP.Receive(Buffer, sizeof(Buffer), Received) != sf::Socket::Done)
    {
        std::cout<< "Impossible de lire les messages entrants" << std::endl;
    }
    else
    {
        std::cout<< "Instruction : " << Buffer << std::endl;
    }
    }

}
