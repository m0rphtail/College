#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class info
{
	char dob[11],name[50],bloodgroup[5];
	public:
	void getData();
	void display();
};
void info :: getData()
{
	cout<<"\nEnter name: ";
	cin.getline(name,50);
	cin.getline(name,50);
	cout<<"\nEnter date of birth (dd/mm/yyyy): ";
	cin.getline(dob,11);
	cout<<"\nEnter blood group: ";
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
	cout<<"\nEnter height (in cm): ";
	cin>>height;
	cout<<"\nEnter weight (in kg): ";
	cin>>weight;
}
void physical :: displayp()
{
	cout<<"\nHeight: "<<height<<" cm";
	cout<<"\nWeight: "<<weight<<" kg";
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
	cout<<"\nEnter insurance policy number: ";
	cin>>policy_no;
	cout<<"\nEnter address: ";
	cin.getline(address,100);
	cin.getline(address,100);
}

void insurance :: displayi()
{
	cout<<"\nInsurance number: "<<policy_no;
	cout<<"\nAddress: "<<address;
}

class data : public info, public physical, public insurance
{
	int phone_no;
	char licence[20];
	public:
	void getDatad();
	void displayd();
};
void data :: getDatad()
{
info:getData();
physical:getDatap();
insurance:getDatai();
	  cout<<"\nEnter licence number: ";
	  cin.getline(licence,20);
	  cout<<"\nEnter phone number: ";
	  cin>>phone_no;
}
void data :: displayd()
{
info:display();
physical:displayp();
insurance:displayi();
	  cout<<"\nLicence number: "<<licence;
	  cout<<"\nPhone number: +91 "<<phone_no;
}

int main()
{
	int n,i;
	cout<<"Enter number of data entries: ";
	cin>>n;
	data z[n];
	for(i=0;i<n;i++){
	cout<<"Entry "<<i+1;
	z[i].getDatad();}
	for(i=0;i<n;i++){
	z[i].displayd();}
	return 0;
}
