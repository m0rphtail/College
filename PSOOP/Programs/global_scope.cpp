#include<iostream>
using namespace std;
int x=10;
int main()
{
	cout<<"\nStart of main.";
	int x=5;
	cout<<"\nHello";
	{
		cout<<"\n\nStart of inner block.";
		int x=20;
		cout<<"\n"<<x;		//prints 20
		cout<<"\n"<<::x;	//prints 10
		cout<<"\nEnd of inner block.\n";
	}
	cout<<"\n"<<x;		//prints 5
	cout<<"\n"<<::x;	//prints 10
	cout<<"\nEnd of main.";
	return 0;
}

