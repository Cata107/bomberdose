#ifndef Sclient_h
#define Sclient_h
#include <SFML/Network.hpp>
#include <iostream>
#include "ThreadEnvoi.h"
/* Stocke les informations relatives au client et se charge de la transmission d'instructions tcp */
class Sclient
{

public :
    /* Constructeur */
    Sclient( unsigned int const _numeroClient, sf::IPAddress const _adresseIpClient, sf::SocketTCP const _socketTCPClient );

    /* Destructeur */
    ~Sclient();

    /* Envoie une instruction au client par TCP */
    bool MEnvoiInstruction(int const _msg);

    /* Transmet au client que la partie va commencer */
    bool MGameStart();

    /* Transmet au client que la partie va s'arrêter */
    bool MGameStop();

    /* Retourne l'adresse ip du client */
    sf::IPAddress MGetIP();

private :
    /* l'ordre d'arrivée du client sur le serveur */
    unsigned int m_NumeroClient;

    /* Adresse ip du client */
    sf::IPAddress m_AdresseIpClient;

    /* Socket TCP du client */
    sf::SocketTCP m_SocketTCPClient;
};


#endif // Sclient_h
