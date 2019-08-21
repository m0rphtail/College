#include <iostream>                                                //KC
using namespace std;                                                //KC
class employee                                                //KC
{                                                //KC
    private:                                                //KC
    char name[20];                                                //KC
    int f,ID,salary,d;                                                //KC
    public:                                                //KC
    void getdata()                                                //KC
    {                                                //KC
    	cout<<"\n Employee's Name";                                                //KC
    	cin>>name;                                                //KC
    	cout<<"\n Employee's Id";                                                //KC
    	cin>>ID;                                                //KC
    	cout<<"\n Employee's salary";                                                //KC
    	cin>>salary;                                                //KC
    	cout<<"\n Enter Number Of Leaves in one month";                                                //KC
    	cin>>d;                                                //KC
    }                                                //KC
    void putdata()                                                //KC
    {                                                //KC
    	cout<<"\n Employee's Name"<<name;                                                //KC
    	cout<<"\n Employee's Id"<<ID;                                                //KC
    	cout<<"\n Employee's salary"<<salary;                                                //KC
    	cout<<"\n Number Of Leaves in one month"<<d;                                                //KC
    	if(d>8)                                                //KC
    	{                                                //KC
    		f=salary*20/100;                                                //KC
    		salary=salary-f;                                                //KC
    	}                                                //KC
    	else if(d<8&&d>5)                                                //KC
    	{                                                //KC
    		f=salary*10/100;                                                //KC
    		salary=salary-f;                                                //KC
    	}                                                //KC
    	else if(d<5)                                                //KC
    	{                                                //KC
    		f=0;                                                //KC
    		salary=salary - f;                                                //KC
    	}                                                //KC
    	cout<<"Salary after fine"<<salary;                                                //KC
    }                                                //KC
};                                                //KC
        int main()                                                //KC
        {                                                //KC
        	int i;                                                //KC
        	employee obj[5];                                                //KC
	        for(i=0;i<5;i++)                                                //KC
        	{                                                //KC
        		obj[i].getdata();                                                //KC
        		obj[i].putdata();                                                //KC
        	}                                                //KC
        	return 0;                                                //KC
        }//Kshitij Chitnis                                                //KC
