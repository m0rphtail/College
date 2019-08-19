/* Write a program to show how the class first has generated its friendship to the class second to access private data 
of class first through public member function of class second*/


#include<iostream>
using namespace std;
class first
{
	friend class second;
private:
	int x;
public:
	void accept()
	{
		cout << "\nEnter value of x: ";
		cin >> x;
	}

};
class second
{

public:
	void display(first F);

};
void second::display(first F)
{
	cout << "\nValue of x is: " << F.x;

}

int main()
{
	first f1;
	second s1;
	f1.accept();
	s1.display(f1);
	return 0;
}
//Kshitij Chitnis