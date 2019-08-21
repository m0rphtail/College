#include<iostream>                                                //KC
                                                //KC
using namespace std;                                                //KC
                                                //KC
class complex 	//class definition of complex number                                                //KC
{                                                //KC
	float real;                                                //KC
	float imaginary;                                                //KC
	                                                //KC
	public:		                                                //KC
	complex()	//initializing a constructor named complex                                                //KC
	{                                                //KC
		real=0;                                                //KC
		imaginary=0;                                                //KC
	}                                                //KC
	complex(float a, float b)	//parameterized constuctor                                                //KC
	{                                                //KC
		real=a;                                                //KC
		imaginary=b;                                                //KC
	}                                                //KC
                                                    //KC
	void putData(complex &number);                                                //KC
	                                                //KC
	complex friend operator + (complex a, complex b);	//prototyping a friend function                                                //KC
	complex friend operator - (complex a, complex b);	//prototyping a friend function                                                //KC
	                                                //KC
	complex operator * (complex &number)		//function overloading                                                //KC
	{                                                //KC
		complex product;			//initializing object                                                //KC
		product.real = (real*number.real) - (imaginary*number.imaginary);	//calculating multiplication                                                //KC
		product.imaginary = (real*number.imaginary) + (number.real*imaginary);                                                //KC
		return product;                                                //KC
	}                                                //KC
	                                                //KC
	complex operator / (complex &number)		//function overloading                                                //KC
	{                                                //KC
		complex division;			//initializing object                                                //KC
        float mod=(number.real*number.real + number.imaginary*number.imaginary);	//calculating division                                                //KC
        division.real = ((real*number.real) + (imaginary*number.imaginary))/(mod);                                                //KC
        division.imaginary = ((imaginary*number.real) - (real*number.imaginary))/(mod);                                                //KC
		return division;                                                //KC
	}                                                //KC
};                                                //KC
                                                //KC
int main()                                                //KC
{                                                //KC
	complex answer;                                                //KC
	int choice;                                                //KC
	float Re, Im;                                                //KC
	char repeat='y';	//initializing value of repeat to 'y', as initially it is y, the while loop will run once                                                //KC
	                                                //KC
	while(repeat=='y' || repeat=='Y')	//condition to check to continue program                                                //KC
	{                                                //KC
		cout << "First number\nEnter real part: ";                                                //KC
		cin >> Re;					                                                //KC
		cout << "Enter imaginary part: ";	                                                //KC
		cin >> Im;	                                                //KC
		complex number1(Re, Im);				//inputing the numbers                                                //KC
		                                                //KC
		cout << "\nSecond number\nEnter real part: ";                                                //KC
		cin >> Re;                                                //KC
		cout << "Enter imaginary part: ";                                                //KC
		cin >> Im;                                                //KC
		complex number2(Re, Im);                                                //KC
		                                                //KC
		cout << "\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\nSelect the operation: ";	//menu                                                //KC
		cin >> choice;                                                //KC
		switch(choice)                                                //KC
		{                                                //KC
			case 1:                                                //KC
				{                                                //KC
					answer = number1 + number2;                                                //KC
					answer.putData(answer);                                                //KC
					break;                                                //KC
				}                                                //KC
			case 2:                                                //KC
				{                                                //KC
					answer = number1 - number2;                                                //KC
					answer.putData(answer);                                                //KC
					break;                                                //KC
				}                                                //KC
			case 3:                                                //KC
				{                                                //KC
					answer = number1 * number2;                                                //KC
					answer.putData(answer);                                                //KC
					break;                                                //KC
				}                                                //KC
			case 4:                                                //KC
				{                                                //KC
					answer = number1 / number2;                                                //KC
					answer.putData(answer);                                                //KC
					break;                                                //KC
				}                                                //KC
			default:                                                //KC
				{                                                //KC
					cout << "Invalid selection! Select a number between 1-4";                                                //KC
					break;                                                //KC
				}                                                //KC
		}                                                //KC
		cout << "\nDo you want to perform another operation? (y/n)";                                                //KC
		cin >> repeat;                                                //KC
	}                                                //KC
	                                                //KC
	return 0;                                                //KC
}                                                //KC
                                                //KC
void complex::putData(complex &number)		//function to display the answer in correct format                                                //KC
{                                                //KC
	if(number.imaginary>=0)                                                //KC
		cout << "\n" << real << "+" << imaginary << "i\n";                                                //KC
	else                                                //KC
		cout << "\n" << real << imaginary << "i\n";                                                //KC
}                                                //KC
                                                //KC
complex operator + (complex a, complex b) 	//calculating addition                                                //KC
{                                                //KC
	complex sum;		//initializing object                                                //KC
	sum.real = a.real + b.real;                                                //KC
	sum.imaginary = a.imaginary + b.imaginary;                                                //KC
	return sum;                                                //KC
}                                                //KC
                                                //KC
complex operator - (complex a, complex b)	//calculating subtraction                                                //KC
{                                                //KC
	complex diff;		//initializing object                                                //KC
	diff.real = a.real - b.real;                                                //KC
	diff.imaginary = a.imaginary - b.imaginary;                                                //KC
	return diff;                                                //KC
}//Kshitij Chitnis                                                //KC
