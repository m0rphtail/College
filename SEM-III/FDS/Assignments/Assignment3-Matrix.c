#include<stdio.h>
void add(int [][100],int [][100],int,int,int,int);
void sub(int [][100],int [][100],int,int,int,int);
void mul(int[][100],int [][100],int,int,int,int);
void transpose(int[][100],int,int);
void saddle(int[][100],int,int);

int main()
{
	 int a[100][100],b[100][100];
	 int i=0,j=0,r1,r2,c1,c2,ch;
	a:
	 printf("\nEnter number of row:");
	 scanf("%d",&r1);
	if(r1<=0)
	{
		printf("Invalid number. Enter again!\n");
		goto a;
	}
	else{}
	b:
	 printf("\nEnter number of coloumn:");
	 scanf("%d",&c1);
	if(c1<=0)
	{
		printf("Invalid number. Enter again!");
		goto b;
	}
	else{}
	 printf("\nEnter first matrix:");
	 for(i=0;i<r1;i++)
	 {
		  for(j=0;j<c1;j++)
		   { 
			    scanf("%d",&a[i][j]);
		    }
	 }   
 
	 printf("\nFirst matrix is:\n");
	  for(i=0;i<r1;i++)
	 {
		  for(j=0;j<c1;j++)
		   { 
			    printf("\t%d",a[i][j]);
		    }
		    printf("\n");
	 }
	 c:
	  printf("\nEnter number of row:");
	 scanf("%d",&r2);
	if(r2<=0)
	{
		printf("Invalid number. Enter again!");
		goto c;
	}
	else{}
	d:
	 printf("\nEnter number of coloumn:");
	 scanf("%d",&c2);
	if(c2<=0)
	{
		printf("Invalid number. Enter again!");
		goto d;
	}
	 printf("\nEnter second matrix:");
	 for(i=0;i<r2;i++)
	 {
		  for(j=0;j<c2;j++)
		   { 
			    scanf("%d",&b[i][j]);
		    }
	 }   
 
	 printf("\nSecond matrix is:\n");
 
 

	 for(i=0;i<r2;i++)
	 {
		  for(j=0;j<c2;j++)
		   { 
			    printf("\t%d",b[i][j]);
		    }
		    printf("\n");
	 }    
	 do{
	printf("\n1.Addition of matrix\n2.Subtaction of matrix\n3.Multiplication\n4.Transpose\n5.Saddle point\n6.Exit\n");
	printf("\nEnter your choice : ");
	scanf("%d",&ch);
switch(ch)
{
case 1:	
     add(a,b,r1,c1,r2,c2);
      break;
 case 2:
      sub(a,b,r1,c1,r2,c2);
      break;
 case 3:

     mul(a,b,r1,c2,r2,c2);

       break;
 case 4:
     transpose(a,r1,c1);
      break;
 case 5:
     saddle(a,r1,c1);
     break;
 
}}while(ch!=6);
 return 0;
} 



void add(int a[100][100],int b[100][100],int r1,int c1,int r2,int c2)
 
  {
	int i,j,d[100][100];
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			d[i][j]=a[i][j]+b[i][j];
		}
	}
	printf("\nAddition of matrix is :\n");
	for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				printf("%d\t",d[i][j]);
			}
		printf("\n");
		}
}





void sub(int a[100][100],int b[100][100],int r1,int c1,int r2,int c2)
 
  {
	int i,j,s[100][100];
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			s[i][j]=a[i][j]-b[i][j];
		}
	}
	printf("\nSubtraction of matrix is :\n");
	for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				printf("%d\t",s[i][j]);
			}
		printf("\n");
		}
}

void mul(int a[100][100],int b[100][100],int r1,int c1,int r2,int c2)

{ 
  int i,j,k,e[100][100],x=0;
  
  if(c1==r2)
  {
   for(i=0;i<r1;i++)
    { 
      for(j=0;j<c1;j++)
       { 
         x=0;
          for(k=0;k<c1;k++)
           { 
             x=x+a[i][k]*b[k][j];
             e[i][j]=x;
             
            }
         }
     }
   printf("\nMultiplication of two matrix is :\n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			printf("%d\t",e[i][j]);
		}
		printf("\n");
	} 
   }	

	 
	 else
	 {
	   printf("\nMultiplication not possible!!");
	  }
}	  
	 
	 void transpose(int a[100][100],int r1,int c1)
	 {
	  int i,j;
	  
	  int t[100][100];
	  for(i=0;i<r1;i++)
	   {
	     for(j=0;j<c1;j++)
	      { 
	       t[j][i]=a[i][j];
	      }
	   }
	   printf("\nTranspose of  matrix is :\n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			printf("%d\t",t[i][j]);
		}
		printf("\n");
	}
}	 
	
	       
	
        

void saddle(int a[100][100],int r1,int c1)
 {
   int i,j,k=0,h;
   int n,n1;
for(i=0;i<r1;i++)
{
    n=a[i][0];
  for(j=0;j<c1;j++)
   {
    
     if(n>=a[i][j])
       {
         n=a[i][j];
         k=j;
        }
   }     
        n1=a[0][k];
     for(h=0;h<r1;h++)
      { 
       if(n1<=a[h][k])
         { 
           n1=a[h][k];
          }
      }
       
        if(n1==n)
          {
           printf("\nThe saddle point is found!!");
           printf("\nThe saddle point is:%d at row %d and column %d\n\n",n,i+1,k+1);
          
         break;
         
          }
          
                
         
      }
      if(n1!=n)
       { 
        printf("Saddle point not found!!");
       }
        
  }    
