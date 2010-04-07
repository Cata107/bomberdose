#ifndef Client_h
#define Client_h
#include <SFML/Network.hpp>
#include <iostream>
#include "ThreadEcoute.h"
#include "Envoi.h"
#include "ToClient.h"
#include "../Graphique TRUE/Screen.h"
class Client {
    /* Client qui se connecte au serveur par TCP pour lui donner les informations importantes, notamment l'adresse ip ; se charge de créer les sous threads de communication avec le serveur */
    public :

        /* Constructeur */
        Client(char const* _addressIpServer/*, ToClient* _pStructToClient */);

        /* Destructeur */
        ~Client();

        /* Affiche les attributs du client */
        void MAfficherStatus();

        /* Retourne true si la partie est en cours, false sinon */
        bool MGetStatusPartie();

        /* Ne fait rien tant que la partie n'est pas terminée */
        void MAttenteFinPartie();

        /* Se connecte au serveur */
        bool MConnect();

        /* Attend une instruction du serveur */
        bool MAttenteInstruction();

        /* Renvoie true si le buffer envoyé correspond à l'instruction STOP */
        bool MInstructionIsStop( char const *_buffer );

        /* Renvoie true si le buffer envoyé correspond à l'instruction START */
        bool MInstructionIsStart( char const *_buffer );

        /* Renvoie true si le buffer envoyé correspond à l'instruction QUIT */
        bool MInstructionIsQuit( char const *_buffer );

        /* Déclare qu'une partie va commencer */
        bool MGameStart();

        /* Termine la partie */
        bool MGameStop();

        /* Crée les fils du client */
        bool MCreateFils();

        /* Crée le ThreadEnvoi du client */
        bool MCreateEnvoi();

        /* Crée le ThreadEcoute du client */
        bool MCreateEcoute();

        /* Supprime les threads fils */
        bool MDeleteFils();

        /* Supprime le ThreadEcoute */
        bool MDeleteEcoute();

        /* Supprime le ThreadEnvoi */
        bool MDeleteEnvoi();

        /* Récupère un pointeur sur l'état de la partie */
        bool * MGetPointeurPartieEncours();


    protected :

        /* Port utilisé pour la socket TCP */
        unsigned int m_portTCP;

        /* Adresse ip locale vue sur le réseau local */
        sf::IPAddress m_localAddress;

        /* Adresse ip du serveur, passé en argument lors de l'execution de l'executable */
        sf::IPAddress m_serverAddress;

        /* Représente le status d'une partie */
        bool m_PartieEnCours;

        /* Socket TCP utilisée par le client */
        sf::SocketTCP m_SocketTCP;

        /* Thread fils d'écoute UDP */
        ThreadEcoute * m_pThreadEcoute;

        /* Thread fils d'envoi UDP */
        Envoi* m_pEnvoi;

        /** Pointeur vers la fenêtre de jeu **/
        Screen* m_pScreen;

        //ToClient * m_pStructToClient;

};

#endif // Client_h
