#include<stdio.h>

#include<stdlib.h>
int main()
{
	int *ptr;		//This pointer will hold the base address of the block
	int n,i,sum=0;
	printf("\nEnter a number: ");
	scanf("%d",&n);				//get the number of elements
	printf("\nNumber of elements %d",n);	
	ptr=(int*)malloc(n * sizeof(int));		//dynamically allocate memory using malloc
	if(ptr==NULL)			//check to see if memory has been allocated or not
	{
		printf("\nMemory not allocated");
		exit(0);
	}
	else{
		printf("\nMemory successfully allocated.");
		for(i=0;i<n;++i)
		{
			ptr[i]=i+1;
		}
		printf("\nElements are: ");
		for(i=0;i<n;++i)
		{
			printf("%d ",ptr[i]);
		}
	}
	return 0;
}
