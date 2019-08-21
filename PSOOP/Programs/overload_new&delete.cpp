                                                //KC
// CPP program to demonstrate                                                  //KC
// Overloading new and delete operator                                                  //KC
// for a specific class                                                 //KC
#include<iostream>                                                 //KC
#include<stdlib.h>                                                 //KC
                                                  //KC
using namespace std;                                                 //KC
class student                                                 //KC
{                                                 //KC
    string name;                                                 //KC
    int age;                                                 //KC
public:                                                 //KC
    student()                                                 //KC
    {                                                 //KC
        cout<< "Constructor is called\n" ;                                                  //KC
    }                                                 //KC
    student(string name, int age)                                                 //KC
    {                                                 //KC
        this->name = name;                                                 //KC
        this->age = age;                                                 //KC
    }                                                 //KC
    void display()                                                 //KC
    {                                                 //KC
        cout<< "Name:" << name << endl;                                                 //KC
        cout<< "Age:" << age << endl;                                                 //KC
    }                                                 //KC
    void * operator new(size_t size)                                                 //KC
    {                                                 //KC
        cout<< "Overloading new operator with size: " << size << endl;                                                 //KC
        void * p = ::new student();                                                  //KC
        //void * p = malloc(size); will also work fine                                                 //KC
                                                      //KC
        return p;                                                 //KC
    }                                                 //KC
                                                  //KC
    void operator delete(void * p)                                                 //KC
    {                                                 //KC
        cout<< "Overloading delete operator " << endl;                                                 //KC
        free(p);                                                 //KC
    }                                                 //KC
};                                                 //KC
                                                  //KC
int main()                                                 //KC
{                                                 //KC
    student * p = new student("Yash", 24);                                                 //KC
                                                  //KC
    p->display();                                                 //KC
    delete p;                                                 //KC
}                                                 //KC
//Kshitij Chitnis                                                //KC
