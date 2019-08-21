#include<iostream>                                                //KC
using namespace std;                                                //KC
                                                //KC
class volume                                                //KC
{                                                //KC
	int x,y,z;                                                //KC
	public:                                                //KC
	volume(int a)                                                //KC
	{                                                //KC
		x=a;                                                //KC
	}                                                //KC
	volume(int a,int b)                                                //KC
	{                                                //KC
		x=a;                                                //KC
		y=b;                                                //KC
	}                                                //KC
	void displaycube();                                                //KC
	void displaycylinder();                                                //KC
};                                                //KC
                                                //KC
void volume::displaycube()                                                //KC
{                                                //KC
	cout<<"\nVolume of cube is "<<x*x*x;                                                //KC
}                                                //KC
                                                //KC
void volume::displaycylinder()                                                //KC
{                                                //KC
	cout<<"\nVolume of cylinder is "<<3.14*x*x*y;                                                //KC
}                                                //KC
                                                //KC
int main()                                                //KC
{                                                //KC
	volume o1(10);                                                //KC
	volume o2(10,5);                                                //KC
	o1.displaycube();                                                //KC
	o2.displaycylinder();                                                //KC
	return 0;                                                //KC
}//Kshitij Chitnis                                                //KC
