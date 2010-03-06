#ifndef Client_h
#define Client_h
#include <SFML/Network.hpp>
#include <iostream>

class Client {
    /* Client qui se connecte au serveur par TCP pour lui donner les informations importantes, notamment l'adresse ip ; se charge de créer les sous threads de communication avec le serveur */
    public :

        /* Constructeur */
        Client(int const _portTCP, char const* _addressIpServer);

        /* Destructeur */
        ~Client();

        /* Affiche les attributs du client */
        void MAfficherStatus();

        /* Renvoie un pointeur vers lui même */
        Client* MGetInstance();

        /* Retourne true si la partie est en cours, false sinon */
        bool MGetStatusPartie();

        /* Ne fait rien tant que la partie n'est pas terminée */
        void MAttenteFinPartie();

        /* Se connecte au serveur */
        void MConnect();

        /* Attend une instruction du serveur */
        void MAttenteInstruction();


    protected :

        /* Port utilisé pour la socket TCP */
        int m_portTCP;

        /* Adresse ip locale vue sur le réseau local */
        sf::IPAddress m_localAddress;

        /* Adresse ip du serveur, passé en argument lors de l'execution de l'executable */
        sf::IPAddress m_serverAddress;

        /* Représente le status d'une partie */
        bool m_PartieEnCours;

        /* Socket TCP utilisée par le client */
        sf::SocketTCP m_SocketTCP;

};

#endif // Client_h
