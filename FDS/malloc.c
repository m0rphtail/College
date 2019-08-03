#include<stdio.h>

#include<stdlib.h>
int main()
{
	int *ptr;		//This pointer will hold the base address of the block
	int n,i,sum=0;		
	n=5;			//get the number of elements
	printf("Number of elements %d",n);	
	ptr=(int*)malloc(n * sizeof(int));		//dynamically allocate memory using malloc
	if(ptr==NULL)			//check to see if memory has been allocated or not
	{
		printf("Memory not allocated");
		exit(0);
	}
	else{
		printf("Memory successfully allocated.");
		for(i=0;i<n;++i)
		{
			ptr[i]=i+1;
		}
		printf("Elements are: ");
		for(i=0;i<n;++i)
		{
			printf("%d ",ptr[i]);
		}
	}
	return 0;
}
