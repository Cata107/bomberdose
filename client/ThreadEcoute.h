#ifndef ThreadEcoute_h
#define ThreadEcoute_h
#include <SFML/Network.hpp>
#include "ToClient.h"

/* CLIENT : Ecoute par le protocole UDP par le port défini lors de la construction du Thread tant qu'une partie est en cours */
class ThreadEcoute : public sf::Thread
{
    public :
        /* Constructeur */
        ThreadEcoute( volatile bool const * _partieEnCours, ToClient * _pStructToClient );

        /* Destructeur */
        ~ThreadEcoute();

        /* Run du Thread */
        virtual void Run();

        /* Reçoit les données envoyées par le serveur tant que la partie est en cours */
        bool MReceptionDonnees();

        /* Bind la socket au port udp correspondant */
        bool MBindSocket();

        /* Affiche le ToClient en console :: DEBUG */
        void MPrintToClient(ToClient const T);

        /* Enregistre la Structure dans le GRAPHIQUE TRUE */
        bool MCommitToClient(ToClient* T);




    private :
        /* Port Udp utilisé pour bind la socket d'écoute UDP */
        unsigned int m_portUDPEcoute;

        /* Socket UDP */
        sf::SocketUDP m_SocketUdp;

        /* Pointeur vers l'état de la partie en cours contenu dans le Client */
        volatile bool const *m_pPartieEnCours;

        /** Pointeur de ToClient qui se trouve dans GRAPHIQUE TRUE **/
        ToClient* m_pVue;

};

#endif // ThreadEcoute_h
