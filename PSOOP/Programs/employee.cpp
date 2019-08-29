#include <iostream>
using namespace std;
class employee
{
    private:
    char name[20];
    int f,ID,salary,d;
    public:
    void getdata()
    {
    	cout<<"\n Employee's Name";
    	cin>>name;
    	cout<<"\n Employee's Id";
    	cin>>ID;
    	cout<<"\n Employee's salary";
    	cin>>salary;
    	cout<<"\n Enter Number Of Leaves in one month";
    	cin>>d;
    }
    void putdata()
    {
    	cout<<"\n Employee's Name"<<name;
    	cout<<"\n Employee's Id"<<ID;
    	cout<<"\n Employee's salary"<<salary;
    	cout<<"\n Number Of Leaves in one month"<<d;
    	if(d>8)
    	{
    		f=salary*20/100;
    		salary=salary-f;
    	}
    	else if(d<8&&d>5)
    	{
    		f=salary*10/100;
    		salary=salary-f;
    	}
    	else if(d<5)
    	{
    		f=0;
    		salary=salary - f;
    	}
    	cout<<"Salary after fine"<<salary;
    }
};
        int main()
        {
        	int i;
        	employee obj[5];
	        for(i=0;i<5;i++)
        	{
        		obj[i].getdata();
        		obj[i].putdata();
        	}
        	return 0;
        }//Kshitij Chitnis
