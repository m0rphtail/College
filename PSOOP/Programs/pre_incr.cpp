#include<iostream>                                                //KC
using namespace std;                                                //KC
class incr                                                //KC
{                                                //KC
	int x;                                                //KC
	public:                                                //KC
		incr()                                                //KC
		{                                                //KC
			x=1;                                                //KC
		}                                                //KC
		void display();                                                //KC
		void operator++();                                                //KC
		void operator++(int);                                                //KC
		                                                //KC
};                                                //KC
void incr::display()                                                //KC
{                                                //KC
	cout<<x<<endl;                                                //KC
		                                                //KC
}                                                //KC
void incr::operator++()                                                //KC
{                                                //KC
	++x;                                                //KC
}                                                //KC
void incr::operator++(int)                                                //KC
{                                                //KC
	x++;                                                //KC
}                                                //KC
int main()                                                //KC
{                                                //KC
	incr i1;                                                //KC
	i1.display();                                                //KC
	++i1;                                                //KC
	i1.display();                                                //KC
	i1++;                                                //KC
	i1.display();                                                //KC
	return 0;                                                //KC
}                                                //KC
                                                //KC
//Kshitij Chitnis                                                //KC