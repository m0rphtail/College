#include<iostream>                                                //KC
using namespace std;                                                //KC
class store                                                //KC
{                                                //KC
private:                                                //KC
	int code;                                                //KC
	float price;                                                //KC
public:                                                //KC
	void accept();                                                //KC
	void display();                                                //KC
                                                //KC
};                                                //KC
void store::accept()                                                //KC
{                                                //KC
	cout << "\nEnter code & price: ";                                                //KC
	cin >> code >> price;                                                //KC
                                                //KC
}                                                //KC
void store::display()                                                //KC
{                                                //KC
	cout << "\nCode & Price is: " << code << price;                                                //KC
}                                                //KC
int main()                                                //KC
{                                                //KC
	int i;                                                //KC
	store* s = new store[3];                                                //KC
	for (i = 0; i < 3; i++)                                                //KC
	{                                                //KC
		s->accept();                                                //KC
		s->display();                                                //KC
		s++;                                                //KC
	}                                                //KC
	return 0;                                                //KC
}//Kshitij Chitnis                                                //KC