
//................DOES NOT WORK :( ...................

#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class info
{
	char dob[10];
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
	cin.getline(dob,10);
	cout<<"\nEnter branch: ";
	cin.getline(bloodgroup,5);
}
void info :: display()
{
	cout<<"\n\nName: "<<name<<"\nDate of birth: "<<dob<<"\nBlood Group: "<<bloodgroup;
}

class physical
{
	int height,weight;
	public:
	void getDatap();
	void displayp();
};

void physical :: getDatap()
{
	cout<<"\nEnter height: ";
	cin>>height;
	cout<<"\nEnter weight: ";
	cin>>weight;
}
void physical :: displayp()
{
	cout<<"\nHeight: "<<height;
	cout<<"\nWeight: "<<weight;
}

class insurance
{
	double policy_no;
	char address[100];
	public:
	void getDatai();
	void displayi();
};

void insurance :: getDatai()
{
	cin.ignore();
	cout<<"Enter insurance policy number: ";
	cin>>policy_no;
	cout<<"Enter address: ";
	cin.getline(address,100);
}

void insurance :: displayi()
{
	cout<<"Insurance number: "<<policy_no;
	cout<<"Address: "<<address;
}

class data : public info, public physical, public insurance
{
	int phone_no,licence;
	public:
	void getDatad();
	void displayd();
};
void data :: getDatad()
{
//info:getData();
//physical:getDatap();
//insurance:getDatai();
	cout<<"Enter licence number: ";
	cin>>licence;
	cout<<"Enter phone number: ";
	cin>>phone_no;
}
void data :: displayd()
{
//info:display();
//physical:display();
//insurance:display();
	cout<<"Licence number: "<<licence;
	cout<<"Phone number: "<<phone_no;
}

int main()
{
	data m;
	m.getData();
	m.display();
	return 0;
}
