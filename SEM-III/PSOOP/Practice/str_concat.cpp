#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	const char* s1, * s2, * s3;
	int i = 0;
	int l1, l2;
	s1 = new char[10];
	s2 = new char[10];
	s3 = new char[10];
	s1 = "abcd";
	s2 = "fghi";
	l1 = strlen(s1);
	l2 = strlen(s2);
	while (s1[i] != '\0')
	{
		*(s3 + i) = *(s1 + i);
		i++;

	}
	i = 0;
	while (s2[i] <= l2)
	{
		*(s3 + i + l1) = *(s2 + i);
		i++;

	}
	cout << *s3;
	return 0;
	

}//Kshitij Chitnis
