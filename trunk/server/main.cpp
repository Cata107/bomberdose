#include <iostream>
#include "Server.h"

int main()
{
    Server myServer(44444, 44444);
    myServer.MAfficherStatus();
    myServer.MAttenteConnexion();
    myServer.MGameStart();
    myServer.MAttenteFinPartie();
	return 1;
}