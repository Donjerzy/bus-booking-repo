#include<winsock2.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct bus{
	int seat;
	char f_name[50];
	char l_name[50];
	char mobile_no[9];
	unsigned int ticket_no;
} person[22]; 


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

	
int book(int y)
{
	int v=0;
	int redo=0;
	int bul =0;
	tk:
	printf("CLIENT HAS REQUESTED FOR BOOKED SEATS \n");
	printf("SENDING BOOKED SEATS TO THE CLIENT \n");
	int k;
	for(k=0;k<=23;k++)
	{
		if(person[k].seat !=0)
		{
			if(person[k].seat == 1){
				char one[512] = "one";
				iSend = send(y, one, iSenderBuffer, 0);
				bul = 1;
			}else if(person[k].seat == 2){
				char two[512] = "two";
				iSend = send(y, two, iSenderBuffer, 0);
				bul = 1;
			}else if(person[k].seat == 3){
				char three[512] = "three";
				iSend = send(y, three, iSenderBuffer, 0);
				bul = 1;
			}else if(person[k].seat == 4){
				char four[512] = "four";
				iSend = send(y, four, iSenderBuffer, 0);
				bul = 1;
			}else if(person[k].seat == 5){
				char five[512] = "five";
				iSend = send(y, five, iSenderBuffer, 0);
				bul = 1;
			}else if(person[k].seat == 6){
				char six[512] = "six";
				iSend = send(y, six, iSenderBuffer, 0);
				bul = 1;
			}else if(person[k].seat == 7){
				char sev[512] = "seven";
				iSend = send(y, sev, iSenderBuffer, 0);
				bul = 1;
			}else if(person[k].seat == 8){
				char eig[512] = "eight";
				iSend = send(y, eig, iSenderBuffer, 0);
				bul = 1;
			}else if(person[k].seat == 9){
				char nine[512] = "nine";
				iSend = send(y, nine, iSenderBuffer, 0);
				bul = 1;
			}else if(person[k].seat == 10){
				char ten[512] = "ten";
				iSend = send(y, ten, iSenderBuffer, 0);
				bul = 1;
			}else if(person[k].seat == 11){
				char eleven[512] = "eleven";
				iSend = send(y, eleven, iSenderBuffer, 0);
				bul = 1;
			}else if(person[k].seat == 12){
				char twel[512] = "twelve";
				iSend = send(y, twel, iSenderBuffer, 0);
				bul = 1;
			}else if(person[k].seat == 13){
				char thir[512] = "thirteen";
				iSend = send(y, thir, iSenderBuffer, 0);
				bul = 1;
			}else if(person[k].seat == 14){
				char fourteen[512] = "fourteen";
				iSend = send(y, fourteen, iSenderBuffer, 0);
				bul = 1;
			}else if(person[k].seat == 15){
				char fif[512] = "fifteen";
				iSend = send(y, fif, iSenderBuffer, 0);
				bul = 1;
			}else if(person[k].seat == 16){
				char sixt[512] = "sixteen";
				iSend = send(y, sixt, iSenderBuffer, 0);
				bul = 1;
			}else if(person[k].seat == 17){
				char sevt[512] = "seventeen";
				iSend = send(y, sevt, iSenderBuffer, 0);
				bul = 1;
			}else if(person[k].seat == 18){
				char eighteen[512] = "eighteen";
				iSend = send(y,eighteen, iSenderBuffer, 0);
				bul = 1;
			}else if(person[k].seat == 19){
				char nineteen[512] = "nineteen";
				iSend = send(y,nineteen, iSenderBuffer, 0);
				bul = 1;
			}else if(person[k].seat == 20){
				char twen[512] = "twenty";
				iSend = send(y,twen, iSenderBuffer, 0);
				bul = 1;
			}else if(person[k].seat == 21){
				char twenty_one[512] = "twenty-one";
				iSend = send(y,twenty_one, iSenderBuffer, 0);
				bul = 1;
			}else if(person[k].seat == 22){
				char twenty_two[512] = "twenty-two";
				iSend = send(y,twenty_two, iSenderBuffer, 0);
				bul = 1;
			}
}
	

	if(k==23 && bul ==0)
	{
		char none[512] = "none of the seats have been booked \n";
		iSend = send(y,none, iSenderBuffer, 0);
	}else if(k==23 && bul ==1)
	{
		char dn[512] = "\n";
		iSend = send(y,dn, iSenderBuffer, 0);
	}
	}
		k = 0;
		bul= 0;
		// receiving booking details
		
		printf("RECEIVING CUSTOMER DETAILS TO FACILITATE BOOKING \n");
		
		// receiving seat number
	iRecv = recv(y, RecvBuffer, iRecvBuffer, 0);
	int chairr =  *(unsigned int*)(RecvBuffer);
	
	// checking if seat is booked
	int checker;
	int place =0;
	for(checker=1;checker<=23;checker++)
	{
		if(person[checker].seat == chairr)
		{
			place = 1;
		}
	}
	
	if(place == 1)
	{
		char tak[512] = "b";
		iSend = send(y, tak, iSenderBuffer, 0);
		goto tk;
	}else
	{
			char tak[512] = "ok";
		iSend = send(y, tak, iSenderBuffer, 0);
	}
	
	
	int i;
	for(i=1;i<23;i++)
	{
		if(person[i].seat == 0){
			break;
		}
		
	}
	
	person[i].seat = chairr;
	// receiving mobile number
	 	iRecv = recv(y, RecvBuffer, iRecvBuffer, 0);
	 	strcpy(person[i].mobile_no,RecvBuffer);
	 	// receiving first name
	 	iRecv = recv(y, RecvBuffer, iRecvBuffer, 0);
	 	strcpy(person[i].f_name,RecvBuffer);
	 	// receiving last name
	 	iRecv = recv(y, RecvBuffer, iRecvBuffer, 0);
	 	strcpy(person[i].l_name,RecvBuffer);
	 	// generating ticket no
	 	srand(time(0));
	 	ticket: ;
	 	int randdomized = rand() % 100 + 1;
	 	while(v<=23)
	{
		if(person[v].ticket_no == randdomized){
		redo=1;
		v++;
		}
	v++;
	}
	
	if(redo==1)
	{
	redo =0;
		goto ticket;
	}
	person[i].ticket_no = randdomized;
	printf("I HAVE GENERATED THE FOLLOWING TICKET NUMBER :: %d \n",randdomized);
	printf("I HAVE STORED THE FOLLOWING TICKET NUMBER :: %d \n",person[i].ticket_no);
	
	
	char ticketnum[512];
	memcpy(ticketnum, (char*)&randdomized,sizeof(unsigned int));
	
	int foll =  *(unsigned int*)(ticketnum);

	
	//sending ticket number to client
	iSend = send(y,ticketnum, iSenderBuffer, 0);
			
  return 0;	
}



