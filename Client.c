#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

// initializing winsock and related variables
	WSADATA Winsockdata;
	int iWsaStartup;
	int iWsaCleanup;
	SOCKET TCPClientSocket;
	int iCloseSocket;
	struct sockaddr_in TCPServerAdd;
	int iConnect;
	int iSend;
	int iRecv;
	char RecvBuffer[512];
	int iRecvBuffer = 512;
	int iSenderBuffer = 50;
	




booking()
{

	printf("These are the seats in our buses. \n");
      printf(" [1]    [2]   | |    [Driver]\n");
	printf("  ---------------------------------\n");
	printf(" [3]    [4]   | |    [5]   [6]\n");
	printf(" [7]    [8]   | |    [9]   [10]\n");
	printf(" [11]   [12]  | |    [13]  [14]\n");
	printf(" [15]   [16]  | |    [17]  [18]\n");
	printf(" [19]   [20]  | |    [21]  [22]\n");
}

cancel(){
	return 0;
}

details(){
	return 0;
}

int main()
{
	// WSAStartup 
	iWsaStartup = WSAStartup(MAKEWORD(2, 2), &Winsockdata);
	// creating client socket
	TCPClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	// filling socket structure with address info of the server
	TCPServerAdd.sin_family = AF_INET;
	TCPServerAdd.sin_addr.s_addr = inet_addr("127.0.0.1");
	TCPServerAdd.sin_port = htons(8000);
	//  Connection to server
	iConnect = connect(TCPClientSocket, (SOCKADDR*)&TCPServerAdd, sizeof(TCPServerAdd));
	printf("THE CLIENT HAS SUCCESSFULLY CONNECTED TO THE SERVER \n");
	
	
	
	
	
	int choice; // to store customer service choice
	printf("Welcome to the bus booking section \n Enter 1: To book a seat 2: To cancel a seat 3:View booked ticket details \n");
	scanf("%d", &choice);
	if(choice == 1)
	{
		booking();
	}else if(choice == 2)
	{
		cancel();
	}else if(choice == 3)
	{
		details();
	}
	
	return 0;
}
