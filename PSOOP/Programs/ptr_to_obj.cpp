#include<iostream>
using namespace std;
class store
{
private:
	int code;
	float price;
public:
	void accept();
	void display();

};
void store::accept()
{
	cout << "\nEnter code & price: ";
	cin >> code >> price;

}
void store::display()
{
	cout << "\nCode & Price is: " << code << price;
}
int main()
{
	int i;
	store* s = new store[3];
	for (i = 0; i < 3; i++)
	{
		s->accept();
		s->display();
		s++;
	}
	return 0;
}//Kshitij Chitnis
