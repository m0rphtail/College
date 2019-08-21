#include<iostream>                                                //KC
using namespace std;                                                //KC
int x=10;                                                //KC
int main()                                                //KC
{                                                //KC
	cout<<"\nStart of main.";                                                //KC
	int x=5;                                                //KC
	cout<<"\nHello";                                                //KC
	{                                                //KC
		cout<<"\n\nStart of inner block.";                                                //KC
		int x=20;                                                //KC
		cout<<"\n"<<x;		//prints 20                                                //KC
		cout<<"\n"<<::x;	//prints 10                                                //KC
		cout<<"\nEnd of inner block.\n";                                                //KC
	}                                                //KC
	cout<<"\n"<<x;		//prints 5                                                //KC
	cout<<"\n"<<::x;	//prints 10                                                //KC
	cout<<"\nEnd of main.";                                                //KC
	return 0;                                                //KC
}                                                //KC
//Kshitij Chitnis                                                //KC
