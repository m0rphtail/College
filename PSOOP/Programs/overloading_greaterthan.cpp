/* Write a program to overload greater than to comapre 2 classes of objects*/                                                //KC
                                                //KC
#include<iostream>                                                //KC
using namespace std;                                                //KC
class greater                                                //KC
{                                                //KC
	int num;                                                //KC
public:                                                //KC
	 greater()                                                //KC
	{                                                //KC
		num=0;                                                //KC
	}                                                //KC
	 greater(int x)                                                //KC
	{                                                //KC
		 num = x;                                                //KC
	}                                                //KC
	 int operator >(greater obj)                                                //KC
                                                //KC
	 {                                                //KC
		 return ((greater) > obj.value);                                                //KC
	 }                                                //KC
	 void display()                                                //KC
	 {                                                //KC
		 cout << "\nValue of number: " << num;                                                //KC
		                                                //KC
	 }                                                //KC
};                                                //KC
int main()                                                //KC
{                                                //KC
	greater g1,g2;                                                //KC
	g1(20);                                                //KC
	g2(200);                                                //KC
	g1.display();                                                //KC
	g2.display();                                                //KC
	g1 > g2;                                                //KC
	cout << g1 > g2;                                                //KC
                                                //KC
                                                //KC
}//Kshitij Chitnis                                                //KC