//Program to accept and display details of book
#include<iostream>
using namespace std;
class book
{
	char name[50];
	int pages;
	float price;
	public:
	void accept()
	{
		cout<<"\nEnter name of the book: ";
		cin>>name;
		cout<<"\nEnter pages in the book: ";
		cin>>pages;
		cout<<"\nEnter price of the book: ";
		cin>>price;
	}
	void display()
	{
		cout<<"\n\nName: "<<name<<"\nPages: "<<pages<<"\nPrice: "<<price;
	}
};

int main()
{
	book b1,b2;
	b1.accept();
	b2.accept();
	b1.display();
	b2.display();
	return 0;
}

//Kshitij Chitnis
