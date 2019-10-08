#include<iostream>
using namespace std;

class A
{	

	double x,y;
	public:
	void accept()
	{
		cout << "\nEnter two numbers: ";
		cin >> x >> y;
	}
	double divide()
	{
		try       //the try block checks for a condition
		{
			if(y==0)
				throw(y);       //if the condition if flase, throw block is executed
			cout << "\nDivision of the entered numbers is " << x/y << endl;
		}
		catch(double p)         //if the condition is true, catch block is executed
		{
			cout << "\nDivide by zero exception" << endl;
		}
	}
};

int main()
{
	A obj;
	obj.accept();
	obj.divide();
	return 0;
}
