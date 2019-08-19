//using scope resolution operator

#include<iostream>
using namespace std;
class example
{
	int number;
	public:
	void accept();
	void evenodd();
};

void example::accept()
{
	cout<<"Enter number: ";
	cin>>number;
}

void example::evenodd()
{
	if(number%2==0)
		cout<<number<<" is even.";
	else
		cout<<number<<" is odd.";
}

int main()
{
	example x;
	x.accept();
	x.evenodd();
	return 0;
}
//Kshitij Chitnis
