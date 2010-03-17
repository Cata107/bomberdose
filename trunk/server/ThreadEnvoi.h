#ifndef ThreadEnvoi_h
#define ThreadEnvoi_h
#include <SFML/Network.hpp>
/* SERVEUR : Se charge d'envoyer uniquement des données au client par les sockets UDP */
class ThreadEnvoi : public sf::Thread
{
    public :

    /* Constructeur */
    ThreadEnvoi( uint const _portUDP, volatile const bool *_pPartieEnCours );

    /* Destructeur */
    ~ThreadEnvoi();

    /* Run du thread */
    virtual void Run();

    /* Envoie les données du jeu au client */
    bool MEnvoiDonnees();



    protected :

    /* Le port udp qui est utilisé pour communiquer avec les clients */
    uint m_portUDP;

    /* Socket UDP */
    sf::SocketUDP m_SocketUdp;

    /* Le pointeur vers le bool m_PartieEnCours du serveur */
    volatile const bool *m_pPartieEnCours;


};

#endif // ThreadEnvoi_h