#include<iostream>
using namespace std;
class value
{
private:
	int x;
public:
	value()
	{
		x = 0;
	}
	void *operator new(size_t size)
	{
		return malloc(size);
	}
	void operator delete (void* p)
	{
		cout << "\nOverloaded delete operator.";
		free (p);

	}


};
int main()
{
	value* v = new value;
	delete v;
	return 0;
}//Kshitij Chitnis
