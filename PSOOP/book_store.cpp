/*
A Book shop maintains the inventory of books that are being sold at the shop.
The list includes details such as title, author, publisher, price and available stock.
Write a program in C++ which will have a class called books with suitable member functions for
i. Add
ii. Update
iii. Search a book
iv. Purchase a book (update the stock and display the total cost)
v. Record number of successful/unsuccessful transactions (use static data members to keep count of transactions)
Use new operator in constructors to allocate memory space required.
*/

#include<iostream>
using namespace std;

class book
{
	int stock;
	float price;
	char title[100],author[10],publisher[10];
	public:
	book();
	void getData();
	void display();
};

book::book(){}

void book::getData()
{
	cout<<"Enter the title: ";
	cin.get(title,100);
	cout<<"Enter the author: ";
	cin.get(author,10);
	cout<<"Enter the publisher: ";
	cin.get(publisher,10);
	cin<<"Enter the price: ";
	cin<<price;
	cout<<"Enter the stock: ";
	cin<<stock;
}

void book::display()
{
	cout<<title;
	cout<<"\t"<<author;
	cout<<"\t"<<publisher;
	cout<<"\t"<<price;
	cout<<"\t"<<stock;
}

int main()
{
	book b;
	b.getData();
	b.display();
    return 0;
}
