#include <iostream>
#include "Server.h"

int main()
{
    Server myServer(44444);
    myServer.MAfficherStatus();
    myServer.MAttenteConnexion();
	std::cout << "HELLO" << std::endl ;
	return 1;
}