#include<iostream>                                                //KC
#include<string.h>                                                //KC
using namespace std;                                                //KC
int main()                                                //KC
{                                                //KC
	const char* s1, * s2, * s3;                                                //KC
	int i = 0;                                                //KC
	int l1, l2;                                                //KC
	s1 = new char[10];                                                //KC
	s2 = new char[10];                                                //KC
	s3 = new char[10];                                                //KC
	s1 = "abcd";                                                //KC
	s2 = "fghi";                                                //KC
	l1 = strlen(s1);                                                //KC
	l2 = strlen(s2);                                                //KC
	while (s1[i] != '\0')                                                //KC
	{                                                //KC
		*(s3 + i) = *(s1 + i);                                                //KC
		i++;                                                //KC
                                                //KC
	}                                                //KC
	i = 0;                                                //KC
	while (s2[i] <= l2)                                                //KC
	{                                                //KC
		*(s3 + i + l1) = *(s2 + i);                                                //KC
		i++;                                                //KC
                                                //KC
	}                                                //KC
	cout << *s3;                                                //KC
	return 0;                                                //KC
	                                                //KC
                                                //KC
}//Kshitij Chitnis                                                //KC