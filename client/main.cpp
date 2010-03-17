#include <iostream>
#include "Client.h"

int main(int argc, char ** argv)
{
    Client myClient(44444, 44444, argv[1]);
    myClient.MAfficherStatus() ;
    myClient.MConnect();
    myClient.MAttenteInstruction();
	return 1;
}
