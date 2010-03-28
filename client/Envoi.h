#ifndef ThreadEnvoi_h
#define ThreadEnvoi_h
#include <SFML/Network.hpp>
#include "ToServer.h"
class Envoi
{
    public :

    /* Constructeur */
    Envoi( sf::IPAddress const _IPAddressServer );

    /* Destructeur */
    ~Envoi();

    /* Envoie les packets concernant le client au serveur */
    bool MEnvoiPacket(ToServer const T);

    /* Permet d'initialiser une struct ToServer en fonction des bool passés en paramètres */
    bool MInitialiseToServer( ToServer& T, bool const _up, bool const _down, bool const _right, bool const _left, bool const _bomb, unsigned int _elapsed_time);

    /* Permet d'envoyer les informations sur les intentions du client directement au serveur */
    bool MEnvoiInformations( bool const _up, bool const _down, bool const _right, bool const _left, bool const _bomb, unsigned int const _elapsed_time);

    /** Méthodes à utiliser par des classes externes au package client **/
    /* Envoie l'information au serveur que le joueur souhaite se déplacer vers la gauche, avec le temps sur lequel le joueur est resté appuyé sur le bouton correspondant */
    bool MEnvoiMoveLeft( unsigned int const _elapsed_time );
    /* Envoie l'information au serveur que le joueur souhaite se déplacer vers la droite avec le temps sur lequel le joueur est resté appuyé sur le bouton correspondant*/
    bool MEnvoiMoveRight( unsigned int const _elapsed_time );
    /* Envoie l'information au serveur que le joueur souhaite se déplacer vers le haut avec le temps sur lequel le joueur est resté appuyé sur le bouton correspondant */
    bool MEnvoiMoveUp( unsigned int const _elapsed_time );
    /* Envoie l'information au serveur que le joueur souhaite se déplacer vers le bas avec le temps sur lequel le joueur est resté appuyé sur le bouton correspondant*/
    bool MEnvoiMoveDown( unsigned int const _elapsed_time );
    /* Envoie l'information au serveur que le joueur souhaite poser une bombe */
    bool MEnvoiPoseBombe();






    protected :

    /* Le port udp qui est utilisé pour communiquer avec le serveur */
    unsigned int m_portUDPEnvoi;

    /* L'addresse ip du serveur */
    sf::IPAddress m_IPAddressServer;

    /* Socket UDP */
    sf::SocketUDP m_SocketUdp;

};



#endif // ThreadEnvoi_h
