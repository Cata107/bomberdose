#ifndef ThreadPrincipal_h
#define ThreadPrincipal_h
#include <SFML/Network.hpp>
#include "Server.h"
#include <iostream>
class ThreadPrincipal : public sf::Thread
/* Thread qui s'occupe d'envoyer des instructions par TCP au client, et se charge de la création des sous threads de communication */
{

public :
    /* Constructeur */
    ThreadPrincipal(int const _numeroClient, sf::IPAddress const _adresseIpClient, sf::SocketTCP const _socketTCPClient, Server::Server const * _pServer);

    /* Méthode run du thread */
    virtual void Run();

    /* Destructeur */
    ~ThreadPrincipal();

    /* Méthode qui envoie une instruction au client par TCP */
    bool MEnvoiInstruction(std::string const _msg);

private :
    /* l'ordre d'arrivée du client sur le serveur */
    int m_NumeroClient;

    /* Adresse ip du client */
    sf::IPAddress m_AdresseIpClient;

    /* Socket TCP du client */
    sf::SocketTCP m_SocketTCPClient;

    /* Pointeur vers le père, le serveur */
    Server const * m_pServer;

};


#endif // ThreadPrincipal_h
