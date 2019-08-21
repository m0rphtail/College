//calculate area of triangle using friend function                                                //KC
                                                //KC
#include<iostream>                                                //KC
using namespace std;                                                //KC
class example                                                //KC
{                                                //KC
	int base,height;                                                //KC
	public:                                                //KC
	void accept()                                                //KC
	{                                                //KC
		cout<<"\nEnter 2 numbers: ";                                                //KC
		cin>>base>>height;                                                //KC
	}                                                //KC
	friend float area(example a);                                                //KC
};                                                //KC
float area(example a)                                                //KC
{                                                //KC
	return float(a.base+a.height)/2;                                                //KC
}                                                //KC
                                                //KC
int main()                                                //KC
{                                                //KC
	example o;                                                //KC
	o.accept();                                                //KC
	cout<<"\nArea of triangle is "<<area(o);                                                //KC
	return 0;                                                //KC
}                                                //KC
//Kshitij Chitnis                                                //KC
