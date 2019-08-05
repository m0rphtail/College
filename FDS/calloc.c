#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *ptr;
	int n,i,sum=0;
	printf("Enter a number: ");
	scanf("%d",&n);
	printf("\nNumber of elements: %d",n);
	ptr=(int*)calloc(n,sizeof(int));
	if(ptr==NULL)
	{
		printf("\nMemory not allocated.");
		exit(0);
	}
	else
	{
		printf("\nMemory allocated successfully.");
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

