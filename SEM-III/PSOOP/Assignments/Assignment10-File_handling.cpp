#include<iostream>
#include<fstream>
using namespace std;
class employee
{
	private:
		int id;
		char name[25],designation[25];
		float salary;
	public:
		void getdata();
		void putdata();
};
	void employee::getdata()
	{
		cout<<"\nEnter name of employee";
		cin>>name;
		cout<<"\nEnter Employee id";
		cin>>id;
		cout<<"\nEnter designation of employee";
		cin>>designation;
		cout<<"\nEnter salary of employee";
		cin>>salary;
	}
	void employee::putdata()
	{
		cout<<"\nName:\t"<<name;
		cout<<"\nEmployee_Id:\t"<<id;
		cout<<"\nDesignation:\t"<<designation;
		cout<<"\nSalary:\t"<<salary;
	}
	int main()
	{
		int i,n;
		employee e[10];
		cout<<"Enter number of employees";
		cin>>n;
		fstream fobj;
		fobj.open("employee.txt",ios::binary|ios::out);
		for(i=0;i<n;i++)
		{
			e[i].getdata();
			fobj.write((char*)&e[i],sizeof(e[i]));
		}
		fobj.close();
		fobj.seekg(0);
		cout<<"\nRead from the file";
		fobj.open("employee.txt",ios::in|ios::out);
		for(i=0;i<n;i++)
		{
			e[i].putdata();
			fobj.read((char*)&e[i],sizeof(e[i]));
		}
		fobj.close();	
		return 0;
	}
//Kshitij Chitnis
