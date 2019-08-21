//Copy Constuctor                                                //KC
                                                //KC
                                                //KC
#include<iostream>                                                 //KC
using namespace std;                                                 //KC
                                                  //KC
class Point                                                 //KC
{                                                 //KC
	private:                                                 //KC
	int x, y;                                                 //KC
	public:                                                 //KC
	Point(int x1, int y1) { x = x1; y = y1; }//    Copy constructor                                                 //KC
        Point(const Point &p2) {x = p2.x; y = p2.y; }                                                 //KC
	                                                           //KC
        int getX()            {  return x; }                                                 //KC
        int getY()            {  return y; }                                                 //KC
};                                                 //KC
		                                                                     //KC
int main()                                                 //KC
{                                                 //KC
Point p1(10, 15); // Normal constructor is called here                                                 //KC
Point p2 = p1; // Copy constructor is called here                                                                         //KC
                                                             //KC
cout << "p1.x = " << p1.getX() << ", p1.y = " << p1.getY();                                                 //KC
cout << "\np2.x = " << p2.getX() << ", p2.y = " << p2.getY();                                                 //KC
	                                                                                             //KC
return 0;                                                 //KC
}                                                //KC
			                                                   //KC
	//Kshitij Chitnis                                                //KC
