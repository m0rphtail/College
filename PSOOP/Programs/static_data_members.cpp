#include<iostream>
using namespace std;

class example
{
	public:
	static int x;
	void accepts()
	{
		x++;
	}
};

int example::x;

int main()
{
	example a1,a2,a3;
	cout<<a1.x;
	cout<<a2.x;
	cout<<a3.x;
	a1.accepts();
	cout<<a1.x;
	a2.accepts();
	cout<<a2.x;
	a3.accepts();
	cout<<a3.x;
	return 0;
}
