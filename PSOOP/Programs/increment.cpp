#include<iostream>                                                //KC
using namespace std;                                                //KC
class unary                                                //KC
{                                                //KC
private:                                                //KC
	int x, y;                                                //KC
public:                                                //KC
	void getdata(int a, int b);                                                //KC
	void display();                                                //KC
	void operator ++ ();                                                //KC
};                                                //KC
void unary::getdata(int a, int b)                                                //KC
{                                                //KC
	x = a;                                                //KC
	y = b;                                                //KC
                                                //KC
}                                                //KC
void unary::operator++()                                                //KC
{                                                //KC
	x = ++x;                                                //KC
	y = ++y;                                                //KC
}                                                //KC
void unary::display()                                                //KC
{                                                //KC
	cout << "\nValue of x is: " << x;                                                //KC
	cout << "\nValue of y is: " << y;                                                //KC
                                                //KC
}                                                //KC
int main()                                                //KC
{                                                //KC
	unary i;                                                //KC
	i.getdata(10, 20);                                                //KC
	i.display();                                                //KC
	++i;                                                //KC
	i.display();                                                //KC
	return 0;                                                //KC
}//Kshitij Chitnis                                                //KC