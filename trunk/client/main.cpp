#include <iostream>
#include "Client.h"

int main(int argc, char ** argv)
{
   Client myClient = Client::Client(/*argv[1]*/"5.13.213.237");
    myClient.MAfficherStatus();
    myClient.MConnect();
    myClient.MAttenteInstruction();
	return 1;
}
