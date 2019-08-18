#include<iostream>
using namespace std;

class example
{
	int x;
	static int y;
	public:
	void getdata()
	{
		cout<<"\nEnter value of x: ";
		cin>>x;
	}
	void putdata()
	{
		cout<<"\nx is "<<x;
	}
	static void display()
	{
		y=y++;
		cout<<"\ny is "<<y;
	}
};

int example::y;

int main()
{
	example a;
	a.getdata();
	a.putdata();
	example::display();
	return 0;
}
