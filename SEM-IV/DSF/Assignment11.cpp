//Kshitij Chitnis
//SE-IT
//S2-BATCH
//ROLL NO:8016

//ASSIGNMENT 11
// PROBLEM STATEMENT
// Department maintains a student information. The file contains roll number, name, division and address.
// Write a program to create a sequential file to store and maintain student data. It should allow the user to add,
// delete information of student. Display information of particular employee. If record of student does not exist an
// appropriate message is displayed. If student record is found it should display the student details.

#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

class student        //student class
{
    int rollno;
    char addr[20],name[10];
    int s1,s2,s3;
public:
    student()
    {
        rollno=s1=s2=s3=0;
    }
    void accept();
    void disp();
    void change();
    int retroll();
};

void student::accept()     //accept function
{
    fstream fp;
    student st;
    int k=0;
    static int roll=1;
    fp.open("student",ios::in);
    if(fp)
    {
    	fp.seekg(-sizeof(st),ios::end);
        fp.read((char*)&st,sizeof(st));
        roll=st.rollno+1;
	}
   
    fp.close();
    
    cout<<"\nEnter the Name of student:";
    cin>>name;
    cout<<"\nEnter the city:";
    cin>>addr;
    cout<<"\nEnter the marks of subjects s1,s2,s3:";
    cin>>s1>>s2>>s3;
    cout<<"\n";
    while(s1<0||s2<0||s3<0)
     {
      cout<<"\nReenter Marks should not be negative ";
      cout<<"\nEnter the marks of subjects s1,s2,s3";
      cin>>s1>>s2>>s3;
    }
    rollno=roll;
    roll++;
}

void student::disp()       //display function
{
    cout<<"\nRoll no\t\t"<<rollno;
    cout<<"\nName\t\t"<<name;
    cout<<"\nAddress\t\t"<<addr;
    cout<<"\nMarks of subjects:"<<s1<<" "<<s2<<" "<<s3<<"\n";
    
}

int student::retroll()       //return rollno function
{
    return rollno;
}

void student::change()      //chnage data function
{
    int ch;
do{
    cout<<"\n1.Name\n2.Address\n3.marks\n0.Exit\nEnter your choice";
    cin>>ch;
    switch(ch)
    {
    case 1:
             cout<<"\nEnter new name";
             cin>>name;
             break;
    case 2:
             cout<<"\nEnter new city";
             cin>>addr;
             break;
    case 3:
             cout<<"\nEnter marks of subjects s1,s2,s3";
             cin>>s1>>s2>>s3;
              while(s1<0||s2<0||s3<0)
     	      {
     		 cout<<"\nReenter Marks should not be negative ";
      		 cout<<"\nEnter the marks of subjects s1,s2,s3";
      		 cin>>s1>>s2>>s3;
    	      }
             break;
    }
   } while(ch!=0);
    
}

class seqfile          //File class
{
public:
    void create();
    void insert();
    void search();
    void del();
    void display();
    void modify();
};

void seqfile::insert()     //insert record function
{
    fstream fp;
    student st;
    fp.open("student",ios::out|ios::app);
    st.accept();
    fp.write((char*)&st,sizeof(st));
    fp.close();
}

void seqfile::create()     //create function
{
    int i,n;

    cout<<"\nHow many records you want to insert";
    cin>>n;
    for(i=0;i<n;i++)
    {
        insert();
    }
}

void seqfile::display()    //display function
{
    fstream fp;
    student st;
    fp.open("student",ios::in);
    if(fp)
    {
        while(fp.read((char*)&st,sizeof(st)))
        {
            st.disp();
        }
    }
    else
    {
        cout<<"\nFile is not present";
    }
    fp.close();
}

void seqfile::modify()      //modify function
{
    fstream fp,fpt;
    student st;
    int flag=0;
    int r;
    cout<<"\nEnter the roll number";
    cin>>r;

    fp.open("student",ios::in);
    if(fp)
    {
        fpt.open("temp",ios::out|ios::ate);
        while(fp.read((char*)&st,sizeof(st)))
        {
            if(st.retroll()==r)
            {
                cout<<"\nOld Record is\n";
                st.disp();
                st.change();
                flag=1;
            }
            fpt.write((char*)&st,sizeof(st));
        }
        fpt.close();
        if(flag==0)
        {
            cout<<"\nRecord not found";
        }
    }
    else
    {
        cout<<"\nFile is not created";
    }
    fp.close();
    remove("student");
    rename("temp","student");

}

void seqfile::del()     //delete record function
{
    fstream fp,fpt;
    student st;
    int flag=0;
    int r;
    cout<<"\nEnter the roll number to delete record";
    cin>>r;

    fp.open("student",ios::in);
    if(fp)
    {
        fpt.open("temp",ios::out|ios::ate);
        while(fp.read((char*)&st,sizeof(st)))
        {
            if(st.retroll()!=r)
            {
                fpt.write((char*)&st,sizeof(st));
            }
            else
            {
                flag=1;
            }
       }
        fpt.close();
        if(flag==0)
        {
            cout<<"\nRecord not found";
        }
        else
        {
            cout<<"\nRecord successfully deleted";
        }
    }
    else
    {
        cout<<"\nFile is not created";
    }
    fp.close();
    remove("student");
    rename("temp","student");
}

