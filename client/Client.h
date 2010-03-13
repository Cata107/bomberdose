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

        /* Retourne true si la partie est en cours, false sinon */
        bool MGetStatusPartie();

        /* Ne fait rien tant que la partie n'est pas terminée */
        void MAttenteFinPartie();

        /* Se connecte au serveur */
        void MConnect();

        /* Attend une instruction du serveur */
        bool MAttenteInstruction();

        /* Renvoie true si le buffer envoyé correspond à l'instruction STOP */
        bool MIsStop( char *_buffer );

        /* Renvoie true si le buffer envoyé correspond à l'instruction START */
        bool MIsStart( char *_buffer );

        /* Renvoie true si le buffer envoyé correspond à l'instruction QUIT */
        bool MIsQuit( char *_buffer );


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
