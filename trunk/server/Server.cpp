#include "Server.h"
#include "ThreadPrincipal.h"

Server::Server(int _port)
{
    m_localAdress = sf::IPAddress::GetLocalAddress();
    m_portTCP = _port;
    m_nbClients = 0;
    m_socketTCP = sf::SocketTCP::SocketTCP();
    m_PartieEnCours = false;
}

void Server::MAfficherStatus()
{
    std::cout << "Serveur " << m_localAdress.ToString() << ":" << m_portTCP <<std::endl;
}
void Server::MAttenteConnexion()
{
    if (!m_socketTCP.Listen(m_portTCP))
    //Si la socket n'arrive pas à écouter sur le port, gestion des erreurs
    {
        std::cout << "Erreur d'écoute de la socket TCP sur le port " << m_portTCP << std::endl;
    }

    while (!m_PartieEnCours)
    //tant qu'il n'y a pas une partie en cours
    {
        sf::IPAddress clientAddress;
        sf::SocketTCP socketClient;
        if (m_socketTCP.Accept(socketClient, &clientAddress) != sf::Socket::Done)
        //en cas d'erreur d'une acceptation de socket
            {
                std::cout<< "Erreur d'acceptation de client sur la socket du serveur" << std::endl;
            }
        //si tout se passe bien
        else {
            std::cout<<"Connexion d'un nouveau client d'adresse : " << clientAddress.ToString() << std::endl;
            //création du thread principal
            ThreadPrincipal tp(m_nbClients, clientAddress, socketClient, Server::MGetAdresse());
            tp.Launch();
            m_nbClients++;
            }
    }
}
Server::Server* Server::MGetAdresse()
{
    return this;
}
