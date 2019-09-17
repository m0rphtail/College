#include<iostream>
using namespace std;
int main(){
	double *a = new double,*b = new double;
	cout<<"Enetr the numbers:  ";
	cin>>*a>>*b;
	
	double *add = new double;
        double *sub = new double;
	double *mul = new double;
        float *div = new float;

	*add=*a+*b;
	*sub=*a-*b;
	*mul=*a* *b;
	*div=*a/ *b;
 
	cout<<*add<<"\n"<<*sub<<"\n"<<*mul<<"\n"<<*div<<"\n";
	delete add;
	delete sub;
	delete mul;
        delete div;


	return 0;
}
	
