//using scope resolution operator                                                                 //KC
                                                                 //KC
#include<iostream>                                                                 //KC
using namespace std;                                                                 //KC
class example                                                                 //KC
{                                                                //KC
	int number;                                                                 //KC
	public:                                                                 //KC
	void accept();                                                                 //KC
	void evenodd();                                                                 //KC
};                                                                 //KC
                                                                 //KC
void example::accept()                                                                //KC
{                                                                //KC
	cout<<"Enter number: ";                                                              //KC
	cin>>number;                                                //KC
}                                                                 //KC
void example::evenodd()                                                               //KC
{                                                                //KC
	if(number%2==0)                                                               //KC
		cout<<number<<" is even.";                                                               //KC
	else                 \\Kshitij Chitnis                                                //KC
		cout<<number<<" is odd.";                                                              //KC
}                                                                 //KC
                                                                 //KC
int main()                                                                 //KC
{                                                                 //KC
	example x;                                                                //KC
	x.accept();                                                                //KC
	x.evenodd();                                                                 //KC
	return 0;                                                                 //KC
}                                                                 //KC
//Kshitij Chitnis                                                                //KC
