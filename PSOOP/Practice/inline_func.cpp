#include<iostream>
using namespace std;

inline void data(int x)
{
	if(x%2==0)
		cout<<x<<" is even\n";
	else
		cout<<x<<" is odd";
}

int main()
{
	data(10);
	data(5);
	return 0;
}
//Kshitij Chitnis
