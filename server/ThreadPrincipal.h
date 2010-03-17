#ifndef ThreadPrincipal_h
#define ThreadPrincipal_h
#include <SFML/Network.hpp>
#include <iostream>
#include "ThreadEnvoi.h"
class ThreadPrincipal /*: public sf::Thread*/
/* SERVEUR : Envoie des instructions par TCP au client, et se charge de la création des sous threads de communication par protocole UDP */
{

public :
    /* Constructeur */
    ThreadPrincipal(uint const _numeroClient, sf::IPAddress const _adresseIpClient, sf::SocketTCP const _socketTCPClient, uint _portUDP, volatile const bool *_pPartieEnCours);

    /* Méthode run du thread */
    virtual void Run();

    /* Destructeur */
    ~ThreadPrincipal();

    /* Envoie une instruction au client par TCP */
    bool MEnvoiInstruction(int const _msg);

    /* Transmet au thread courant et aux sous threads que la partie va commencer */
    bool MGameStart();

    /* Crée les threads fils */
    bool MCreateFils();

    /* tue les fils */
    bool MDeleteFils();

    /* Transmet au thread courant et aux sous threads que la partie va s'arrêter */
    bool MGameStop();

    /* Supprime correctement le ThreadEnvoi correspondant à ce ThreadPrincipal. */
    bool MDeleteEnvoi();

    /* Supprime correctement le ThreadEcoute correspondant à ce ThreadPrincipal. */
    bool MDeleteEcoute();

    /* Crée le ThreadEnvoi correspondant à ce ThreadPrincipal */
    bool MCreateEnvoi();

    /* Crée le ThreadEcoute correspondant à ce ThreadPrincipal */
    bool MCreateEcoute();

    /* Attend la fin de la partie */
    bool MAttenteFinPartie();

    /* Attend la fin de la méthode run des fils */
    bool MAttenteFils();

private :
    /* l'ordre d'arrivée du client sur le serveur */
    uint m_NumeroClient;

    /* Adresse ip du client */
    sf::IPAddress m_AdresseIpClient;

    /* Socket TCP du client */
    sf::SocketTCP m_SocketTCPClient;

    /* Etat de la partie en cours, pointe sur la valeur du père, m_PartieEnCours */
    volatile bool const *m_pPartieEnCours;

    /* pointeur vers le thread fils d'envoi */
    ThreadEnvoi* m_pThreadEnvoi;

    /* Le port udp qui sera utilisé par les fils */
    uint m_portUDP;


};


#endif // ThreadPrincipal_h
