#include<iostream>
using namespace std;
class unary
{
private:
	int x, y;
public:
	void getdata(int a, int b);
	void display();
	void operator ++ ();
};
void unary::getdata(int a, int b)
{
	x = a;
	y = b;

}
void unary::operator++()
{
	x = ++x;
	y = ++y;
}
void unary::display()
{
	cout << "\nValue of x is: " << x;
	cout << "\nValue of y is: " << y;

}
int main()
{
	unary i;
	i.getdata(10, 20);
	i.display();
	++i;
	i.display();
	return 0;
}//Kshitij Chitnis