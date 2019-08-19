/*Write a program to create a class of obj as objA and objB the contents of objA is assigned to
objB using operator overloading technique*/

#include<iostream>
using namespace std;
class assign
{
private:
	int x, y;
public:
	void getdata(int a, int b);
	void display();
	void operator = (assign v);
};
void assign::getdata(int a, int b)
{
	x = a;
	y = b;

}
void assign::operator=(assign v)
{
	x = v.x;
	y = v.y;

}
void assign::display()
{
	cout << "\nValue of x: " << x;
	cout << "\nValue of y: " << y;

}
int main()
{

	assign p1, p2;
	p1.getdata(20, 30);
	p1.display();
	p1 = p2;
	p2.display();
	return 0;
}
//Kshitij Chitnis