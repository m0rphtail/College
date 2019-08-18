//Copy Constuctor

#include<iostream>
using namespace std;
class volume
{
	int s;
	public:
	volume(int & x)	//copy constuctor
	{
		s=x.s;	//copies value
	}
	void display()
	{
		cout<<"Volume is "<<s*s*s;
	}
};

int main()
{
	volume a1;	//calls default constructor
	volume a2(a1);	//calls copy constructor
	a2.display();
	return 0;
}
	