void seqfile::search()      //search function
{
    fstream fp;
    int r,flag=0;
    student st;
    cout<<"\nEnter roll number to search record";
    cin>>r;

    fp.open("student",ios::in);
    if(!fp)
    {
        cout<<"\nFile is not present";
    }
    else
    {
        while(fp.read((char*)&st,sizeof(st)))
        {
            if(st.retroll()==r)
            {
                cout<<"\nRecord found";
                st.disp();
                flag=1;
            }
        }
        fp.close();
        if(flag==0)
        {
            cout<<"\nRecord not found";
        }
    }
}
int main()
{
    int ch;
    seqfile fp;
    do
    {
        cout<<"\n1.Create\n2.insert\n3.display\n4.Modify\n5.Delete\n6.search\n7.EXIT";
        cout<<"\nEnter your choice";
        cin>>ch;
        switch(ch)
        {
        case 1:
                fp.create();     //create function call
                break;
        case 2:
                fp.insert();    //insert function call
                break;
        case 3:
               cout<<"**********Records**********";
                fp.display();   //display function call
                break;
        case 4:
                fp.modify();     //modify function call
                break;
        case 5:
                fp.del();        //delete function call
                break;
        case 6:
                fp.search();     //search function call
                break;
        case 7: exit(0);
                break;
        default:cout<<"\nWRONG CHOICE ENTERED ";
        }
    }while(ch!=7);

}


/*OUTPUT:


1.Create
2.insert
3.display
4.Modify
5.Delete
6.search
7.EXIT
Enter your choice1

How many records you want to insert3

Enter the Name of student abc

Enter the city pune

Enter the marks of subjects s1,s2,s3 -20
30
40

Reenter Marks should not be negative 
Enter the marks of subjects s1,s2,s3 20 30 40

Enter the Name of studentxyz

Enter the city solapur

Enter the marks of subjects s1,s2,s3 50 60 70

Enter the Name of student pqr

Enter the city satara

Enter the marks of subjects s1,s2,s3 80 90 100

1.Create
2.insert
3.display
4.Modify
5.Delete
6.search
7.EXIT
Enter your choice3
**********Records**********
Roll no		1
Name		abc
Address		pune
Marks of subjects:20 30 40
Roll no		2
Name		xyz
Address		solapur
Marks of subjects:50 60 70
Roll no		3
Name		pqr
Address		satara
Marks of subjects:80 90 100
1.Create
2.insert
3.display
4.Modify
5.Delete
6.search
7.EXIT
Enter your choice7
[root@localhost Documents]# ./a.out

1.Create
2.insert
3.display
4.Modify
5.Delete
6.search
7.EXIT
Enter your choice2

Enter the Name of student ijk

Enter the city kolhapur

Enter the marks of subjects s1,s2,s3 12 14 16

1.Create
2.insert
3.display
4.Modify
5.Delete
6.search
7.EXIT
Enter your choice3
**********Records**********
Roll no		1
Name		abc
Address		pune
Marks of subjects:20 30 40
Roll no		2
Name		xyz
Address		solapur
Marks of subjects:50 60 70
Roll no		3
Name		pqr
Address		satara
Marks of subjects:80 90 100
Roll no		4
Name		ijk
Address		kolhapur
Marks of subjects:12 14 16
1.Create
2.insert
3.display
4.Modify
5.Delete
6.search
7.EXIT
Enter your choice4

Enter the roll number 4

Old Record is

Roll no		4
Name		ijk
Address		kolhapur
Marks of subjects:12 14 16
1.Name
2.Address
3.marks
0.Exit
Enter your choice3

Enter marks of subjects s1,s2,s3 25 30 35

1.Name
2.Address
3.marks
0.Exit
Enter your choice0

1.Create
2.insert
3.display
4.Modify
5.Delete
6.search
7.EXIT
Enter your choice3
**********Records**********
Roll no		1
Name		abc
Address		pune
Marks of subjects:20 30 40
Roll no		2
Name		xyz
Address		solapur
Marks of subjects:50 60 70
Roll no		3
Name		pqr
Address		satara
Marks of subjects:80 90 100
Roll no		4
Name		ijk
Address		kolhapur
Marks of subjects:25 30 35
1.Create
2.insert
3.display
4.Modify
5.Delete
6.search
7.EXIT
Enter your choice6

Enter roll number to search record3

Record found
Roll no		3
Name		pqr
Address		satara
Marks of subjects:80 90 100
1.Create
2.insert
3.display
4.Modify
5.Delete
6.search
7.EXIT
Enter your choice5

Enter the roll number to delete record4

Record successfully deleted
1.Create
2.insert
3.display
4.Modify
5.Delete
6.search
7.EXIT
Enter your choice3
**********Records**********
Roll no		1
Name		abc
Address		pune
Marks of subjects:20 30 40
Roll no		2
Name		xyz
Address		solapur
Marks of subjects:50 60 70
Roll no		3
Name		pqr
Address		satara
Marks of subjects:80 90 100
1.Create
2.insert
3.display
4.Modify
5.Delete
6.search
7.EXIT
Enter your choice7
*/

