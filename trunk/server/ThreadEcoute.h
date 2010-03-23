#ifndef ThreadEcoute_h
#define ThreadEcoute_h
#include <SFML/Network.hpp>
#include "ToServer.h"
#include <BomberDose.h>
class ThreadEcoute : public sf::Thread
{
    public :
        /* Constructeur */
        ThreadEcoute( volatile const bool *_pPartieEnCours, int* _tabCorrespondanceIP, BomberDose* _pointeurBomberdose );

        /* Destructeur */
        ~ThreadEcoute();

        /* Run du thread */
        virtual void Run();

        /* Recoit des données par UDP */
        bool MReceptionDonnees();

        /* Permet de bind la socket au port passé par le constructeur du ThreadEcoute */
        bool MBindSocket();

        /* Affiche le ToServer, fonction de débuggage */
        void MPrintToServer(ToServer const T);

        /* récupère le numéro du joueur en fonction de son addresse ip */
        int MGetNumJoueur ( int const _addresseIP );

        bool MCommitToServer ( ToServer const T, int const _numJoueur );

    private :

        /* La socket UDP utilisée */
        sf::SocketUDP m_SocketUdp;

        /* Le pointeur sur l'état de la partie en cours du serveur */
        volatile const bool *m_pPartieEnCours;

        /* PORT_UDP_ECOUTE */
        uint m_portUDPEcoute;

        /* Tableau de LUT pour savoir à qui correspond quelle adresse ip */
        int * m_tableauIP;

        /** POINTEUR VERS BOMBERDOSE **/
        BomberDose* m_pBomberdose;


};

#endif // ThreadEcoute_h
