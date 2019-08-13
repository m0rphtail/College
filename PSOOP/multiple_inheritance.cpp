
//................DOES NOT WORK :( ...................

#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class info
{
	int dob;
	char name[50],bloodgroup[5];
	public:
	void getData();
	void display();
};
void info :: getData()
{
	cin.ignore();
	cout<<"\nEnter name: ";
	cin.getline(name,50);
	cout<<"\nEnter date of birth: ";
	cin>>dob;
	cout<<"\nEnter branch: ";
	cin.getline(bloodgroup,5);
}
void info :: display()
{
	cout<<"\n\nName: "<<name<<"\nDate of birth: "<<dob<<"\nBlood Group: "<<bloodgroup;
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
