#pragma once
#include <iostream>

using namespace std;

class Complex
{
	friend ostream& operator<<(ostream &, const Complex&);
	friend istream& operator>>(istream &, Complex&);
public:
	Complex() : Complex(1, 1) {}
	Complex(double, double);
	
	double getRealPart() const;
	double getImaginaryPart() const;
	void setComplex(double, double);

	Complex conjugate();
	Complex operator+(const Complex&);
	Complex operator-(const Complex&);
	Complex operator-();
	Complex operator*(const Complex&);
	Complex operator/(const Complex&);

	~Complex();
private:
	void setRealPart(double);
	void setImaginaryPart(double);
	double real, imaginary;
};