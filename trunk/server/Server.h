#ifndef Server_h
#define Server_h
#include <SFML/Network.hpp>

class Server {
public :

    /* Constructeur */
    Server (int _port);

    void MAfficherStatus();
    void MAttenteConnexion();
    Server* MGetAdresse();

protected :

    sf::IPAddress m_localAdress;
    int m_portTCP;
    int m_nbClients;
    sf::SocketTCP m_socketTCP;
    bool m_PartieEnCours;

};

#endif // Server_h
