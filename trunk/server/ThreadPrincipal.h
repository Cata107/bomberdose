#ifndef ThreadPrincipal_h
#define ThreadPrincipal_h
#include <SFML/Network.hpp>
#include "Server.h"

class ThreadPrincipal : public sf::Thread
/* Thread qui s'occupe d'envoyer/recevoir des messages par TCP au client, et se charge de la création des sous threads pour prendre en charge l'envoi/reception des datagrammes UDP */
{

public :
    ThreadPrincipal(int _numeroClient, sf::IPAddress _adresseIpClient, sf::SocketTCP _socketTCPClient, Server::Server* _pServer);
    virtual void Run();
    ~ThreadPrincipal();

private :
    int m_NumeroClient;
    sf::IPAddress m_AdresseIpClient;
    sf::SocketTCP m_SocketTCPClient;
    Server* m_pServer;





};


#endif // ThreadPrincipal_h
