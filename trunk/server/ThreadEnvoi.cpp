#include "ThreadEnvoi.h"

ThreadEnvoi::ThreadEnvoi( uint const _portUDP, uint const _numClient, sf::IPAddress const _clientAddress)
{
    m_portUDP = _portUDP;
    m_NumeroClient = _numClient;
    m_clientAddress = _clientAddress;
}
ThreadEnvoi::~ThreadEnvoi()
{

}
