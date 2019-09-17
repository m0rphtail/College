#include<iostream>
using namespace std;
int num;
class value{
private:
static int count;
int x;
public:
void getdata(int num);
void putdata();
};

void value :: getdata(int num)
{
++count;
x=num;
}
void value :: putdata()
{
cout<<"count value: "<<count;
}
int value :: count;
int main(){
value v1,v2,v3;
v1.putdata();
v2.putdata();
v3.putdata();
v1.getdata(10);
v2.getdata(100);
v3.getdata(1000);
v1.putdata();
v2.putdata();
v3.putdata();
return 0;
}
