#ifndef ThreadEcoute_h
#define ThreadEcoute_h
#include <SFML/Network.hpp>
/* CLIENT : Ecoute par le protocole UDP par le port défini lors de la construction du Thread tant qu'une partie est en cours */
class ThreadEcoute : public sf::Thread
{
    public :
        /* Constructeur */
        ThreadEcoute( uint _portUdp, volatile bool const * _partieEnCours );

        /* Destructeur */
        ~ThreadEcoute();

        /* Run du Thread */
        virtual void Run();

        /* Reçoit les données envoyées par le serveur tant que la partie est en cours */
        bool MReceptionDonnees();

        /* Bind la socket au port udp correspondant */
        bool MBindSocket();



    private :
        /* Port Udp utilisé pour bind la socket UDP */
        uint m_PortUDP;

        /* Socket UDP */
        sf::SocketUDP m_SocketUdp;

        /* Pointeur vers l'état de la partie en cours contenu dans le Client */
        volatile bool const *m_pPartieEnCours;

};

#endif // ThreadEcoute_h
