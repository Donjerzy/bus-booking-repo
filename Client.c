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
	tk:
	printf("These are the seats in our buses. \n");
      printf(" [1]    [2]   | |    [Driver]\n");
	printf("  ---------------------------------\n");
	printf(" [3]    [4]   | |    [5]   [6]\n");
	printf(" [7]    [8]   | |    [9]   [10]\n");
	printf(" [11]   [12]  | |    [13]  [14]\n");
	printf(" [15]   [16]  | |    [17]  [18]\n");
	printf(" [19]   [20]  | |    [21]  [22]\n");
	
	printf("The following seats below have been booked:: \n" );

	for(k=0;k<=23;k++)
	{
		
		iRecv = recv(TCPClientSocket,RecvBuffer, iRecvBuffer, 0);
		printf("%s , ",RecvBuffer);
	
		y = strcmp(RecvBuffer,"none of the seats have been booked \n");
		int zgw =  strcmp(RecvBuffer,"\n");
	
		
		if(y==0)
		{
			break;
		}
		
		if(zgw == 0)
		{
			break;
		} 
	
	}
	int chair;
	printf("Enter the seat you wish to book \n");
	scanf("%d",&chair);
	// sending selected book seats to the server
	char chairr[520];
	memcpy(chairr, (char*)&chair,sizeof(unsigned int));
	iSend = send(TCPClientSocket,chairr, iSenderBuffer, 0);
	
	//confirmation if seat is free
	char conf[512];
	iRecv = recv(TCPClientSocket,conf, iRecvBuffer, 0);
	int co = strcmp(conf,"b");
	if(co==0)
	{
		printf("The seat you have chosen has already been booked \n");
		goto tk;
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
	
	char ticNo[512];
	// receiving confirmation (ticket_no)
	iRecv = recv(TCPClientSocket,ticNo, iRecvBuffer, 0);
	int ticko = *(unsigned int*)(ticNo);
	
	printf("You have successfully booked the seat, here is your ticket number:: %d \n",ticko);
	return 0;
	
	
	
	
	
	
	

}

cancel(){
	char SenderBuffer[512] ="Cancel";
    //Sending Data to the server (booking)
	iSend = send(TCPClientSocket, SenderBuffer, iSenderBuffer, 0);
	printf("What is the seat you had earlier booked? \n");
	int seat;
	scanf("%d",&seat);
	printf("What is your ticket number ?\n");
	int ticko;
	scanf("%d",&ticko);
	printf("Are you sure you want to cancel this seat? Enter 1 for yes or 2 for no \n");
	int ch;
	scanf("%d",&ch);
	if(ch==1)
	{
	// sending booking details to server for cancellation
	char ticketnum[512];
	char seatNo[512];
	memcpy(seatNo, (char*)&seat,sizeof(unsigned int));
	memcpy(ticketnum, (char*)&ticko,sizeof(unsigned int));
	// sending ticket_no to server
	iSend = send(TCPClientSocket,ticketnum, iSenderBuffer, 0);
	//sending seat_no to server
	iSend = send(TCPClientSocket,seatNo, iSenderBuffer, 0);
	// receiving confirmation/denial
	iRecv = recv(TCPClientSocket,RecvBuffer, iRecvBuffer, 0);
	int com = strcmp(RecvBuffer,"done");
	int notcom = strcmp(RecvBuffer,"fail");
	if(com == 0)
	{
		printf("Your booking has successfully been cancelled \n");
	}else if(notcom == 0)
	{
		printf("Your booking does not exist or you have entered wrong details :o \n");
	}

	return 0;
}else{
		return 0;
}

}

details(){
	char SenderBuffer[512] ="details";
    //Sending Data to the server (details)
	iSend = send(TCPClientSocket, SenderBuffer, iSenderBuffer, 0);
	printf("What is the seat you had earlier booked? \n");
	int seat;
	scanf("%d",&seat);
	printf("What is your ticket number ?\n");
	int ticko;
	scanf("%d",&ticko);
	
	
	// sending booking details to server 
	char ticketnum[512];
	char seatNo[512];
	memcpy(seatNo, (char*)&seat,sizeof(unsigned int));
	memcpy(ticketnum, (char*)&ticko,sizeof(unsigned int));
	// sending ticket_no to server
	iSend = send(TCPClientSocket,ticketnum, iSenderBuffer, 0);
	//sending seat_no to server
	iSend = send(TCPClientSocket,seatNo, iSenderBuffer, 0);
	// receiving confirmation/denial
	iRecv = recv(TCPClientSocket,RecvBuffer, iRecvBuffer, 0);
	
	int com = strcmp(RecvBuffer,"done");
	int notcom = strcmp(RecvBuffer,"fail");
	if(com == 0)
	{
	printf("The following details are associated with the booking \n");
	// receiving confirmation/denial
	iRecv = recv(TCPClientSocket,RecvBuffer, iRecvBuffer, 0);
	printf("First Name: %s \n",RecvBuffer);
	iRecv = recv(TCPClientSocket,RecvBuffer, iRecvBuffer, 0);
	printf("Last Name: %s \n",RecvBuffer);
	iRecv = recv(TCPClientSocket,RecvBuffer, iRecvBuffer, 0);
	printf("Mobile number: %s \n",RecvBuffer);
	}else if(notcom == 0)
	{
		printf("Your booking does not exist or you have entered wrong details :o \n");
	}
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
	
	
	continu: ;
	int cont;
	
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
	
	printf("Are you done? If yes enter 1 if no enter 0 \n");
	int ch;
	scanf("%d",&ch);
	if(ch==1)
	{
		printf("Thank you for using my bus booking platform, Goodbye :) \n");
		iCloseSocket = closesocket(TCPClientSocket);
		exit(0);
	}else if(ch==0)
	{
	 char SenderBuffer[512] = "cont";
	//Sending don't terminate connection to the server (details)
	iSend = send(TCPClientSocket, SenderBuffer, iSenderBuffer, 0);
	goto continu;	
	}
	return 0;
}

