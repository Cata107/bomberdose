#include <iostream>
#include "Server.h"

int main()
{
    Server myServer(44444);
    myServer.MAfficherStatus();
    myServer.MAttenteConnexion();
	return 1;
}
