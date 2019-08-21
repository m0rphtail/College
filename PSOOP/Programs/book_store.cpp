/*                                                //KC
A Book shop maintains the inventory of books that are being sold at the shop.                                                //KC
The list includes details such as title, author, publisher, price and available stock.                                                //KC
Write a program in C++ which will have a class called books with suitable member functions for                                                //KC
i. Add                                                //KC
ii. Update                                                //KC
iii. Search a book                                                //KC
iv. Purchase a book (update the stock and display the total cost)                                                //KC
v. Record number of successful/unsuccessful transactions (use static data members to keep count of transactions)                                                //KC
Use new operator in constructors to allocate memory space required.                                                //KC
*/                                                //KC
                                                //KC
                                                //KC
#include<iostream>                                                //KC
#include<string.h>                                                //KC
#include<stdlib.h>                                                //KC
                                                //KC
using namespace std;                                                //KC
                                                //KC
class book					//defining class                                                 //KC
{                                                //KC
	char *author,*title,*publisher; 	//setting data members as pointers                                                //KC
	float *price;                                                //KC
	int * stock;                                                //KC
	public:                                                //KC
	book()                                                //KC
	{                                                //KC
		author = new char[50];                                                //KC
		title = new char[50];                                                //KC
		publisher = new char[50];                                                //KC
		price = new float;                                                //KC
		stock = new int;                                                //KC
	}                                                //KC
	void feedData();                                                //KC
	void editData();                                                //KC
	void showData();                                                //KC
	int search(char[],char[]);                                                //KC
	void buyBook();                                                //KC
};                                                //KC
                                                //KC
void book :: feedData()				//function to get all the data                                                //KC
{                                                //KC
	cin.ignore();				//used cin.ignore(), as I have used getline funtion, so it is convinent for the user to input a string with spaces, and does not crash the program                                                //KC
	cout<<"\nEnter title: ";                                                //KC
	cin.getline(title,50);                                                //KC
	cout<<"\nEnter author: ";                                                //KC
	cin.getline(author,50);                                                //KC
	cout<<"\nEnter publisher: ";                                                //KC
	cin.getline(publisher,50);                                                //KC
	cout<<"\nEnter the price: ";                                                //KC
	cin>>*price;                                                //KC
	cout<<"\nEnter the stock: ";                                                //KC
	cin>>*stock;                                                //KC
	cout<<"\n\n";                                                //KC
}                                                //KC
                                                //KC
void book :: editData()				//function to edit the data                                                //KC
{                                                //KC
	feedData();				//it is basically the feedData function called inside it                                                //KC
}                                                //KC
                                                //KC
void book :: showData()				//function to display all the data of the book                                                //KC
{                                                //KC
	cout<<"\nTitle: "<<title;                                                //KC
	cout<<"\nAuthor: "<<author;                                                //KC
	cout<<"\nPublisher: "<<publisher;                                                //KC
	cout<<"\nPrice: Rs "<<*price;                                                //KC
	cout<<"\nStock: "<<*stock;                                                //KC
}                                                //KC
                                                //KC
int book :: search(char tbuy[50],char abuy[50]) 		//function to search if a book and the author exists in stock or not                                                 //KC
{                                                //KC
	if(strcmp(tbuy,title)==0 && strcmp(abuy,author)==0) 	//this funtion compares the title and the author string with help of strcmp funtion                                                //KC
		return 1;					//and if a book is found returns value 1, or else 0                                                //KC
	else return 0;                                                //KC
}                                                //KC
                                                //KC
void book :: buyBook()				//function to buy book                                                //KC
{                                                //KC
	int count;                                                //KC
	cout<<"\nEnter the number of books to buy: ";                                                //KC
	cin>>count;				//this function first checks if the stock of the books are sufficient                                                //KC
	if(count<=*stock)			//if yes, then finds out the total cost of the books to be bought                                                //KC
	{                                                //KC
		*stock=*stock-count;                                                //KC
		cout<<"\nBooks bought successfully.";                                                //KC
		cout<<"\nAmount: Rs "<<(*price)*count;                                                //KC
	}                                                //KC
	else                                                //KC
		cout<<"\nRequired copies are not in stock.";                                                //KC
}                                                //KC
                                                //KC
