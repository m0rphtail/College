
//................DOES NOT WORK :( ...................

#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class student
{
	int roll_no;
	char name[50],branch[50];
	public:
	void getData();
	void display();
};
void student :: getData()
{
	cin.ignore();
	cout<<"\nEnter the roll no: ";
	cin>>roll_no;
	cout<<"\nEnter name: ";
	cin.getline(name,50);
	cout<<"\nEnter branch: ";
	cin.getline(branch,50);
}
void student :: display()
{
	cout<<"\n\nRoll no: "<<roll_no<<"\nName: "<<name<<"\nBranch: "<<branch;
}

class sports
{
	int marks=0;
	char w;
	public:
	void getData();
	void display();
};

void sports :: getData()
{
	cout<<"Participated in sports? (y/n): ";
	cin>>w;
}
void sports :: display()
{
	if(w=='y')
	{
		marks=5;
	}
	else{
		marks=0;
	}
	cout<<"sports marks are: "<<marks;
}

class marks : public student, public sports
{
	int sub_marks,total_marks;
	public:
	void getData();
	void display();
};
void marks :: getData()
{
student:getData();
sports:getData();
	cout<<"Enter marks: ";
	cin>>sub_marks;
}
void marks :: display()
{
student:display();
sports:display();
	total_marks = sub_marks;
	cout<<"Total marks: "<<total_marks;
}

int main()
{
	marks m;
	m.getData();
	m.display();
	return 0;
}
