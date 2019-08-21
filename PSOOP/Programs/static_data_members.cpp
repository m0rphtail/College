#include<iostream>                                                //KC
using namespace std;                                                //KC
                                                //KC
class example                                                //KC
{                                                //KC
	public:                                                //KC
	static int x;                                                //KC
	void accepts()                                                //KC
	{                                                //KC
		x++;                                                //KC
	}                                                //KC
};                                                //KC
                                                //KC
int example::x;                                                //KC
                                                //KC
int main()                                                //KC
{                                                //KC
	example a1,a2,a3;                                                //KC
	cout<<a1.x;                                                //KC
	cout<<a2.x;                                                //KC
	cout<<a3.x;                                                //KC
	a1.accepts();                                                //KC
	cout<<a1.x;                                                //KC
	a2.accepts();                                                //KC
	cout<<a2.x;                                                //KC
	a3.accepts();                                                //KC
	cout<<a3.x;                                                //KC
	return 0;                                                //KC
}//Kshitij Chitnis                                                //KC
