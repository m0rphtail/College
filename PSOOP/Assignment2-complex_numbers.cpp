#include<iostream>

using namespace std;

class complex 	//class definition of complex number
{
	float real;
	float imaginary;
	
	public:		
	complex()	//initializing a constructor named complex
	{
		real=0;
		imaginary=0;
	}
	complex(float a, float b)	//parameterized constuctor
	{
		real=a;
		imaginary=b;
	}
    
	void putData(complex &number);
	
	complex friend operator + (complex a, complex b);	//prototyping a friend function
	complex friend operator - (complex a, complex b);	//prototyping a friend function
	
	complex operator * (complex &number)		//using a copy constructor
	{
		complex product;			//initializing object
		product.real = (real*number.real) - (imaginary*number.imaginary);	//calculating multiplication
		product.imaginary = (real*number.imaginary) + (number.real*imaginary);
		return product;
	}
	
	complex operator / (complex &number)		//using copy constuctor
	{
		complex division;			//initializing object
        float mod=(number.real*number.real + number.imaginary*number.imaginary);	//calculating division
        division.real = ((real*number.real) + (imaginary*number.imaginary))/(mod);
        division.imaginary = ((imaginary*number.real) - (real*number.imaginary))/(mod);
		return division;
	}
};

int main()
{
	complex answer;
	int choice;
	float Re, Im;
	char repeat='y';	//initializing value of repeat to 'y', as initially it is y, the while loop will run once
	
	while(repeat=='y' || repeat=='Y')	//condition to check to continue program
	{
		cout << "First number\nEnter real part: ";
		cin >> Re;					
		cout << "Enter imaginary part: ";	
		cin >> Im;	
		complex number1(Re, Im);				//inputing the numbers
		
		cout << "\nSecond number\nEnter real part: ";
		cin >> Re;
		cout << "Enter imaginary part: ";
		cin >> Im;
		complex number2(Re, Im);
		
		cout << "\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\nSelect the operation: ";	//menu
		cin >> choice;
		switch(choice)
		{
			case 1:
				{
					answer = number1 + number2;
					answer.putData(answer);
					break;
				}
			case 2:
				{
					answer = number1 - number2;
					answer.putData(answer);
					break;
				}
			case 3:
				{
					answer = number1 * number2;
					answer.putData(answer);
					break;
				}
			case 4:
				{
					answer = number1 / number2;
					answer.putData(answer);
					break;
				}
			default:
				{
					cout << "Invalid selection! Select a number between 1-4";
					break;
				}
		}
		cout << "\nDo you want to perform another operation? (y/n)";
		cin >> repeat;
	}
	
	return 0;
}

void complex::putData(complex &number)		//function to display the answer in correct format
{
	if(number.imaginary>=0)
		cout << "\n" << real << "+" << imaginary << "i\n";
	else
		cout << "\n" << real << imaginary << "i\n";
}

complex operator + (complex a, complex b) 	//calculating addition
{
	complex sum;		//initializing object
	sum.real = a.real + b.real;
	sum.imaginary = a.imaginary + b.imaginary;
	return sum;
}

complex operator - (complex a, complex b)	//calculating subtraction
{
	complex diff;		//initializing object
	diff.real = a.real - b.real;
	diff.imaginary = a.imaginary - b.imaginary;
	return diff;
}
