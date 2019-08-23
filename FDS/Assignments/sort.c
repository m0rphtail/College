#include<stdio.h>

void getdata();
void display();
//void bubblesort();
//void selectionsort();

int main()
{
	getdata();
	return 0;
}

void getdata()
{
	char string1[100],string2[100];
	int n;
	printf("Enter the lenght of string: ");
	scanf("%d",&n);
	printf("Enter the characters: ");
	for(int i=0;i<n;i++)
	{
		scanf("%s",&string1[n]);
	}	

	for(int i=0;i<n;i++)
	{
		printf("%s",&string1[n]);
	}
}	
