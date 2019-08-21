#include<iostream>                                                //KC
using namespace std;                                                //KC
class UnaryFriend                                                //KC
{                                                //KC
     int a=10;                                                //KC
     int b=20;                                                //KC
     int c=30;                                                //KC
     public:                                                //KC
         void getvalues()                                                //KC
         {                                                //KC
              cout<<"Values of A, B & C\n";                                                //KC
              cout<<a<<"\n"<<b<<"\n"<<c<<"\n"<<endl;                                                //KC
         }                                                //KC
         void show()                                                //KC
         {                                                //KC
              cout<<a<<"\n"<<b<<"\n"<<c<<"\n"<<endl;                                                //KC
         }                                                //KC
         void friend operator-(UnaryFriend &x);      //Pass by reference                                                //KC
};                                                //KC
void operator-(UnaryFriend &x)                                                //KC
{                                                //KC
     x.a = -x.a;     //Object name must be used as it is a friend function                                                //KC
     x.b = -x.b;                                                //KC
     x.c = -x.c;                                                //KC
}                                                //KC
int main()                                                //KC
{                                                //KC
     UnaryFriend x1;                                                //KC
     x1.getvalues();                                                //KC
     cout<<"Before Overloading\n";                                                //KC
     x1.show();                                                //KC
     cout<<"After Overloading \n";                                                //KC
     -x1;                                                //KC
      x1.show();                                                //KC
      return 0;                                                //KC
}//Kshitij Chitnis                                                //KC
