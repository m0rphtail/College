//program to calculate are of cirecle,rectangle and triangle using function overloading                                                //KC
                                                //KC
#include<iostream>                                                //KC
using namespace std;                                                //KC
#define pi 3.14                                                //KC
class lalala                                                //KC
{                                                //KC
	public:                                                //KC
	void area(int x)                                                //KC
	{                                                //KC
		int y=pi*x*x;                                                //KC
		cout<<"\nArea of circle is "<<y;                                                //KC
	}                                                //KC
	void area(int a,int b)                                                //KC
	{                                                //KC
		int c=a*b;                                                //KC
		cout<<"\nArea of rectangle is "<<c;                                                //KC
	}                                                //KC
	void area1(float p,float q)                                                //KC
	{                                                //KC
		float s=0.5*p*q;                                                //KC
		cout<<"\nArea of triangle is "<<s;                                                //KC
	}                                                //KC
};                                                //KC
                                                //KC
int main()                                                //KC
{                                                //KC
	lalala o;                                                //KC
	o.area(10);                                                //KC
	o.area(10,20);                                                //KC
	o.area1(5.1,2.7);                                                //KC
	return 0;                                                //KC
}                                                //KC
//Kshitij Chitnis                                                //KC
