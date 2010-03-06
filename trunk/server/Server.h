#ifndef Server_h
#define Server_h
#include <SFML/Network.hpp>
#include <list>

class ThreadPrincipal;

class Server {
    /* gère l'inscription des clients au serveur, crée pour chaque client un thread principal */

public :

    /* Constructeur */
    Server (int const _port);

    /* Destructeur */
    ~Server();

    /* Affiche les informations essentielles, les attributs du serveur */
    void MAfficherStatus();

    /* Attend les connexions des clients, tant que la partie n'est pas commencée */
    void MAttenteConnexion();

    /* Récupère un pointeur du serveur courant */
    Server* MGetInstance();

    /* Récupère le status de la partie */
    bool MGetStatusPartie();

    /* Ne fait rien tant que la partie n'est pas terminée */
    void MAttenteFinPartie();

    /* Initialise la liste des thread principaux, n'est utilisée que par le constructeur */
    void MInitialiserListeThreadPrincipaux(std::list<ThreadPrincipal*> _listeThreadPrincipaux);

protected :

    /* Adresse locale telle qu'elle est vue sur le réseau local */
    sf::IPAddress m_localAdress;

    /* Port nécessité pour la connexion sur la socket TCP */
    int m_portTCP;

    /* Nombre de clients connectés à ce serveur */
    int m_nbClients;

    /* Socket TCP du serveur */
    sf::SocketTCP m_socketTCP;

    /* Permet de savoir si la partie a été lancée ou non */
    bool m_PartieEnCours;

    /* Garde trace des threads principaux lancés, principalement afin de les nettoyer une fois le serveur éteint */
    std::list<ThreadPrincipal*> m_ListeThreadPrincipaux;

};

#endif // Server_h
