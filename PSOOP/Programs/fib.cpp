#include<iostream>
using namespace std;
class series
{
	
	int f1,f2,nf;
	public:
		series();
		void displayseries(int );
		
};

series::series()
{
	f1=0;
	f2=1;
}
void series::displayseries(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		cout<<f1<<endl;
		nf=f1+f2;
		f1=f2;
		f2=nf;
	}
}

int main()
{
	int n;
	cout<<"enter how much long u want series";
	cin>>n;
	series s1;
	s1.displayseries(n);
	return 0;	
}
//Kshitij Chitnis