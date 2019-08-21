#include<iostream>                                                //KC
#include<string.h>                                                //KC
#include<stdlib.h>                                                //KC
using namespace std;                                                //KC
                                                //KC
class info                                                //KC
{                                                //KC
	char dob[11],name[50],bloodgroup[5];                                                //KC
	public:                                                //KC
	void getData();                                                //KC
	void display();                                                //KC
};                                                //KC
void info :: getData()                                                //KC
{                                                //KC
	cout<<"\nEnter name: ";                                                //KC
	cin.getline(name,50);                                                //KC
	cin.getline(name,50);                                                //KC
	cout<<"\nEnter date of birth (dd/mm/yyyy): ";                                                //KC
	cin.getline(dob,11);                                                //KC
	cout<<"\nEnter blood group: ";                                                //KC
	cin.getline(bloodgroup,5);                                                //KC
}                                                //KC
void info :: display()                                                //KC
{                                                //KC
	cout<<"\n\nName: "<<name<<"\nDate of birth: "<<dob<<"\nBlood Group: "<<bloodgroup;                                                //KC
}                                                //KC
                                                //KC
class physical                                                //KC
{                                                //KC
	int height,weight;                                                //KC
	public:                                                //KC
	void getDatap();                                                //KC
	void displayp();                                                //KC
};                                                //KC
                                                //KC
void physical :: getDatap()                                                //KC
{                                                //KC
	cout<<"\nEnter height: ";                                                //KC
	cin>>height;                                                //KC
	cout<<"\nEnter weight: ";                                                //KC
	cin>>weight;                                                //KC
}                                                //KC
void physical :: displayp()                                                //KC
{                                                //KC
	cout<<"\nHeight: "<<height;                                                //KC
	cout<<"\nWeight: "<<weight;                                                //KC
}                                                //KC
                                                //KC
class insurance                                                //KC
{                                                //KC
	double policy_no;                                                //KC
	char address[100];                                                //KC
	public:                                                //KC
	void getDatai();                                                //KC
	void displayi();                                                //KC
};                                                //KC
                                                //KC
void insurance :: getDatai()                                                //KC
{                                                //KC
	cout<<"\nEnter insurance policy number: ";                                                //KC
	cin>>policy_no;                                                //KC
	cout<<"\nEnter address: ";                                                //KC
	cin.getline(address,100);                                                //KC
	cin.getline(address,100);                                                //KC
}                                                //KC
                                                //KC
void insurance :: displayi()                                                //KC
{                                                //KC
	cout<<"\nInsurance number: "<<policy_no;                                                //KC
	cout<<"\nAddress: "<<address;                                                //KC
}                                                //KC
                                                //KC
class data : public info, public physical, public insurance                                                //KC
{                                                //KC
	int phone_no;                                                //KC
	char licence[20];                                                //KC
	public:                                                //KC
	void getDatad();                                                //KC
	void displayd();                                                //KC
};                                                //KC
void data :: getDatad()                                                //KC
{                                                //KC
info:getData();                                                //KC
physical:getDatap();                                                //KC
insurance:getDatai();                                                //KC
	  cout<<"\nEnter licence number: ";                                                //KC
	  cin.getline(licence,20);                                                //KC
	  cout<<"\nEnter phone number: ";                                                //KC
	  cin>>phone_no;                                                //KC
}                                                //KC
void data :: displayd()                                                //KC
{                                                //KC
info:display();                                                //KC
physical:displayp();                                                //KC
insurance:displayi();                                                //KC
	  cout<<"\nLicence number: "<<licence;                                                //KC
	  cout<<"\nPhone number: "<<phone_no;                                                //KC
}                                                //KC
                                                //KC
int main()                                                //KC
{                                                //KC
	int n,l;                                                //KC
	cout<<"Enter number of data entries: ";                                                //KC
	cin>>n;                                                //KC
	data z[2];                                                //KC
	for(l=1;l<=2;l++){                                                //KC
	z[2].getDatad();}                                                //KC
	for(l=1;l<=2;l++){                                                //KC
	z[2].displayd();}                                                //KC
	return 0;                                                //KC
}//Kshitij Chitnis                                                //KC
