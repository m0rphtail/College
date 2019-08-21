#include<iostream>                                                //KC
using namespace std;                                                //KC
                                                //KC
class example                                                //KC
{                                                //KC
	int x;                                                //KC
	static int y;                                                //KC
	public:                                                //KC
	void getdata()                                                //KC
	{                                                //KC
		cout<<"\nEnter value of x: ";                                                //KC
		cin>>x;                                                //KC
	}                                                //KC
	void putdata()                                                //KC
	{                                                //KC
		cout<<"\nx is "<<x;                                                //KC
	}                                                //KC
	static void display()                                                //KC
	{                                                //KC
		y=y++;                                                //KC
		cout<<"\ny is "<<y;                                                //KC
	}                                                //KC
};                                                //KC
                                                //KC
int example::y;                                                //KC
                                                //KC
int main()                                                //KC
{                                                //KC
	example a;                                                //KC
	a.getdata();                                                //KC
	a.putdata();                                                //KC
	example::display();                                                //KC
	return 0;                                                //KC
}//Kshitij Chitnis                                                //KC
