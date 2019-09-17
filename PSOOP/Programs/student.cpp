#include<iostream>
using namespace std;
class student
{
private:
int roll_no,marks,i;
char name[50];
float perc,a;
public:
void getdata()
{
cout<<"Enter the name:";
cin>>name;
cout<<"Enter roll no:";
cin>>roll_no;
cout<<"Enter marks:";
cin>>marks;
}
void putdata()
{
cout<<"student details are:\n";
cout<<name;
cout<<"\nRoll no. :"<<roll_no<<"\nMarks:"<<marks;
a=marks*100;
perc=a/500;
cout<<"\nPercentage:"<<perc<<"\n";
}
};
int main()
{
student s;
s.getdata();
s.putdata();
return 0;
}
