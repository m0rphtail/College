#include<iostream>                                                //KC
using namespace std;                                                //KC
class weather  //class definition                                                //KC
{                                                //KC
	int d_o_m;                                                //KC
	float htemp,ltemp,amt_of_rain,amt_of_snow;                                                //KC
public:                                                //KC
	weather();                                                                       //KC
	void inputdata(int);           //funtion prototypes                                                //KC
	void display();                                                //KC
	void average(weather *w); //using a pointer as an array                                                //KC
};                                                //KC
weather::weather()              //function definition outside of class using :: operator                                                //KC
{                                                //KC
	htemp=0;                                                //KC
	ltemp=0;                                                //KC
	amt_of_rain=0;                                                //KC
	amt_of_snow=0;                                                //KC
	d_o_m=0;                                                //KC
}                                                //KC
void weather::inputdata(int d) //funtion definition outside the class.funtion to get data.                                                 //KC
{                                                //KC
	d_o_m=d;                                                //KC
	cout<<"Enter high Temp:";                                                //KC
	cin>>htemp;                                                //KC
	cout<<"\nEnter low Temp:";                                                //KC
	cin>>ltemp;                                                //KC
	cout<<"\nEnter Amt of Rain:";                                                //KC
	cin>>amt_of_rain;                                                //KC
	cout<<"\nEnter Amt of Snow:";                                                //KC
	cin>>amt_of_snow;                                                //KC
}                                                //KC
void weather::display()        //funtion to display data                                                //KC
{                                                //KC
	cout<<"\t"<<d_o_m;                                                //KC
	cout<<"\t\t"<<htemp;                                                //KC
	cout<<"\t"<<ltemp;                                                //KC
	cout<<"\t"<<amt_of_rain;                                                //KC
	cout<<"\t"<<amt_of_snow;                                                //KC
}                                                //KC
void weather::average(weather w[31])  //funtion to calculate average weather conditions                                                //KC
{                                     //used pointer as an array to point it to the entire array,not only to one element.                                                 //KC
	float train,tsnow,tltemp,thtemp;                                                //KC
	float avghtemp,avgltemp,avgrain,avgsnow;                                                //KC
	train=tsnow=tltemp=thtemp=0;                                                //KC
	int i,count=0;                                                //KC
	for(i=1;i<=31;i++)                                                //KC
	{                                                //KC
        	if(w[i].d_o_m==90)                                                //KC
        	continue;                                                //KC
        	else                                                //KC
        	{                                                //KC
        		thtemp+=w[i].htemp;                                                //KC
        		tltemp+=w[i].ltemp;                                                //KC
        		train+=w[i].amt_of_rain;                                                //KC
        		tsnow+=w[i].amt_of_snow;                                                //KC
        		count++;                                                //KC
        	}                                                //KC
	}                                                //KC
		avghtemp=thtemp/count;                                                //KC
		avgltemp=tltemp/count;                                                //KC
		avgrain=train/count;                                                //KC
		avgsnow=tsnow/count;                                                //KC
		cout<<"\nAverage High Temp:"<<avghtemp;                                                //KC
		cout<<"\nAverage Low Temp:"<<avgltemp;                                                //KC
		cout<<"\nAverage Amount of Rain:"<<avgrain;                                                //KC
		cout<<"\nAverage Amount of Snow:"<<avgsnow;                                                //KC
}                                                //KC
int main()                                                //KC
{                                                //KC
	weather data[40][40],temp[40],obj;                                                //KC
	int choice,i,day,month;                                                //KC
	char answer;                                                //KC
	cout<<"\nWEATHER REPORT";                                                //KC
	do                                                //KC
	{                                                //KC
		cout<<"\n Main Menu";                                                //KC
		cout<<"\n1.Enter Data.";                                                //KC
		cout<<"\n2.Display Report.";                                                //KC
		cout<<"\n3.Exit.";                                                //KC
		cout<<"\nEnter your choice:";                                                //KC
		cin>>choice;                                                //KC
		switch(choice)                                                //KC
		{                                                //KC
		 	case 1:                                                //KC
a:                                                //KC
			cout<<"\nEnter the month:";                                                //KC
			cin>>month;                                                //KC
			if(month==0 || month>=13)    //checking to see vaild month.                                                //KC
			{                                                //KC
				cout<<"Invalid month.\n";                                                //KC
				cout<<"Enter again\n";                                                //KC
				goto a;                                                //KC
			}                                                //KC
			else if(month==2)                                                //KC
			{                                                //KC
c:                                                //KC
				cout<<"\nEnter the day:";                                                //KC
				cin>>day;                                                //KC
				if(day==0 || day>=29)   //checking to see vaild date in february                                                //KC
				{                                                //KC
					cout<<"Invalid day.\nEnter again\n";                                                //KC
					goto c;                                                //KC
				}                                                //KC
				else{}                                                //KC
			}                                                //KC
			else if(month==4 || month==6 || month==9 || month==11)                                                //KC
			{                                                //KC
d:                                                //KC
				cout<<"\nEnter the day:";                                                //KC
				cin>>day;                                                //KC
				if(day==0 || day>=31)                                                //KC
				{                                                //KC
					cout<<"Invalid day.\nEnter again\n";                                                //KC
					goto d;                                                //KC
				}                                                //KC
				else{}                                                //KC
			}                                                //KC
			else                                                //KC
			{                                                //KC
b:                                                //KC
			cout<<"\nEnter the day:";                                                //KC
			cin>>day;                                                //KC
			if(day==0 || day>=32)      //checking to see vaild date                                                //KC
			{                                                //KC
				cout<<"Invalid day.\nEnter again\n;";                                                //KC
				goto b;                                                //KC
                                                //KC
			}                                                //KC
			else{}                                                //KC
			}                                                //KC
			data[month][day].inputdata(day);                                                //KC
			break;                                                //KC
			case 2:                               //case to display report                                                //KC
			cout<<"\nEnter the month:";                                                //KC
			cin>>month;                                                //KC
			cout<<"\n\n\tDOM\t  High_temp  Low_temp Amt_Rain Amt_Snow";                                                //KC
			for(int i=1;i<=31;i++)                                                //KC
			{                                                //KC
				cout<<"\n"<<i;                                                //KC
				data[month][i].display(); //calling display function                                                //KC
			}                                                //KC
			for(int i=1;i<=31;i++)                                                //KC
			{                                                //KC
				temp[i]=data[month][i];                                                //KC
			}                                                //KC
			obj.average(temp);                                                //KC
			break;                                                //KC
		}                                                //KC
		cout<<"\nDo u want to continue?"; //condition to continue the program                                                //KC
		cin>>answer;                                                //KC
	}while(answer=='y');                                                //KC
	return 0;                                                //KC
}                                                //KC
//Kshitij Chitnis                                                //KC
