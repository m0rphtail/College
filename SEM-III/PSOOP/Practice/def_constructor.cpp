//Default/non parameterized constructor

#include<iostream>
using namespace std;
class volume
{
	int s;
	public:
	volume()	//default constructor
	{
		s=10;
	}
	void display()
	{
		cout<<"Volume is "<<s*s*s;
	}
};

int main()
{
	volume a;
	a.display();
	return 0;
}//Kshitij Chitnis
