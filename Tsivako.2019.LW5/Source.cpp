#include <iostream>
#include "Complex.h"

using namespace std;

int inputNumber();

int main()
{
	Complex complex1, complex2;

	cout << "Enter real part of the first number: ";
	int a = inputNumber();
	cout << "Enter imaginary part of the first number: ";
	int b = inputNumber();
	
	complex1.setComplex(a, b);

	cout << "Enter real part of the second number: ";
	int c = inputNumber();
	cout << "Enter imaginary part of the second number: ";
	int d = inputNumber();
	
	complex2.setComplex(c, d);
	
	cout << complex1;
	cout << complex2;
	
	Complex complex3;
	complex3 = complex1 / complex2;
	cout << complex3;

	system("pause");
}

int inputNumber()
{
	int n;
	cout << "Enter number: ";
	cin >> n;

	return n;
}