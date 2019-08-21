#include<iostream>                                                //KC
#include<string.h>                                                //KC
                                                //KC
using namespace std;                                                //KC
                                                //KC
class student                                                //KC
{                                                //KC
	int roll_no;                                                //KC
	char name[50],branch[50];                                                //KC
	public:                                                //KC
	void getData();                                                //KC
	void display();                                                //KC
};                                                //KC
                                                //KC
class marks : public student                                                //KC
{                                                //KC
	int marks;                                                //KC
	char grade[5];                                                //KC
	public:                                                //KC
	void getData1();                                                //KC
	void display1();                                                //KC
};                                                //KC
                                                //KC
                                                //KC
void student :: getData()                                                //KC
{                                                //KC
//	cin.ignore();                                                //KC
	cout<<"\nEnter roll no: ";                                                //KC
	cin>>roll_no;                                                //KC
	cout<<"\nEnter name: ";                                                //KC
	cin.getline(name,50);                                                //KC
	cout<<"\nEnter branch: ";                                                //KC
	cin>>branch;                                                //KC
}                                                //KC
                                                //KC
void student :: display()                                                //KC
{                                                //KC
	cout<<"\n\nRoll no: "<<roll_no;                                                //KC
	cout<<"\nName: "<<name;                                                //KC
	cout<<"\nBranch: "<<branch;                                                //KC
}                                                //KC
                                                //KC
void marks :: getData1()                                                //KC
{                                                //KC
	student :: getData();                                                //KC
	cout<<"\nEnter marks: ";                                                //KC
	cin>>marks;                                                //KC
	cout<<"\nEnter the grade: ";                                                //KC
	cin>>grade;                                                //KC
}                                                //KC
                                                //KC
void marks :: display1()                                                //KC
{                                                //KC
	student :: display();                                                //KC
	cout<<"\nMarks: "<<marks;                                                //KC
	cout<<"\nGrade: "<<grade;                                                //KC
}                                                //KC
                                                //KC
int main()                                                //KC
{                                                //KC
	marks m;                                                //KC
	m.getData1();                                                //KC
	m.display1();                                                //KC
	return 0;                                                //KC
}//Kshitij Chitnis                                                //KC
