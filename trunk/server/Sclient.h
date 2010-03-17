#ifndef ThreadPrincipal_h
#define ThreadPrincipal_h
#include <SFML/Network.hpp>
#include <iostream>
#include "ThreadEnvoi.h"
/* Stocke les informations relatives au client et se charge de la transmission d'instructions tcp */
class Sclient
{

public :
    /* Constructeur */
    Sclient( uint const _numeroClient, sf::IPAddress const _adresseIpClient, sf::SocketTCP const _socketTCPClient );

    /* Destructeur */
    ~Sclient();

    /* Envoie une instruction au client par TCP */
    bool MEnvoiInstruction(int const _msg);

    /* Transmet au client que la partie va commencer */
    bool MGameStart();

    /* Transmet au client que la partie va s'arrêter */
    bool MGameStop();

private :
    /* l'ordre d'arrivée du client sur le serveur */
    uint m_NumeroClient;

    /* Adresse ip du client */
    sf::IPAddress m_AdresseIpClient;

    /* Socket TCP du client */
    sf::SocketTCP m_SocketTCPClient;
};


#endif // ThreadPrincipal_h