#include<iostream>
using namespace std;
class weather  //class definition
{
	int d_o_m;
	float htemp,ltemp,amt_of_rain,amt_of_snow;
public:
	weather();                       
	void inputdata(int);           //funtion prototypes
	void display();
	void average(weather *w); //using a pointer as an array
};
weather::weather()              //function definition outside of class using :: operator
{
	htemp=0;
	ltemp=0;
	amt_of_rain=0;
	amt_of_snow=0;
	d_o_m=0;
}
void weather::inputdata(int d) //funtion definition outside the class.funtion to get data. 
{
	d_o_m=d;
	cout<<"Enter high Temp:";
	cin>>htemp;
	cout<<"\nEnter low Temp:";
	cin>>ltemp;
	cout<<"\nEnter Amt of Rain:";
	cin>>amt_of_rain;
	cout<<"\nEnter Amt of Snow:";
	cin>>amt_of_snow;
}
void weather::display()        //funtion to display data
{
	cout<<"\t"<<d_o_m;
	cout<<"\t\t"<<htemp;
	cout<<"\t"<<ltemp;
	cout<<"\t"<<amt_of_rain;
	cout<<"\t"<<amt_of_snow;
}
void weather::average(weather w[31])  //funtion to calculate average weather conditions
{                                     //used pointer as an array to point it to the entire array,not only to one element. 
	float train,tsnow,tltemp,thtemp;
	float avghtemp,avgltemp,avgrain,avgsnow;
	train=tsnow=tltemp=thtemp=0;
	int i,count=0;
	for(i=1;i<=31;i++)
	{
        	if(w[i].d_o_m==90)
        	continue;
        	else
        	{
        		thtemp+=w[i].htemp;
        		tltemp+=w[i].ltemp;
        		train+=w[i].amt_of_rain;
        		tsnow+=w[i].amt_of_snow;
        		count++;
        	}
	}
		avghtemp=thtemp/count;
		avgltemp=tltemp/count;
		avgrain=train/count;
		avgsnow=tsnow/count;
		cout<<"\nAverage High Temp:"<<avghtemp;
		cout<<"\nAverage Low Temp:"<<avgltemp;
		cout<<"\nAverage Amount of Rain:"<<avgrain;
		cout<<"\nAverage Amount of Snow:"<<avgsnow;
}
int main()
{
	weather data[40][40],temp[40],obj;
	int choice,i,day,month;
	char answer;
	cout<<"\nWEATHER REPORT";
	do
	{
		cout<<"\n Main Menu";
		cout<<"\n1.Enter Data.";
		cout<<"\n2.Display Report.";
		cout<<"\n3.Exit.";
		cout<<"\nEnter your choice:";
		cin>>choice;
		switch(choice)
		{
		 	case 1:
a:
			cout<<"\nEnter the month:";
			cin>>month;
			if(month==0 || month>=13)    //checking to see vaild month.
			{
				cout<<"Invalid month.\n";
				cout<<"Enter again\n";
				goto a;
			}
			else if(month==2)
			{
c:
				cout<<"\nEnter the day:";
				cin>>day;
				if(day==0 || day>=29)   //checking to see vaild date in february
				{
					cout<<"Invalid day.\nEnter again\n";
					goto c;
				}
				else{}
			}
			else if(month==4 || month==6 || month==9 || month==11)
			{
d:
				cout<<"\nEnter the day:";
				cin>>day;
				if(day==0 || day>=31)
				{
					cout<<"Invalid day.\nEnter again\n";
					goto d;
				}
				else{}
			}
			else
			{
b:
			cout<<"\nEnter the day:";
			cin>>day;
			if(day==0 || day>=32)      //checking to see vaild date
			{
				cout<<"Invalid day.\nEnter again\n;";
				goto b;

			}
			else{}
			}
			data[month][day].inputdata(day);
			break;
			case 2:                               //case to display report
			cout<<"\nEnter the month:";
			cin>>month;
			cout<<"\n\n\tDOM\t  High_temp  Low_temp Amt_Rain Amt_Snow";
			for(int i=1;i<=31;i++)
			{
				cout<<"\n"<<i;
				data[month][i].display(); //calling display function
			}
			for(int i=1;i<=31;i++)
			{
				temp[i]=data[month][i];
			}
			obj.average(temp);
			break;
		}
		cout<<"\nDo u want to continue?"; //condition to continue the program
		cin>>answer;
	}while(answer=='y');
	return 0;
}
