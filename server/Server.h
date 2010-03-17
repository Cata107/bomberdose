#ifndef Server_h
#define Server_h
#include <SFML/Network.hpp>
#include <vector>
#include "ThreadPrincipal.h"

class Server {
    /* gère l'inscription des clients au serveur, crée pour chaque client un thread principal */

public :

    /* Constructeur */
    Server (uint const _portTCP, uint const _portUDP);

    /* Destructeur */
    ~Server();

    /* Affiche les informations essentielles, les attributs du serveur */
    void MAfficherStatus();

    /* Attend les connexions des clients, tant que la partie n'est pas commencée */
    void MAttenteConnexion();

    /* Récupère le status de la partie */
    bool MGetStatusPartie();

    /* Ne fait rien tant que la partie n'est pas terminée */
    void MAttenteFinPartie();

    /* Ajoute un thread principal à la liste de threads principaux */
    bool MAjouterThreadPrincipal(ThreadPrincipal * _ThreadPrincipal);

    /* Nettoie la liste des threads principaux */
    bool MNettoyerListeThreads();

    /* Envoie une instruction à tous les clients enregistrés dans la liste des threads principaux */
    bool MEnvoiInstructionClients(int const _msg);

    /* Se charge de transmettre à tous les threads du programme qu'une partie va commencer */
    bool MGameStart();

    /* Se charge de transmettre à tous les threads du programme qu'une partie est terminée */
    bool MGameStop();




protected :

    /* Adresse locale telle qu'elle est vue sur le réseau local */
    sf::IPAddress m_localAdress;

    /* Port nécessité pour la connexion sur la socket TCP */
    uint m_portTCP;

    /* Port de connexion socket UDP */
    uint m_portUDP;

    /* Nombre de clients connectés à ce serveur */
    uint m_nbClients;

    /* Socket TCP du serveur */
    sf::SocketTCP m_socketTCP;

    /* Permet de savoir si la partie a été lancée ou non */
    bool m_PartieEnCours;

    /* Garde trace des threads principaux lancés, principalement afin de les nettoyer une fois le serveur éteint */
    std::vector<ThreadPrincipal*> m_ListeThreadPrincipaux;

};

#endif // Server_h
