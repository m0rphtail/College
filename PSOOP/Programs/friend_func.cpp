/* Write a program to access the private data of a class through friend function*/                                                //KC
                                                //KC
                                                //KC
#include<iostream>                                                //KC
using namespace std;                                                //KC
class student                                                //KC
{                                                //KC
private:                                                //KC
	int rollno;                                                //KC
public:                                                //KC
	void display();                                                //KC
	friend void accept(student s);                                                //KC
};                                                //KC
void student::display()                                                //KC
{                                                //KC
	cout << "\nEnter roll number: ";                                                //KC
	cin >> rollno;                                                //KC
	                                                //KC
}                                                //KC
void accept(student s)                                                //KC
{                                                //KC
	cout << "\nRoll number is: " << s.rollno;                                                //KC
                                                //KC
}                                                //KC
int main()                                                //KC
{                                                //KC
	student stud;                                                //KC
	stud.display();                                                //KC
	accept(stud);                                                //KC
	return 0;                                                //KC
}//Kshitij Chitnis                                                //KC