#include<winsock2.h>
#include <stdio.h>
#include <stdlib.h>
	WSADATA Winsockdata;
	int iWsaStartup;
	int iWsaCleanup;
	SOCKET TCPServerSocket;
	struct sockaddr_in TCPServerAdd;
	struct sockaddr_in TCPClientAdd;
	int iTCPClientAdd = sizeof(TCPClientAdd);
	int iBind;
	int iListen;
	SOCKET sAcceptSocket;
	int iSend;
	int iRecv;
	char RecvBuffer[512];
	int iRecvBuffer = 50;
	int iSenderBuffer = 512;
	int iCloseSocket;

	
	

	
int main()
{
	// WSAStartup 
	iWsaStartup = WSAStartup(MAKEWORD(2, 2), &Winsockdata);
	// filling in struct with address info of the server
	TCPServerAdd.sin_family = AF_INET;
	TCPServerAdd.sin_addr.s_addr = inet_addr("127.0.0.1");
	TCPServerAdd.sin_port = htons(8000);
	//Creating server socket
	TCPServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	// binding the server address to the socket
	iBind = bind(TCPServerSocket, (SOCKADDR*)&TCPServerAdd, sizeof(TCPServerAdd));
	while(1)
	{
		iListen = listen(TCPServerSocket, 1);
		printf("THE SERVER IS IN THE LISTENING STATE \n");
		// accepting a connection
		sAcceptSocket = accept(TCPServerSocket, (SOCKADDR*)&TCPClientAdd,&iTCPClientAdd);
		printf("THE SERVER HAS ACCEPTED A NEW CONNECTION \n");
		int new_sock = sAcceptSocket;
		
	}
	
}
