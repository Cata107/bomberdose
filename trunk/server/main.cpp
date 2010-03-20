#include <iostream>
#include "Server.h"

int main()
{
    Server myServer = Server::Server();
    myServer.MAfficherStatus();
    myServer.MAttenteConnexion();
    myServer.MGameStart();
    myServer.MAttenteFinPartie();
	return 1;
}