int cancel(int y)
{
	printf("THE USER WANTS TO CANCEL AN EXISTING BOOKING \n");
	
	// receiving ticket_no
	iRecv = recv(y, RecvBuffer, iRecvBuffer, 0);
	int ticketNo = *(unsigned int*)(RecvBuffer);
	// receiving seat_no
	iRecv = recv(y, RecvBuffer, iRecvBuffer, 0);
	int seatNo = *(unsigned int*)(RecvBuffer);
	
	int i;
	int z = 0;
	for(i=1;i<=23;i++)
	{
		if(person[i].seat == seatNo && person[i].ticket_no == ticketNo)
		{
			strcpy(person[i].f_name,"NULL");
			strcpy(person[i].l_name,"NULL");
			strcpy(person[i].mobile_no,"NULL");
			person[i].seat = 0;
			person[i].ticket_no = 0;
			printf("THE BOOKING HAS BEEN CANCELLED SENDING CONFIRMATION TO CLIENT \n");
			//sending confirmation to client
			char mess[512] = "done";
			iSend = send(y,mess, iSenderBuffer, 0);
			z =1;
			break;
		}
	}
	if(z == 0)
	{
		//sending confirmation to client
			char fail[512] = "fail";
			iSend = send(y,fail, iSenderBuffer, 0);
	}
	
	return 0;
}

int details(int y)
{
	printf("USER WANTS TO VIEW THEIR BOOKING DETAILS \n");
	// receiving ticket_no
	iRecv = recv(y, RecvBuffer, iRecvBuffer, 0);
	int ticketNo = *(unsigned int*)(RecvBuffer);
	// receiving seat_no
	iRecv = recv(y, RecvBuffer, iRecvBuffer, 0);
	int seatNo = *(unsigned int*)(RecvBuffer);
	
	int i;
	int z = 0;
	for(i=1;i<=23;i++)
	{
		if(person[i].seat == seatNo && person[i].ticket_no == ticketNo)
		{
			char fname[512];
			char lname[512];
			char mobile[9];
			strcpy(fname,person[i].f_name);
			strcpy(lname,person[i].l_name);
			strcpy(mobile,person[i].mobile_no);
			char mess[512] = "done";
			iSend = send(y,mess, iSenderBuffer, 0);
			printf("SENDING BOOKING DETAILS TO THE CLIENT \n");
			//sending details to client
			iSend = send(y,fname, iSenderBuffer, 0);
			iSend = send(y,lname, iSenderBuffer, 0);
			iSend = send(y,mobile, iSenderBuffer, 0);
			z =1;
			break;
		}
	}
	if(z == 0)
	{
		//sending confirmation to client
			char fail[512] = "fail";
			iSend = send(y,fail, iSenderBuffer, 0);
	}
	
		return 0;
	
}




	
int main()
{
	 int x;
 for(x=0;x<=23;x++)
 {
 	person[x].seat = 0;
 	person[x].ticket_no = 0;
 }
	
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
		
		continu:
		iRecv = recv(new_sock, RecvBuffer, iRecvBuffer, 0);
		// comparing strings to message received in the buffer in order to determine  the service requested by the client
		int ch1 = strcmp(RecvBuffer,"Book");
		int ch2 = strcmp(RecvBuffer,"Cancel");
		int ch3 = strcmp(RecvBuffer,"details");
		
		if(ch1 == 0)
		{
			book(new_sock);
		}else if(ch2 == 0)
		{
			cancel(new_sock);
		}else if(ch3 == 0)
		{
			details(new_sock);
		}
		
		iRecv = recv(new_sock, RecvBuffer, iRecvBuffer, 0);
		int cont = strcmp(RecvBuffer,"cont");
		if(cont == 0)
		{
			goto continu;
		}else {
				iCloseSocket = closesocket(new_sock);
		}
	}
	
	return 0;

	
}

