#include<iostream>                                                //KC
using namespace std;                                                //KC
class series                                                //KC
{                                                //KC
	                                                //KC
	int f1,f2,nf;                                                //KC
	public:                                                //KC
		series();                                                //KC
		void displayseries(int );                                                //KC
		                                                //KC
};                                                //KC
                                                //KC
series::series()                                                //KC
{                                                //KC
	f1=0;                                                //KC
	f2=1;                                                //KC
}                                                //KC
void series::displayseries(int n)                                                //KC
{                                                //KC
	int i;                                                //KC
	for(i=1;i<=n;i++)                                                //KC
	{                                                //KC
		cout<<f1<<endl;                                                //KC
		nf=f1+f2;                                                //KC
		f1=f2;                                                //KC
		f2=nf;                                                //KC
	}                                                //KC
}                                                //KC
                                                //KC
int main()                                                //KC
{                                                //KC
	int n;                                                //KC
	cout<<"enter how much long u want series";                                                //KC
	cin>>n;                                                //KC
	series s1;                                                //KC
	s1.displayseries(n);                                                //KC
	return 0;	                                                //KC
}                                                //KC
//Kshitij Chitnis                                                //KC