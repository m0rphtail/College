/* Write a program to overload greater than to comapre 2 classes of objects*/

#include<iostream>
using namespace std;
class greater
{
	int num;
public:
	 greater()
	{
		num=0;
	}
	 greater(int x)
	{
		 num = x;
	}
	 int operator >(greater obj)

	 {
		 return ((greater) > obj.value);
	 }
	 void display()
	 {
		 cout << "\nValue of number: " << num;
		
	 }
};
int main()
{
	greater g1,g2;
	g1(20);
	g2(200);
	g1.display();
	g2.display();
	g1 > g2;
	cout << g1 > g2;


}