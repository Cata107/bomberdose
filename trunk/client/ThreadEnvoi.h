#ifndef ThreadEnvoi_h
#define ThreadEnvoi_h
#include <SFML/Network.hpp>

class ThreadEnvoi : public sf::Thread
{
    public :

    /* Constructeur */
    ThreadEnvoi( volatile const bool *_pPartieEnCours, sf::IPAddress const _IPAddressServer );

    /* Destructeur */
    ~ThreadEnvoi();

    /* Run du thread */
    virtual void Run();

    /* Envoie les données du jeu au client */
    bool MEnvoiDonnees();



    protected :

    /* Le port udp qui est utilisé pour communiquer avec le serveur */
    uint m_portUDPEnvoi;

    /* L'addresse ip du serveur */
    sf::IPAddress m_IPAddressServer;

    /* Socket UDP */
    sf::SocketUDP m_SocketUdp;

    /* Le pointeur vers le bool m_PartieEnCours du client */
    volatile const bool *m_pPartieEnCours;

};



#endif // ThreadEnvoi_h
