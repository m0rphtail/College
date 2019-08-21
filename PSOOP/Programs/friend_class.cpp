/* Write a program to show how the class first has generated its friendship to the class second to access private data                                                 //KC
of class first through public member function of class second*/                                                //KC
                                                //KC
                                                //KC
#include<iostream>                                                //KC
using namespace std;                                                //KC
class first                                                //KC
{                                                //KC
	friend class second;                                                //KC
private:                                                //KC
	int x;                                                //KC
public:                                                //KC
	void accept()                                                //KC
	{                                                //KC
		cout << "\nEnter value of x: ";                                                //KC
		cin >> x;                                                //KC
	}                                                //KC
                                                //KC
};                                                //KC
class second                                                //KC
{                                                //KC
                                                //KC
public:                                                //KC
	void display(first F);                                                //KC
                                                //KC
};                                                //KC
void second::display(first F)                                                //KC
{                                                //KC
	cout << "\nValue of x is: " << F.x;                                                //KC
                                                //KC
}                                                //KC
                                                //KC
int main()                                                //KC
{                                                //KC
	first f1;                                                //KC
	second s1;                                                //KC
	f1.accept();                                                //KC
	s1.display(f1);                                                //KC
	return 0;                                                //KC
}                                                //KC
//Kshitij Chitnis                                                //KC