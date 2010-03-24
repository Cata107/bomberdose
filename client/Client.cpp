#include "Client.h"
#include "MacroClient.h"
Client::Client(char const * _addressIpServer)
{
    m_portTCP = PORT_TCP;
    m_localAddress = sf::IPAddress::GetLocalAddress();
    m_serverAddress = sf::IPAddress::IPAddress(_addressIpServer);
    m_PartieEnCours = false;
    m_SocketTCP = sf::SocketTCP::SocketTCP();
}
Client::~Client()
{
    m_SocketTCP.Close();
}
void Client::MAfficherStatus()
{
    std::cout<< "Client, Adresse locale et port : " << m_localAddress.ToString() <<":"<< m_portTCP << std::endl;
    std::cout<< "Adresse serveur : "<< m_serverAddress << std::endl;
}
bool Client::MGetStatusPartie()
{
    return m_PartieEnCours;
}
void Client::MAttenteFinPartie()
{
    while (m_PartieEnCours)
    {
        usleep( DODO );
    }
}
bool Client::MConnect()
{
    if (m_SocketTCP.Connect(m_portTCP, m_serverAddress) != sf::Socket::Done)
    {
        std::cout<< "Erreur de connection au serveur" << std::endl;
        return false;
    }
    else
    {
        std::cout << "Connection au serveur " << m_serverAddress.ToString() << " par le port " << m_portTCP << " effectuée"<< std::endl;
    }
    return true;

}
bool Client::MAttenteInstruction()
{
    char Buffer [2];
    while ( !MInstructionIsQuit( Buffer ) )
    {
        std::size_t Received;
        if (m_SocketTCP.Receive(Buffer, sizeof(Buffer), Received) != sf::Socket::Done)
        {
            if (m_SocketTCP.Receive(Buffer, sizeof(Buffer), Received) == sf::Socket::Disconnected)
            {
                std::cout<<"Déconnection du serveur"<<std::endl;
                return false;
            }
            else
            std::cout<<"Problème de réception des données du serveur"<<std::endl;
        }
        else
        {
            std::cout<< "Instruction : " << Buffer << std::endl;
            if ( MInstructionIsStart( Buffer ) )
            {
                std::cout<<"La partie va commencer ..."<<std::endl;
                MGameStart();
                usleep ( 10000000 );
                m_pEnvoi->MEnvoiPoseBombe();
            }
            if ( MInstructionIsStop ( Buffer ) )
            {
                std::cout<<"La partie va s'arrêter ..."<<std::endl;
                MGameStop();
            }

        }
    }
    std::cout << "Fermeture du client" << std::endl;
    return true;

}
bool Client::MInstructionIsStart( char const *_buffer)
{
    bool retour = false;
    if ( _buffer[0]== CHARSTART )
    {
        retour = true;
    }
    return retour;
}

bool Client::MInstructionIsStop( char const *_buffer )
{
    bool retour = false;
    if ( _buffer[0]== CHARSTOP )
    {
        retour = true;
    }
    return retour;
}
bool Client::MInstructionIsQuit( char const *_buffer )
{
    bool retour = false;
    if ( _buffer[0]== CHARQUIT )
    {
        retour = true;
    }
    return retour;
}
bool Client::MGameStart()
{
    m_PartieEnCours = true;
    MCreateFils();
    m_pThreadEcoute->Launch();
    return true;
}
bool Client::MCreateFils()
{
    MCreateEcoute();
    MCreateEnvoi();
    return true;
}
bool Client::MCreateEcoute()
{
    m_pThreadEcoute = new ThreadEcoute( &m_PartieEnCours );
    return true;
}
bool Client::MCreateEnvoi()
{
    m_pEnvoi = new Envoi( m_serverAddress );
    return true;
}
bool Client::MGameStop()
{
    m_PartieEnCours = false;
    MDeleteFils();
    return true;
}
bool Client::MDeleteFils()
{
    MDeleteEcoute();
    MDeleteEnvoi();
    return true;
}
bool Client::MDeleteEnvoi()
{
    delete m_pEnvoi;
    std::cout<<"SUPPRESSION ENVOI EFFECTUEE"<<std::endl;
    return true;
}
bool Client::MDeleteEcoute()
{
    std::cout<<"SUPPRESSION THREAD ECOUTE EN COURS"<<std::endl;
    m_pThreadEcoute->Wait();
    delete m_pThreadEcoute;
    std::cout<<"SUPPRESSION THREAD ECOUTE EFFECTUEE"<<std::endl;
    return true;
}
