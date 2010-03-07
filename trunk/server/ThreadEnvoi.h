#ifndef ThreadEnvoi_h
#define ThreadEnvoi_h
#include <SFML/Network.hpp>
/* Se charge d'envoyer uniquement des données par les sockets UDP */
class ThreadEnvoi : public sf::Thread
{
    public :

    ThreadEnvoi( uint const _portUDP, uint const _numClient, sf::IPAddress const _clientAddress );
    ~ThreadEnvoi();
    virtual void Run();
    bool MEnvoiDonnees();
    bool MGameStart();
    bool MGameStop();





    protected :

    uint m_portUDP;
    uint m_NumeroClient;
    sf::IPAddress m_clientAddress;
    volatile bool m_PartieEnCours;


};

#endif // ThreadEnvoi_h
