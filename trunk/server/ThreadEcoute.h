#ifndef ThreadEcoute_h
#define ThreadEcoute_h
#include <SFML/Network.hpp>
class ThreadEcoute : public sf::Thread
{
    public :
        /* Constructeur */
        ThreadEcoute( volatile const bool *_pPartieEnCours );

        /* Destructeur */
        ~ThreadEcoute();

        /* Run du thread */
        virtual void Run();

        /* Recoit des données par UDP */
        bool MReceptionDonnees();

        /* Permet de bind la socket au port passé par le constructeur du ThreadEcoute */
        bool MBindSocket();

    private :

        /* La socket UDP utilisée */
        sf::SocketUDP m_SocketUdp;

        /* Le pointeur sur l'état de la partie en cours du serveur */
        volatile const bool *m_pPartieEnCours;

        /* PORT_UDP_ECOUTE */
        uint m_portUDPEcoute;


};

#endif // ThreadEcoute_h
