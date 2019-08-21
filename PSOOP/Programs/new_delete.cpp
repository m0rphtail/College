#include<iostream>                                                //KC
using namespace std;                                                //KC
class value                                                //KC
{                                                //KC
private:                                                //KC
	int x;                                                //KC
public:                                                //KC
	value()                                                //KC
	{                                                //KC
		x = 0;                                                //KC
	}                                                //KC
	void *operator new(size_t size)                                                //KC
	{                                                //KC
		return malloc(size);                                                //KC
	}                                                //KC
	void operator delete (void* p)                                                //KC
	{                                                //KC
		cout << "\nOverloaded delete operator.";                                                //KC
		free (p);                                                //KC
                                                //KC
	}                                                //KC
                                                //KC
                                                //KC
};                                                //KC
int main()                                                //KC
{                                                //KC
	value* v = new value;                                                //KC
	delete v;                                                //KC
	return 0;                                                //KC
}//Kshitij Chitnis                                                //KC