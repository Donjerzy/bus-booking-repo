#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

booking()
{
	return 0;
}

cancel(){
	return 0;
}

details(){
	return 0;
}

int main()
{
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
