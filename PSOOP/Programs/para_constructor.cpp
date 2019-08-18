//Parameterized constuctor

#include<iostream>
using namespace std;
class volume
{
	int s;
	public:
	volume(int a)	//Parameterized constuctor
	{
		s=a;
	}
	void display()
	{
		cout<<"Volume is "<<s*s*s;
	}
};

int main()
{
	volume a(10);	//calls constructor and passes argument
	a.display();
	return 0;
}
