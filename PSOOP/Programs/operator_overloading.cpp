/*Write a program to create a class of obj as objA and objB the contents of objA is assigned to                                                //KC
objB using operator overloading technique*/                                                //KC
                                                //KC
#include<iostream>                                                //KC
using namespace std;                                                //KC
class assign                                                //KC
{                                                //KC
private:                                                //KC
	int x, y;                                                //KC
public:                                                //KC
	void getdata(int a, int b);                                                //KC
	void display();                                                //KC
	void operator = (assign v);                                                //KC
};                                                //KC
void assign::getdata(int a, int b)                                                //KC
{                                                //KC
	x = a;                                                //KC
	y = b;                                                //KC
                                                //KC
}                                                //KC
void assign::operator=(assign v)                                                //KC
{                                                //KC
	x = v.x;                                                //KC
	y = v.y;                                                //KC
                                                //KC
}                                                //KC
void assign::display()                                                //KC
{                                                //KC
	cout << "\nValue of x: " << x;                                                //KC
	cout << "\nValue of y: " << y;                                                //KC
                                                //KC
}                                                //KC
int main()                                                //KC
{                                                //KC
                                                //KC
	assign p1, p2;                                                //KC
	p1.getdata(20, 30);                                                //KC
	p1.display();                                                //KC
	p1 = p2;                                                //KC
	p2.display();                                                //KC
	return 0;                                                //KC
}                                                //KC
//Kshitij Chitnis                                                //KC