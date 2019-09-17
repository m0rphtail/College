#include<iostream>
using namespace std;

static int count;
int x;

static int func(int num){
++count;
x=num;
}

int main(){
func(100);
func(1000);
cout<<count;
return 0;
}
