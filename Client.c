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
	int y;
	int k;
	char SenderBuffer[512] ="Book";
    //Sending Data to the server (booking)
	iSend = send(TCPClientSocket, SenderBuffer, iSenderBuffer, 0);

	printf("These are the seats in our buses. \n");
      printf(" [1]    [2]   | |    [Driver]\n");
	printf("  ---------------------------------\n");
	printf(" [3]    [4]   | |    [5]   [6]\n");
	printf(" [7]    [8]   | |    [9]   [10]\n");
	printf(" [11]   [12]  | |    [13]  [14]\n");
	printf(" [15]   [16]  | |    [17]  [18]\n");
	printf(" [19]   [20]  | |    [21]  [22]\n");
	
	printf("The following seats below have been booked:: \n" );

	for(k =0;k<=23;k++)
	{
		iRecv = recv(TCPClientSocket,RecvBuffer, iRecvBuffer, 0);
		printf("%s , ",RecvBuffer);
		y = strcmp(RecvBuffer,"none of the seats have been booked \n");
		if(y==0)
		{
			break;
		}
		
	}
	int chair;
	printf("Enter the seat you wish to book \n");
	scanf("%d",&chair);
	// sending selected book seats to the server
	if(chair == 1){
	char one[512] = "one";
	iSend = send(TCPClientSocket, one, iSenderBuffer, 0);
	}else if(chair == 2){
	char two[512] = "two";
	iSend = send(TCPClientSocket, two, iSenderBuffer, 0);
	}else if(chair == 3){
	char three[512] = "three";
	iSend = send(TCPClientSocket, three, iSenderBuffer, 0);
	}else if(chair == 4){
	char four[512] = "four";
	iSend = send(TCPClientSocket, four, iSenderBuffer, 0);
	}else if(chair == 5){
	char five[512] = "five";
	iSend = send(TCPClientSocket, five, iSenderBuffer, 0);
	}else if(chair == 6){
	char six[512] = "six";
	iSend = send(TCPClientSocket, six, iSenderBuffer, 0);
	}else if(chair == 7){
	char sev[512] = "seven";
	iSend = send(TCPClientSocket, sev, iSenderBuffer, 0);
	}else if(chair == 8){
	char eig[512] = "eight";
	iSend = send(TCPClientSocket, eig, iSenderBuffer, 0);
	}else if(chair == 9){
	char nine[512] = "nine";
	iSend = send(TCPClientSocket, nine, iSenderBuffer, 0);
	}else if(chair == 10){
	char ten[512] = "ten";
	iSend = send(TCPClientSocket, ten, iSenderBuffer, 0);
	}else if(chair == 11){
	char eleven[512] = "eleven";
	iSend = send(TCPClientSocket, eleven, iSenderBuffer, 0);
	}else if(chair == 12){
	char twel[512] = "twelve";
	iSend = send(TCPClientSocket, twel, iSenderBuffer, 0);
	}else if(chair == 13){
	char thir[512] = "thirteen";
	iSend = send(TCPClientSocket, thir, iSenderBuffer, 0);
	}else if(chair == 14){
	char fourteen[512] = "fourteen";
	iSend = send(TCPClientSocket, fourteen, iSenderBuffer, 0);
	}else if(chair == 15){
	char fif[512] = "fifteen";
	iSend = send(TCPClientSocket, fif, iSenderBuffer, 0);
	}else if(chair == 16){
	char sixt[512] = "sixteen";
	iSend = send(TCPClientSocket, sixt, iSenderBuffer, 0);
	}else if(chair == 17){
	char sevt[512] = "seventeen";
	iSend = send(TCPClientSocket, sevt, iSenderBuffer, 0);
	}else if(chair == 18){
	char eighteen[512] = "eighteen";
	iSend = send(TCPClientSocket,eighteen, iSenderBuffer, 0);
	}else if(chair == 19){
	char nineteen[512] = "nineteen";
	iSend = send(TCPClientSocket,nineteen, iSenderBuffer, 0);
	}else if(chair == 20){
	char twen[512] = "twenty";
	iSend = send(TCPClientSocket,twen, iSenderBuffer, 0);
	}else if(chair == 21){
	char twenty_one[512] = "twenty-one";
	iSend = send(TCPClientSocket,twenty_one, iSenderBuffer, 0);
	}else if(chair == 22){
	char twenty_two[512] = "twenty-two";
	iSend = send(TCPClientSocket,twenty_two, iSenderBuffer, 0);
	}
	printf("Enter your mobile number \n");
	char no[9];
	scanf("%s",no);
	// sending mobile number
	iSend = send(TCPClientSocket,no, iSenderBuffer, 0);
	printf("Enter your first name \n");
	char fname[50];
	scanf("%s",fname);
	// sending first name to server
	iSend = send(TCPClientSocket,fname, iSenderBuffer, 0);
	printf("Enter your last name \n");
	char lname[50];
	scanf("%s",lname);
	// sending last name to server
	iSend = send(TCPClientSocket,lname, iSenderBuffer, 0);
	
	// receiving confirmation (ticket_no)
	iRecv = recv(TCPClientSocket,RecvBuffer, iRecvBuffer, 0);
	int ticko = *(unsigned int*)(RecvBuffer);
	
	printf("You have successfully booked the seat, here is your ticket number:: %d",ticko);
	iCloseSocket = closesocket(TCPClientSocket);
	
	
	
	
	
	
	

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