int main()                                                //KC
{                                                //KC
	book *B[100];				//objects initialized as array                                                //KC
	int i=0,t,choice;                                                //KC
	char titleBuy[50],authorBuy[50];                                                //KC
	while(1)                                                //KC
	{                                                //KC
		cout<<"\n\n\t----KSHITIJ's BOOK SHOP---------------------";                                                //KC
		cout<<"\n1. Entry of new book.\n2. Buy book.\n3. Search for book.\n4. Edit details of book.\n5. Exit\nEnter your choice: "; 	//menu                                                //KC
		cin>>choice;                                                //KC
		                                                //KC
		switch(choice)                                                //KC
		{                                                //KC
			case 1: B[i] = new book;                                                //KC
				B[i]->feedData();		//dot and arrow are used to refrence indivitial members in class                                                //KC
				i++;                                                //KC
				break;                                                //KC
                                                //KC
			case 2: cin.ignore();                                                //KC
				cout<<"\nEnter title: ";                                                //KC
				cin.getline(titleBuy,50);                                                //KC
				cout<<"\nEnter author: ";                                                //KC
				cin.getline(authorBuy,50);                                                //KC
                                                //KC
				for(t=0;t<i;t++)                                                //KC
				{                                                //KC
					if(B[t]->search(titleBuy,authorBuy))	//first checks if the book exists, then buys it                                                //KC
					{                                                //KC
						B[t]->buyBook();                                                //KC
						break;                                                //KC
					}                                                //KC
				}                                                //KC
				if(t==1)                                                //KC
					cout<<"\nThis book is not in stock.";                                                //KC
				break;                                                //KC
                                                //KC
			case 3: cin.ignore();                                                //KC
				cout<<"\nEnter title: ";                                                //KC
				cin.getline(titleBuy,50);                                                //KC
				cout<<"\nEnter author: ";                                                //KC
				cin.getline(authorBuy,50);                                                //KC
				                                                //KC
				for(t=0;t<i;t++)                                                //KC
				{                                                //KC
					if(B[t]->search(titleBuy,authorBuy))                                                //KC
					{                                                //KC
						cout<<"\nBook found!";                                                //KC
						B[t]->showData();                                                //KC
						break;                                                //KC
					}                                                //KC
				}                                                //KC
				if(t==i)                                                //KC
					cout<<"\nbook not in stock.";                                                //KC
				break;                                                //KC
                                                //KC
			case 4: cin.ignore();                                                //KC
			        cout<<"\nEnter title: ";                                                //KC
				cin.getline(titleBuy,50);                                                //KC
				cout<<"\nEnter author: ";                                                //KC
				cin.getline(authorBuy,50);	                                                //KC
                                                //KC
				for(t=0;t<i;t++)                                                //KC
				{                                                //KC
					if(B[t]->search(titleBuy,authorBuy))	//first checks if the book exists, then edits it                                                //KC
					{                                                //KC
						cout<<"\nBook found";                                                //KC
						B[t]->editData();                                                //KC
						break;                                                //KC
					}                                                //KC
				}                                                //KC
				if(t==1)                                                //KC
					cout<<"\nBook not in stock.";                                                //KC
				break;                                                //KC
                                                //KC
			case 5: exit(0);                                                //KC
			default: cout<<"\nInvalid choice.";                                                //KC
		}                                                //KC
	}                                                //KC
	return 0;                                                //KC
}                                                //KC
		//Kshitij Chitnis				                                                //KC
                                                //KC
		                                                //KC
                                                //KC
                                                //KC
	                                                //KC
