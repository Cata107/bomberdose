#include <iostream>
#include "Server.h"
#include "Sclient.h"
#include <sstream>
#include "MacroServer.h"
#include <BomberDose.h>

Server::Server( int const _nbClientsAttendus )
{
    m_localAdress = sf::IPAddress::GetLocalAddress();
    m_nbClients = 0;
    m_nbClientsAttendus = _nbClientsAttendus;
    m_socketTCP = sf::SocketTCP::SocketTCP();
    m_PartieEnCours = false;
    m_portTCP = PORT_TCP;
}
Server::~Server()
{
    m_socketTCP.Close();
    MNettoyerListeClients();
    delete m_pBomberdose;
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

    while ( m_nbClients < m_nbClientsAttendus )
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
            Sclient * client = new Sclient( m_nbClients, clientAddress, socketClient );
            MAjouterClient( client );
            m_nbClients++;
            }
    }
}
bool Server::MGetStatusPartie()
{
    return m_PartieEnCours;
}
void Server::MAttenteFinPartie()
{
    while (m_PartieEnCours)
    {
        usleep( DODO );
    }
}
bool Server::MAjouterClient( Sclient * _client )
{
    m_ListeClients.push_back( _client );
    return true;
}

bool Server::MNettoyerListeClients()
{
    for ( uint i = 0; i < m_ListeClients.size(); i++)
    {
        Sclient * client = m_ListeClients.back();
        m_ListeClients.pop_back();
        delete client;
    }

    return true;
}

bool Server::MEnvoiInstructionClients( int const _msg)
{
    for ( uint i = 0; i < m_ListeClients.size(); i++)
    {
        m_ListeClients[i]->MEnvoiInstruction(_msg);
    }
    return true;
}

bool Server::MGameStart()
{
    m_PartieEnCours = true;
    for ( uint i = 0; i < m_ListeClients.size(); i++)
    {
        m_ListeClients[i]->MGameStart();
    }
    MCreateFils();
    m_pThreadEnvoi->Launch();
    m_pThreadEcoute->Launch();
    return true;
}

bool Server::MGameStop()
{
    m_PartieEnCours = false;
    for ( uint i = 0; i < m_ListeClients.size(); i++)
    {
        m_ListeClients[i]->MGameStop();
    }

    return true;
}

bool Server::MCreateFils()
{
    MCreateEnvoi();
    MCreateEcoute();
    return true;
}
bool Server::MDeleteFils()
{
    MDeleteEnvoi();
    MDeleteEcoute();
    return true;
}
bool Server::MCreateEnvoi()
{
    m_pThreadEnvoi = new ThreadEnvoi( &m_PartieEnCours, m_ListeClients, m_pBomberdose );
    return true;
}
bool Server::MCreateEcoute()
{
    m_pThreadEcoute = new ThreadEcoute ( &m_PartieEnCours, MGetTableauIP(), m_pBomberdose);
    return true;
}
bool Server::MDeleteEcoute()
{
    m_pThreadEcoute->Wait();
    delete m_pThreadEnvoi;
    return true;
}
bool Server::MDeleteEnvoi()
{
    m_pThreadEnvoi->Wait();
    delete m_pThreadEnvoi;
    return true;
}
bool Server::MCreateBomberdose()
{
    int nbJoueurs = m_nbClientsAttendus;
    int nbBonusBombe=0,nbBonusFlamme=0,nbBonusRoller=0,nbMalus=0, score=0;
    do
    {
        std::cout<<"Entrez le nombre de bonus et malus que vous souhaitez avoir en jeu (le total ne doit pas dépasser 80) :";
        std::cout<<std::endl<<"Entrez le nombre de bonus de bombe :";
        std::cin>>nbBonusBombe;
        std::cout<<std::endl<<"Entrez le nombre de bonus de flamme : ";
        std::cin>>nbBonusFlamme;
        std::cout<<std::endl<<"Entrez le nombre de bonus roller : ";
        std::cin>>nbBonusRoller;
        std::cout<<std::endl<<"Entrez le nombre de malus : ";
        std::cin>>nbMalus;
        std::cout<<std::endl;
    } while (nbBonusBombe+nbBonusFlamme+nbBonusRoller+nbMalus>80);
        std::cout<<"Entrez le score à atteindre par le joueur pour gagner :";
        std::cin>>score;
        std::cout<<std::endl;
    m_pBomberdose = new BomberDose(nbJoueurs,nbBonusBombe, nbBonusFlamme, nbBonusRoller, nbMalus, score);
    return true;
}
int* Server::MGetTableauIP()
{
    int * tab = new int [ m_nbClientsAttendus ];
    for ( int i = 0; i < m_ListeClients.size(); i++ )
    {
        tab[i] = m_ListeClients[i]->MGetIP().ToInteger();
    }
    return tab;
}
