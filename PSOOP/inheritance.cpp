#include<iostream>
using namespace std;

class student
{
	int roll_no;
	char name[50],branch[50];
	public:
	void getData();
	void display();
};

class marks : public student
{
	int marks;
	char grade[5];
	public:
	void getData1();
	void display1();
};


void student :: getData()
{
	cout<<"\nEnter roll no: ";
	cin>>roll_no;
	cout<<"\nEnter name: ";
	cin.get(name,50);
	cout<<"\nEnter branch: ";
	cin.get(branch,50);
}

void student :: display()
{
	cout<<"\n\nRoll no: "<<roll_no;
	cout<<"\nName: "<<name;
	cout<<"\nBranch: "<<branch;
}

void marks :: getData1()
{
	student :: getData();
	cout<<"\nEnter marks: ";
	cin>>marks;
	cout<<"\nEnter the grade: ";
	cin.get(grade,5);
}

void marks :: display1()
{
	student :: display();
	cout<<"\nMarks: "<<marks;
	cout<<"\nGrade: "<<grade;
}

int main()
{
	marks m;
	m.getData1();
	m.display1();
	return 0;
}
