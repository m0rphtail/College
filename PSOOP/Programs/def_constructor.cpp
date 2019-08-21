//Default/non parameterized constructor                                                //KC
                                                //KC
#include<iostream>                                                //KC
using namespace std;                                                //KC
class volume                                                //KC
{                                                //KC
	int s;                                                //KC
	public:                                                //KC
	volume()	//default constructor                                                //KC
	{                                                //KC
		s=10;                                                //KC
	}                                                //KC
	void display()                                                //KC
	{                                                //KC
		cout<<"Volume is "<<s*s*s;                                                //KC
	}                                                //KC
};                                                //KC
                                                //KC
int main()                                                //KC
{                                                //KC
	volume a;                                                //KC
	a.display();                                                //KC
	return 0;                                                //KC
}//Kshitij Chitnis                                                //KC
