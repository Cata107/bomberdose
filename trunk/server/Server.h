#ifndef Server_h
#define Server_h
#include <SFML/Network.hpp>
#include <vector>
#include "Sclient.h"
#include "ThreadEcoute.h"
#include "ThreadEnvoi.h"
#include <BomberDose.h>
class Server {
    /* gère l'inscription des clients au serveur, crée pour chaque client un thread principal */

public :

    /* Constructeur */
    Server ( int const _nbClientsAttendus );

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
    bool MAjouterClient(Sclient * _sclient);

    /* Nettoie la liste des clients */
    bool MNettoyerListeClients();

    /* Envoie une instruction à tous les clients enregistrés dans la liste des threads principaux */
    bool MEnvoiInstructionClients(int const _msg);

    /* Se charge de transmettre à tous les threads du programme qu'une partie va commencer */
    bool MGameStart();

    /* Se charge de transmettre à tous les threads du programme qu'une partie est terminée */
    bool MGameStop();

    /* Crée les threads fils */
    bool MCreateFils();

    /* tue les fils */
    bool MDeleteFils();

    /* Supprime correctement le ThreadEnvoi correspondant à ce ThreadPrincipal. */
    bool MDeleteEnvoi();

    /* Supprime correctement le ThreadEcoute correspondant à ce ThreadPrincipal. */
    bool MDeleteEcoute();

    /* Crée le ThreadEnvoi correspondant à ce ThreadPrincipal */
    bool MCreateEnvoi();

    /* Crée le ThreadEcoute correspondant à ce ThreadPrincipal */
    bool MCreateEcoute();

    /* Récupère les addresses ip des clients connectés sous forme d'un tableau d'int */
    int* MGetTableauIP();

    /** Méthodes agissant sur les attributs du moteur du jeu **/
    bool MCreateBomberdose();




protected :

    /* Adresse locale telle qu'elle est vue sur le réseau local */
    sf::IPAddress m_localAdress;

    /* Nombre de clients connectés à ce serveur */
    unsigned int m_nbClients;

    /* Nombre de clients attendus à la connexion */
    unsigned int m_nbClientsAttendus;

    /* Socket TCP du serveur */
    sf::SocketTCP m_socketTCP;

    /* Permet de savoir si la partie a été lancée ou non */
    bool m_PartieEnCours;

    /* Stocke les clients connectés sur le serveur */
    std::vector<Sclient*> m_ListeClients;

    /* pointeur vers le thread fils d'envoi */
    ThreadEnvoi* m_pThreadEnvoi;

    /* pointeur vers le thread fils d'écoute */
    ThreadEcoute* m_pThreadEcoute;

    /* PORT_TCP */
    unsigned int m_portTCP;

    /** Attributs concernant la partie moteur du jeu **/

    /* Pointeur vers le Bomberdose */
    BomberDose* m_pBomberdose;
};

#endif // Server_h
