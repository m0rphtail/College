#include<iostream>
using namespace std;
class add
{	
	public:
	int x;
	public:
		add()
		{
			x=0;
		}
		add(int y)
		{
			x=y;
		}
		void display();
		add operator+(add a);
};
void display()
{
	cout<<x<<endl;
}
add add::operator+(add a)
{
	add sum;
	sum.x=x+a.x;
	return sum;
}
int main()
{	
	add a1(10),a2(20),s;
	s=a1+a2;
	a1.display();
	a2.display();
	s.display();
	return 0;
}
