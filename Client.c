#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

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
