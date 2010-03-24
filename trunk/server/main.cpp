#include <iostream>
#include "Server.h"

int main(int argc, char ** argv)
{
    //Transformation du char du premier argument en int
    int n = argv[1][0] -'0';
    Server myServer = Server::Server(n);
    myServer.MCreateBomberdose();
    myServer.MAfficherStatus();
    myServer.MAttenteConnexion();
    myServer.MBoucleJeu();
    myServer.MDisconnect();
	return 1;
}
