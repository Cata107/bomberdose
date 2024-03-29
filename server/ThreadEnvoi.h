#ifndef ThreadEnvoi_h
#define ThreadEnvoi_h
#include <SFML/Network.hpp>
#include <vector>
#include "Sclient.h"
#include "ToClient.h"
#include <BomberDose.h>
class Sclient;

/* SERVEUR : Se charge d'envoyer uniquement des données au client par les sockets UDP */
class ThreadEnvoi : public sf::Thread
{
    public :

    /* Constructeur */
    ThreadEnvoi( volatile const bool *_pPartieEnCours, std::vector< Sclient* >  _ListeClients, BomberDose* _pointeurBomberdose, sf::Mutex* _pMutex );

    /* Destructeur */
    ~ThreadEnvoi();

    /* Run du thread */
    virtual void Run();

    /* Envoie les données du jeu au client */
    bool MEnvoiDonnees();

    bool MInitialise (ToClient& T);



    protected :

    /* Socket UDP */
    sf::SocketUDP m_SocketUdp;

    /* Le pointeur vers le bool m_PartieEnCours du serveur */
    volatile const bool *m_pPartieEnCours;

    /* La liste des clients connectés au serveur */
    std::vector<Sclient*> m_ListeClients;

    /* PORT_UDP_ENVOI */
    unsigned int m_portUDPEnvoi;

    /* Pointeur vers le mutex principal du serveur */
    sf::Mutex* m_pMutex;

    /** Pointeur vers le BOMBERDOSE **/
    BomberDose* m_pBomberdose;



};

#endif // ThreadEnvoi_h
