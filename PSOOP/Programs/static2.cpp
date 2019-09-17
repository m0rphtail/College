#include<iostream>
using namespace std;

static int count;
int x;
void value(int num){
++count;
x=num;
}

int main(){
value(10);
value(100);
value(1000);
cout<<"count: "<<count<<"\n";
return 0;
}
