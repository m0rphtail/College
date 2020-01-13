#include<iostream>

using namespace std;

class shape     //declaring the class structure
{
	protected:
	float side1, side2;
	public:
	void accept()
	{
		cout << "Enter sides: ";
		cin >> side1 >> side2;
	}
	virtual void compute_area()=0;     //creating a virtual function 
};

class triangle: public shape        //inheriting triangle class from shape class
{
	public:
	void compute_area()        //declaring the virtual function
	{
		cout << "\nThe area of the triangle is " << 0.5*side1*side2;
	}
};

class rectangle: public shape       //inheriting rectangle class from shape class
{
	public:
	void compute_area()        //declaring the virtual function
	{
		cout << "\nThe area of the rectangle is " << side1*side2;
	}
};

int main()
{
	shape *S;      //creating objects of the classes
	triangle T;
	rectangle R;
	int choice;
	
	do
	{
		cout<<"\n1. Triangle\n2. Rectangle\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				{
					S=&T;                  //pointing to the respective class 
					S->accept();           //getting the user input
					S->compute_area();     //calling the virtual function
					break;
				}
			case 2:
				{
					S=&R;
					S->accept();
					S->compute_area();
					break;
				}
			default:
				{
					cout << "\nWrong Choice";
					break;
				}
		}
	}
	while(choice<3 && choice>0);
	return 0;
}//Kshitij Chitnis
