#include<iostream>                                                //KC
using namespace std;                                                //KC
class first                                                //KC
{                                                //KC
	friend class second;                                                //KC
	private:                                                //KC
		int x;                                                //KC
	public:                                                //KC
	void accept();                                                 //KC
};                                                //KC
class second                                                //KC
{                                                //KC
	private:                                                //KC
		int y;                                                //KC
	public:                                                //KC
		void display(first f);                                                //KC
		                                                //KC
};                                                //KC
void first::accept()                                                //KC
{                                                //KC
	cout<<"enter value of x";                                                //KC
	cin>>x;                                                //KC
}                                                //KC
void second::display(first f)                                                //KC
{                                                //KC
	cout<<"value of x is"<<f.x;                                                //KC
	                                                //KC
}                                                //KC
int main()                                                //KC
{                                                //KC
	first o1;                                                //KC
	o1.accept();                                                //KC
	second o2;                                                //KC
	o2.display(o1);                                                //KC
	return 0;                                                //KC
}                                                //KC
//Kshitij Chitnis                                                //KC