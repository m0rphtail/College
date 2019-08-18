//program to calculate are of cirecle,rectangle and triangle using function overloading

#include<iostream>
using namespace std;
#define pi 3.14
class lalala
{
	public:
	void area(int x)
	{
		int y=pi*x*x;
		cout<<"\nArea of circle is "<<y;
	}
	void area(int a,int b)
	{
		int c=a*b;
		cout<<"\nArea of rectangle is "<<c;
	}
	void area1(float p,float q)
	{
		float s=0.5*p*q;
		cout<<"\nArea of triangle is "<<s;
	}
};

int main()
{
	lalala o;
	o.area(10);
	o.area(10,20);
	o.area1(5.1,2.7);
	return 0;
}

