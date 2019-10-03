#include<stdio.h>

int main()
{
	int a[3][3], b[3][3], c[3][3] , t[3][3], i, j;
	int ch;
	char r;

void input()
{
	printf("Enter the elements of A:");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
}

void display()
{
	printf("Elements in the matrix A are:\n ");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("\t%d", a[i][j]);
		}
		printf("\n");
	}
}

void check()
{
	printf("\n");

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(a[i][j]!=0)
			{
				printf("\t%d at position (%d,%d)\n", a[i][j], i, j);
			}
			else continue;
		}
	}
}

void addition()
{
	printf("\nEnter the elements of B:");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	printf("\nElements in the matrix A are:\n ");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("\t%d", a[i][j]);
		}
		printf("\n");
	}
	printf("\nElements in the matrix  are:\n ");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("\t%d", b[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
		printf("\n");
	}
	
	printf("\nAddition is: \n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("\t%d", c[i][j]);
		}
		printf("\n");
	}
}

void transpose()
{
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			t[i][j] = a[j][i];
		}
		printf("\n");
	}

	printf("\nTranspose is:\n ");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("\t%d", t[i][j]);
		}
		printf("\n");
	}
}
a:
	input();
	display();
	check();
	printf("\n   MENU\n1) Addition\n2) Transpose\nEnter a choice: ");
	scanf("%d", &ch);
	switch(ch)
	{
	case 1:addition();
		break;
	case 2:transpose();
		break;
	
	}
	printf("\nDo you want to continue? (y/n): ");
	scanf("%s", &r);
	if(r=='y')
	goto a;
	return 0;
}


