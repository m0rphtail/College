//Program to accept and display details of book                                                //KC
                                                //KC
#include<iostream>                                                //KC
using namespace std;                                                //KC
class book                                                //KC
{                                                //KC
	char name[50];                                                //KC
	int pages;                                                //KC
	float price;                                                //KC
	public:                                                //KC
	void accept()                                                //KC
	{                                                //KC
		cout<<"\nEnter name of the book: ";                                                //KC
		cin>>name;                                                //KC
		cout<<"\nEnter pages in the book: ";                                                //KC
		cin>>pages;                                                //KC
		cout<<"\nEnter price of the book: ";                                                //KC
		cin>>price;                                                //KC
	}                                                //KC
	void display()                                                //KC
	{                                                //KC
		cout<<"\n\nName: "<<name<<"\nPages: "<<pages<<"\nPrice: "<<price;                                                //KC
	}                                                //KC
};                                                //KC
                                                //KC
int main()                                                //KC
{                                                //KC
	book b1,b2;                                                //KC
	b1.accept();                                                //KC
	b2.accept();                                                //KC
	b1.display();                                                //KC
	b2.display();                                                //KC
	return 0;                                                //KC
}                                                //KC
                                                //KC
//Kshitij Chitnis                                                //KC
