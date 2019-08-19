/* Write a program to access the private data of a class through friend function*/


#include<iostream>
using namespace std;
class student
{
private:
	int rollno;
public:
	void display();
	friend void accept(student s);
};
void student::display()
{
	cout << "\nEnter roll number: ";
	cin >> rollno;
	
}
void accept(student s)
{
	cout << "\nRoll number is: " << s.rollno;

}
int main()
{
	student stud;
	stud.display();
	accept(stud);
	return 0;
}//Kshitij Chitnis