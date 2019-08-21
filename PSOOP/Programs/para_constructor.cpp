//Parameterized constuctor                                                //KC
                                                //KC
#include<iostream>                                                //KC
using namespace std;                                                //KC
class volume                                                //KC
{                                                //KC
	int s;                                                //KC
	public:                                                //KC
	volume(int a)	//Parameterized constuctor                                                //KC
	{                                                //KC
		s=a;                                                //KC
	}                                                //KC
	void display()                                                //KC
	{                                                //KC
		cout<<"Volume is "<<s*s*s;                                                //KC
	}                                                //KC
};                                                //KC
                                                //KC
int main()                                                //KC
{                                                //KC
	volume a(10);	//calls constructor and passes argument                                                //KC
	a.display();                                                //KC
	return 0;                                                //KC
}//Kshitij Chitnis                                                //KC
