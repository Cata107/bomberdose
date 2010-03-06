#include <iostream>
#include "Server.h"
#include "ThreadPrincipal.h"

Server::Server(int const _port)
{
    m_localAdress = sf::IPAddress::GetLocalAddress();
    m_portTCP = _port;
    m_nbClients = 0;
    m_socketTCP = sf::SocketTCP::SocketTCP();
    m_PartieEnCours = false;
    Server::MInitialiserListeThreadPrincipaux ( m_ListeThreadPrincipaux );
}
Server::~Server()
{
    m_socketTCP.Close();
}
void Server::MAfficherStatus()
{
    std::cout << "Serveur " << m_localAdress.ToString() << ":" << m_portTCP <<std::endl;
}
void Server::MAttenteConnexion()
{
    if (!m_socketTCP.Listen(m_portTCP))
    {
        std::cout << "Erreur d'écoute de la socket TCP sur le port " << m_portTCP << std::endl;
    }

    while (!m_PartieEnCours)
    //tant qu'il n'y a pas une partie en cours
    {
        sf::IPAddress clientAddress;
        sf::SocketTCP socketClient;
        if (m_socketTCP.Accept(socketClient, &clientAddress) != sf::Socket::Done)
            {
                std::cout<< "Erreur d'acceptation de client sur la socket du serveur" << std::endl;
            }
        else {
            std::cout<<"Connexion d'un nouveau client d'adresse : " << clientAddress.ToString() << std::endl;
            //création du thread principal
            ThreadPrincipal* tp = new ThreadPrincipal(m_nbClients, clientAddress, socketClient, Server::MGetInstance());
            tp->Launch();
            m_nbClients++;
            }
    }
}
Server::Server* Server::MGetInstance()
{
    return this;
}
bool Server::MGetStatusPartie()
{
    return m_PartieEnCours;
}
void Server::MAttenteFinPartie()
{
    while (m_PartieEnCours)
    {
    }
}
void Server::MInitialiserListeThreadPrincipaux(std::list<ThreadPrincipal*> _listeThreadPrincipaux)
{
    for (int i = 0; i < 4; i++)
    {
        ThreadPrincipal *tp;
        //_listeThreadPrincipaux.assign(*tp); << ça marche pas et j'ai pas envie de savoir pourquoi
    }
}
