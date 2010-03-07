#include <iostream>
#include "Server.h"
#include "ThreadPrincipal.h"
#include <sstream>

Server::Server(uint const _port)
{
    m_localAdress = sf::IPAddress::GetLocalAddress();
    m_portTCP = _port;
    //On utilise le même port UDP et TCP ... pour l'instant.
    m_portUDP = _port;
    m_nbClients = 0;
    m_socketTCP = sf::SocketTCP::SocketTCP();
    m_PartieEnCours = false;
}
Server::~Server()
{
    m_socketTCP.Close();
    MNettoyerListeThreads();
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
            ThreadPrincipal* tp = new ThreadPrincipal(m_nbClients, clientAddress, socketClient, m_portUDP);
            MAjouterThreadPrincipal( tp );
            tp->Launch();
            std::ostringstream oss;
            oss << m_nbClients;
            std::string str = oss.str();
            MEnvoiInstructionClients( str );
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
bool Server::MAjouterThreadPrincipal(ThreadPrincipal * _ThreadPrincipal)
{
    m_ListeThreadPrincipaux.push_back( _ThreadPrincipal );
    return true;
}

bool Server::MNettoyerListeThreads()
{
    for ( uint i = 0; i < m_ListeThreadPrincipaux.size(); i++)
    {
        ThreadPrincipal* tp = m_ListeThreadPrincipaux.back();
        m_ListeThreadPrincipaux.pop_back();
        delete tp;
    }

    return true;
}

bool Server::MEnvoiInstructionClients( std::string const _msg)
{
    for ( uint i = 0; i < m_ListeThreadPrincipaux.size(); i++)
    {
        m_ListeThreadPrincipaux[i]->MEnvoiInstruction(_msg);
    }
    return true;
}

bool Server::MGameStart()
{
    m_PartieEnCours = true;
    for ( uint i = 0; i < m_ListeThreadPrincipaux.size(); i++)
    {
        m_ListeThreadPrincipaux[i]->MGameStart();
    }
    return true;
}

bool Server::MGameStop()
{
    m_PartieEnCours = false;
    for ( uint i = 0; i < m_ListeThreadPrincipaux.size(); i++)
    {
        m_ListeThreadPrincipaux[i]->MGameStop();
    }

    return true;
}

