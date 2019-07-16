#include<iostream>
using namespace std;
class weather
{
	int d_o_m;
	float htemp,ltemp,amt_of_rain,amt_of_snow;
public:
	weather();
	void inputdata(int);
	void display();
	void average(weather *w);
};
weather::weather()
{
	htemp=0;
	ltemp=0;
	amt_of_rain=0;
	amt_of_snow=0;
	d_o_m=0;
}
void weather::inputdata(int d)
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
void weather::display()
{
	cout<<"\t"<<d_o_m;
	cout<<"\t\t"<<htemp;
	cout<<"\t"<<ltemp;
	cout<<"\t"<<amt_of_rain;
	cout<<"\t"<<amt_of_snow;
}
void weather::average(weather w[31])
{
	int train,tsnow,tltemp,thtemp;
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
			if(month==0 || month>=13)
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
				if(day==0 || day>=29)
				{
					cout<<"Invalid day.\nEnter again\n";
					goto c;
				}
				else{}
			}
			else
			{
b:
			cout<<"\nEnter the day:";
			cin>>day;
			if(day==0 || day>=32)
			{
				cout<<"Invalid day.\nEnter again\n;";
				goto b;

			}
			else{}
			}
			data[month][day].inputdata(day);
			break;
			case 2:
			cout<<"\nEnter the month:";
			cin>>month;
			cout<<"\n\n\tDOM\t  High_temp  Low_temp Amt_Rain Amt_Snow";
			for(int i=1;i<=31;i++)
			{
				cout<<"\n"<<i;
				data[month][i].display();
			}
			for(int i=1;i<=31;i++)
			{
				temp[i]=data[month][i];
			}
			obj.average(temp);
			break;
		}
		cout<<"\nDo u want to continue?";
		cin>>answer;
	}while(answer=='y');
	return 0;
}
