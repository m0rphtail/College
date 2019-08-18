#include<iostream>
using namespace std;
class incr
{
	int x;
	public:
		incr()
		{
			x=1;
		}
		void display();
		void operator++();
		void operator++(int);
		
};
void incr::display()
{
	cout<<x<<endl;
		
}
void incr::operator++()
{
	++x;
}
void incr::operator++(int)
{
	x++;
}
int main()
{
	incr i1;
	i1.display();
	++i1;
	i1.display();
	i1++;
	i1.display();
	return 0;
}

