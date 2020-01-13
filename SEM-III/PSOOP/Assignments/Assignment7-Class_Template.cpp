#include<iostream>
using namespace std;
template<class t>       //define a template t
class matrix            //creating a class matrix
{
	t a[10][10],b[10][10];
	int i,j,n1,m1,n2,m2;
	public:
		void getdata();
		void display();
		void add();
		void sub();
		void trans();
		void mul();
		void saddle();
};

template<class t>       //using the class template for all the function declarations
void matrix<t>::getdata()
{
	cout<<"\nenter no of rows of first matrix\n";
	cin>>n1;
	cout<<"\nenter no of columns of first matrix\n";
	cin>>m1;
	cout<<"\nnow enter elements in first matrix\n";
	for(i=0;i<n1;i++)
	{
		for(j=0;j<m1;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<"\nenter no of rows of second  matrix\n";
	cin>>n2;
	cout<<"\nenter no of columns of second matrix\n";
	cin>>m2;
	cout<<"\nnow enter elements in second matrix\n";
	for(i=0;i<n2;i++)
	{
		for(j=0;j<m2;j++)
		{
			cin>>b[i][j];
		}
	}
	
}

template<class t>
void matrix<t>::display()
{
	cout<<"\nfirst matrix is:\n";
	for(i=0;i<n1;i++)
	{
		for(j=0;j<m1;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	cout<<"\nsecond matrix is:\n";
	for(i=0;i<n2;i++)
	{
		for(j=0;j<m2;j++)
		{
			cout<<b[i][j]<<"\t";
		}
		cout<<endl;
	}	
}

template<class t>
void matrix<t>::add()
{
	t c[10][10];
	if(n1==n2 && m1==m2)
	{
		for(i=0;i<n1;i++)
		{
			for(j=0;j<m1;j++)
			{
				c[i][j]=a[i][j]+b[i][j];
			}
		}
	
	cout<<"\naddition of above matrices is:\n";
	for(i=0;i<n1;i++)
	{
		for(j=0;j<m1;j++)
		{
			cout<<c[i][j]<<"\t";
		}
		cout<<endl;
	}	
	}
	else
	{
		cout<<"\nenter correct matrices \n";
	}
}

template<class t>
void matrix<t>::sub()
{
	t c[10][10];
	if(n1==n2 && m1==m2)
	{
		for(i=0;i<n1;i++)
		{
			for(j=0;j<m1;j++)
			{
				c[i][j]=a[i][j]-b[i][j];
			}
		}
	
	cout<<"\nsubtraction of above matrices is:\n";
	for(i=0;i<n1;i++)
	{
		for(j=0;j<m1;j++)
		{
			cout<<c[i][j]<<"\t";
		}
		cout<<endl;
	}	
	}
	else
	{
		cout<<"\nenter correct matrices \n";
	}
}

template<class t>
void matrix<t>::trans()
{
	t d[10][10],x;
	int i,j;
	for(i=0;i<n1;i++)
	{
		for(j=0;j<m1;j++)
		{
			d[i][j]=a[i][j];
		}
	}
	for(i=0;i<n1;i++)
	{
		for(j=i;j<m1;j++)
		{
			x=d[i][j];
			d[i][j]=d[j][i];
			d[j][i]=x;
		}
	}
	
		cout<<"\ntranspose of first matrix is:\n";
	for(i=0;i<n1;i++)
	{
		for(j=0;j<m1;j++)
		{
			cout<<d[i][j]<<"\t";
		}
		cout<<endl;
	}	
}

template<class t>
void matrix<t>::mul()
{
	t e[10][10];
	int i,j,k;
	if(m1==n2)
	for(i=0;i<n1;i++)
	{
		for(j=0;j<m2;j++)
		{
			e[i][j]=0;
			for(k=0;k<m1;k++)
			{
				e[i][j]=e[i][j]+a[i][k]*b[k][j];
			}
		}
	}
	cout<<"\nmultiplication  of above matrices is:\n";
	for(i=0;i<n1;i++)
	{
		for(j=0;j<m2;j++)
		{
			cout<<e[i][j]<<"\t";
		}
		cout<<endl<<endl;
	}
}

int main()
{
	int x,ch1,ch2;
	char con;
	matrix<int> mat1;      //making the template use int data type
	matrix<float> mat2;    //making the template use float data type
	a:
	cout<<"\nDo you want integer or float?\n1) Integer\n2) Float\n Enter choice: ";
	cin>>x;
	if(x==1){
	do{
	cout<<"\nFor integers\n1.getdata\n2.addition\n3.subtraction\n4.transpose\n5.multiplication\n";
	cin>>ch1;
	switch(ch1)
	{
		case 1:
		mat1.getdata();
		mat1.display();
		break;
		case 2:
		mat1.add();
		break;
		case 3:
		mat1.sub();
		break;
		case 4:
		mat1.trans();
		break;
		case 5:
		mat1.mul();
		break;
	}
	cout<<"\ndo you want to continue?(y/n): ";
	cin>>con;
	}while(con=='y');
	}
	else if(x==2){
	do{
cout<<"\nFor float operations\n\n1.getdata\n2.addition\n3.subtraction\n4.transpose\n5.multiplication\n";
	cin>>ch2;
	switch(ch2)
	{
		case 1:
		mat2.getdata();
		mat2.display();
		break;
		case 2:
		mat2.add();
		break;
		case 3:
		mat2.sub();
		break;
		case 4:
		mat2.trans();
		break;
		case 5:
		mat2.mul();
		break;
	}
	cout<<"\ndo you want to continue?(y/n): ";
	cin>>con;
	}while(con=='y');
	}
	else
	{
	cout<<"\nEnter correct option!\n";
	goto a;
	}
	return 0;
}//Kshitij Chitnis
