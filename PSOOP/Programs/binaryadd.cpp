#include<iostream>                                                //KC
using namespace std;                                                //KC
class add                                                //KC
{	                                                //KC
	public:                                                //KC
	int x;                                                //KC
	public:                                                //KC
		add()                                                //KC
		{                                                //KC
			x=0;                                                //KC
		}                                                //KC
		add(int y)                                                //KC
		{                                                //KC
			x=y;                                                //KC
		}                                                //KC
		void display();                                                //KC
		add operator+(add a);                                                //KC
};                                                //KC
void display()                                                //KC
{                                                //KC
	cout<<x<<endl;                                                //KC
}                                                //KC
add add::operator+(add a)                                                //KC
{                                                //KC
	add sum;                                                //KC
	sum.x=x+a.x;                                                //KC
	return sum;                                                //KC
}                                                //KC
int main()                                                //KC
{	                                                //KC
	cout<<"Kshitij Chitnis\n";                                                //KC
	add a1(10),a2(20),s;                                                //KC
	s=a1+a2;                                                //KC
	a1.display();                                                //KC
	a2.display();                                                //KC
	s.display();                                                //KC
	return 0;                                                //KC
}                                                //KC
//Kshitij Chitnis                                                //KC