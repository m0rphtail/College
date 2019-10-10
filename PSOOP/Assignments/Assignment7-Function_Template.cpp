#include<iostream>

int const size=3;
using namespace std;

template <class M, class S>
void add(M a[][size],S b[][size])
{
	S c[size][size];
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
    		}

	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
    		{
     			cout<<"   "<<c[i][j];
      		}
    		cout<<endl;
}

template <class M,class S>
void sub(M a[][size],S b[][size])
{
	S c[size][size];
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
		{
			c[i][j]=a[i][j]-b[i][j];
		}
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
		{
			cout<<"   "<<c[i][j];
		}
		cout<<endl;
}

template <class M,class S>
void mul(M a[][size],S b[][size])
{
	S c[size][size];
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			for(int k=0;k<size;k++)
			c[i][j]=a[i][k]*b[k][j];
		}
	}
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			cout<<"   "<<c[i][j];
		}
		cout<<endl;
	}
}

template <class M>
void trans(M a[][size])
{
 M c[size][size];
 for(int i=0;i<size;i++)
 {
    for(int j=0;j<size;j++)
    {
    c[i][j]=a[j][i];
    }
  }
cout<<endl<<endl<<"Transpose of matrix :"<<endl;
 for(int i=0;i<size;i++)
      {
    for(int j=0;j<size;j++)
    {
     cout<<c[i][j]<<"\t";
      }
    cout<<endl;
    }
}

int main()
{
 int x[size][size],y[size][size];
 float g[size][size],h[size][size];
 int ch;

//Read matrices
 cout<<endl<<"Enter values for matrix X:";
 for(int i=0;i<size;i++)
      {
    for(int j=0;j<size;j++)
    {
     cin>>x[i][j];
      }
    cout<<endl;
    }

 cout<<endl<<"Enter values for matrix g:";
  for(int i=0;i<size;i++)
      {
    for(int j=0;j<size;j++)
    {
     cin>>g[i][j];
      }
    cout<<endl;
    }

//Display matrices as entered by user
cout<<endl<<endl<<"Int matrix X:"<<endl;
 for(int i=0;i<size;i++)
      {
    for(int j=0;j<size;j++)
    {
     cout<<x[i][j]<<"\t";
      }
    cout<<endl;
    }
cout<<endl<<endl<<"Float matrix G:"<<endl;
 for(int i=0;i<size;i++)
      {
    for(int j=0;j<size;j++)
    {
     cout<<g[i][j]<<"\t";
      }
    cout<<endl;
    }


 do
  {
 cout<<endl<<"************* Operations ****************  \n1.addition of matrix \n2.Substraction of Matrix \n3.Multiplication \n4.Transpose "<<endl<<endl<<"\t Enter Choice";;
 cin>>ch;
 switch(ch)
 {
 case 1 : cout<<endl<<"Result of Addition of matrix X and G : "<<endl;
    add(x,g);
    break;
case 2 : cout<<endl<<"Result of Substraction of matrix X and G : "<<endl;
     sub(x,g);
    break;
 case 3 : cout<<endl<<"Result of Multiplication of matrix X and G : "<<endl;
    mul(x,g);
    break;
case 4 : trans(x);
    trans(g);
    break;
default : cout<<endl<<"Enter valid option"<<endl<<endl;
    break;
 }
}while(ch<6);
return 0;
}//Kshitij Chitnis
