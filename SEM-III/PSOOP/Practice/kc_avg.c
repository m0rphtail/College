#include<stdio.h>
int main()
{
	int n,i,m1,m2,m3,m4,m5,a,p;
printf("Enter the number of students:");
scanf("%d",&n);
for(i=0;i<=n;i++)
{
	printf("\nEnter the marks of 5 subjects:");
	scanf("%d %d %d %d %d",&m1,&m2,&m3,&m4,&m5);
	a=m1+m2+m3+m4+m5;
	p=a*100/500;
	printf(" Total Percentage is: %d \n",p);
	if(p>=75)
	printf("DISTINGTION!");
	else if (p<=74 && p>=60)
	printf("FIRST CLASS");
	else if(p<=59 && p>=58)
	printf("HIGHER SECOND CLASS");
	else if(p<=57 && p>=55)
	printf("SECOND CLASS");
	else if(p<=54 && p>=40)
	printf("PASS");
	else
	printf("FAIL");
}
	return 0;
}
//Kshitij Chitnis
