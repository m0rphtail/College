#include<iostream>
using namespace std;
int main()
{
	int n,i,m1,m2,m3,m4,m5,a,p;
cout<<"Enter the number of students:";
cin>>n;
for(i=0;i<=n;i++)
{
	cout<<"\nEnter the marks of 5 subjects:";
	cin>>m1>>m2>>m3>>m4>>m5;
	a=m1+m2+m3+m4+m5;
	p=a*100/500;
	cout<<" Total Percentage is:"<<p<<"\n";
	if(p>=75)
	cout<<"DISTINGTION!";
	else if (p<=74 && p>=60)
	cout<<"FIRST CLASS";
	else if(p<=59 && p>=58)
	cout<<"HIGHER SECOND CLASS";
	else if(p<=57 && p>=55)
	cout<<"SECOND CLASS";
	else if(p<=54 && p>=40)
	cout<<"PASS";
	else
	cout<<"FAIL";
}
	return 0;
}
