/* Write a program to display content of pointer using an array of pointers*/


#include<iostream>
using namespace std;
int main()
{
	const char* name[5];
	int i;
	name[0] = "a";
	name[1] = "b";
	name[2] = "c";
	name[3] = "d";
	name[4] = "e";
	name[5] = "f";
	for (i = 0; i <= 5; i++)
	{
		cout << *name[i];
	}
	return 0;
}