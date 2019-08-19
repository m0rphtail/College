//calculate area of triangle using friend function

#include<iostream>
using namespace std;
class example
{
	int base,height;
	public:
	void accept()
	{
		cout<<"\nEnter 2 numbers: ";
		cin>>base>>height;
	}
	friend float area(example a);
};
float area(example a)
{
	return float(a.base+a.height)/2;
}

int main()
{
	example o;
	o.accept();
	cout<<"\nArea of triangle is "<<area(o);
	return 0;
}
//Kshitij Chitnis
