#include<iostream>
using namespace std;

class volume
{
	int x,y,z;
	public:
	volume(int a)
	{
		x=a;
	}
	volume(int a,int b)
	{
		x=a;
		y=b;
	}
	void displaycube();
	void displaycylinder();
};

void volume::displaycube()
{
	cout<<"\nVolume of cube is "<<x*x*x;
}

void volume::displaycylinder()
{
	cout<<"\nVolume of cylinder is "<<3.14*x*x*y;
}

int main()
{
	volume o1(10);
	volume o2(10,5);
	o1.displaycube();
	o2.displaycylinder();
	return 0;
}
