#ifndef ThreadPrincipal_h
#define ThreadPrincipal_h
#include <SFML/Network.hpp>
#include <iostream>
#include "ThreadEnvoi.h"
class ThreadPrincipal : public sf::Thread
/* Thread qui s'occupe d'envoyer des instructions par TCP au client, et se charge de la création des sous threads de communication */
{

public :
    /* Constructeur */
    ThreadPrincipal(uint const _numeroClient, sf::IPAddress const _adresseIpClient, sf::SocketTCP const _socketTCPClient, uint _portUDP);

    /* Méthode run du thread */
    virtual void Run();

    /* Destructeur */
    ~ThreadPrincipal();

    /* Envoie une instruction au client par TCP */
    bool MEnvoiInstruction(std::string const _msg);

    /* Transmet au thread courant et aux sous threads que la partie va commencer */
    bool MGameStart();

    /* Crée les threads fils */
    bool MCreateFils();

    /* tue les fils */
    bool MDeleteFils();

    /* Transmet au thread courant et aux sous threads que la partie va s'arrêter */
    bool MGameStop();

    bool MDeleteEnvoi();

    bool MDeleteEcoute();

    bool MCreateEnvoi();

    bool MCreateEcoute();


private :
    /* l'ordre d'arrivée du client sur le serveur */
    uint m_NumeroClient;

    /* Adresse ip du client */
    sf::IPAddress m_AdresseIpClient;

    /* Socket TCP du client */
    sf::SocketTCP m_SocketTCPClient;

    /* Pointeur vers le père, le serveur */
    //Server const * m_pServer;

    /* Etat de la partie en cours, true si elle est en cours, false sinon, copie de l'état du jeu dans le serveur */
    /* Peut être modifiée par le thread pere, Server.h */
    volatile bool m_PartieEnCours;

    /* pointeur vers le thread fils d'envoi */
    ThreadEnvoi* m_pThreadEnvoi;

    /* Le port udp qui sera utilisé par les fils */
    uint m_portUDP;


};


#endif // ThreadPrincipal_h
