#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	FILE *fp;
	char data[100];
	//opening an existing file
	printf("Opening the file test.txt in writing mode");
	fp = fopen("test.txt","w");
	if(fp == NULL)
	{
		printf("Could not open file test.txt");
		return 1;
	}
	printf("\nEnter some text: ");
	//getting user input
	while( strlen ( gets ( data ) ) >0 )
	{
		//writing in the file
		fputs(data,fp);
		fputs("\n",fp);
	}
	//closing the file
	printf("Closing the file test.txt");
	fclose(fp);
	return 0;
}

