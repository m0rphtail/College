#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int main()
{
char x='k';
FILE *fp=fopen("a.txt,"w");
putc(x,fp);
return 0;
}
//Kshitij Chitnis
