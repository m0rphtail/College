#include<iostream>
using namespace std;
class first
{
	friend class second;
	private:
		int x;
	public:
	void accept(); 
};
class second
{
	private:
		int y;
	public:
		void display(first f);
		
};
void first::accept()
{
	cout<<"enter value of x";
	cin>>x;
}
void second::display(first f)
{
	cout<<"value of x is"<<f.x;
	
}
int main()
{
	first o1;
	o1.accept();
	second o2;
	o2.display(o1);
	return 0;
}
//Kshitij Chitnis