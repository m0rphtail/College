
#include<iostream>
using namespace std;
class fib{
int f0,f1,f2;
	public:
fib()
{
f0=0;
f1=1;
f2=f0+f1;
}
fib(fib &i)
{
f0=i.f0;
f1=i.f2;
f2=f0+f1;
}
void inc(){
	f0=f1;
	f1=f2;
	f2=f0+f1;
}
void disp(){
cout<<f2<<"\n";
}
};

int main(){
fib number;
cout<<"0\n1\n";
for(int i=0;i<=20;i++)
{
number.disp();
number.inc();
}
return 0;
}
//Kshitij Chitnis
