#include <iostream>
#include "Client.h"

int main(int argc, char ** argv)
{
    Client myClient = Client::Client(argv[1]);
    myClient.MAfficherStatus();
    myClient.MConnect();
    myClient.MAttenteInstruction();
	return 1;
}
