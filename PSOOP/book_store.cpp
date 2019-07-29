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


//---------------------------------------------------------------------

//                    WORK IN PROGRESS !!!

//---------------------------------------------------------------------


#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

class book
{
	char *author,*title,*publisher;
	float *price;
	int * stock;
	public:
	book()
	{
		author = new char[50];
		title = new char[50];
		publisher = new char[50];
		price = new float;
		stock = new int;
	}
	void feedData();
	void editData();
	void showData();
	int search(char[],char[]);
	void buyBook();
};

void book :: feedData()
{
	cin.ignore();
	cout<<"\nEnter title: ";
	cin.getline(title,50);
	cout<<"\nEnter author: ";
	cin.getline(author,50);
	cout<<"\nEnter publisher: ";
	cin.getline(publisher,50);
	cout<<"\nEnter the price: ";
	cin>>*price;
	cout<<"\nEnter the stock: ";
	cin>>*stock;
	cout<<"\n\n";
}

void book :: editData()
{
	feedData();	
}

void book :: showData()
{
	cout<<"\nTitle: "<<title;
	cout<<"\nAuthor: "<<author;
	cout<<"\nPublisher: "<<publisher;
	cout<<"\nPrice: Rs "<<*price;
	cout<<"\nStock: "<<*stock;
}

int book :: search(char tbuy[50],char abuy[50])
{
	if(strcmp(tbuy,title)==0 && strcmp(abuy,author)==0)
		return 1;
	else return 0;
}

void book :: buyBook()
{
	int count;
	cout<<"\nEnter the number of books to buy: ";
	cin>>count;
	if(count<=*stock)
	{
		*stock+*stock-count;
		cout<<"\nBooks bought successfully.";
		cout<<"\nAmount: Rs "<<(*price)*count;
	}
	else
		cout<<"\nRequired copies are not in stock.";
}

int main()
{
	book *B[100];
	int i=0,r,t,choice;
	char titleBuy[50],authorBuy[50];
	while(1)
	{
		cout<<"\n\n\tMENU";
		cout<<"\n1. Entry of new book.\n2. Buy book.\n3. Search for book.\n4. Edit details of book.\n5. Exit\nEnter your choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1: B[i] = new book;
				B[i]->feedData();
				i++;
				break;

			case 2: cin.ignore();
				cout<<"\nEnter title: ";
				cin.getline(titleBuy,50);
				cout<<"\nEnter author: ";
				cin.getline(authorBuy,50);

				for(t=0;t<i;t++)
				{
					if(B[t]->search(titleBuy,authorBuy))
					{
						B[t]->buyBook();
						break;
					}
				}
				if(t==1)
					cout<<"\nThis book is not in stock.";
				break;

			case 3: cin.ignore();
				cout<<"\nEnter title: ";
				cin.getline(titleBuy,50);
				cout<<"\nEnter author: ";
				cin.getline(authorBuy,50);
				
				for(t=0;t<i;t++)
				{
					if(B[t]->search(titleBuy,authorBuy))
					{
						cout<<"\nBook found!";
						B[t]->showData();
						break;
					}
				}
				if(t==i)
					cout<<"\nbook not in stock.";
				break;

			case 4: cin.ignore();
			        cout<<"\nEnter title: ";
				cin.getline(titleBuy,50);
				cout<<"\nEnter author: ";
				cin.getline(authorBuy,50);	

				for(t=0;t<i;t++)
				{
					if(B[t]->search(titleBuy,authorBuy))
					{
						cout<<"\nBook found";
						B[t]->editData();
						break;
					}
				}
				if(t==1)
					cout<<"\nBook not in stock.";
				break;

			case 5: exit(0);
			default: cout<<"\nInvalid choice.";
		}
	}
	return 0;
}
						

		


	
