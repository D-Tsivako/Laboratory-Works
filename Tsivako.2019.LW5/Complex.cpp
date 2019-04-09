#include "Complex.h"
#include <iostream>

using namespace std;

Complex::Complex(double real, double imaginary)
{
	setComplex(real, imaginary);
}

void Complex::setRealPart(double a)
{
	real = a;
}

void Complex::setImaginaryPart(double b)
{
	imaginary = b;
}

void Complex::setComplex(double a, double b)
{
	setRealPart(a);
	setImaginaryPart(b);
}

double Complex::getRealPart() const
{
	return real;
}

double Complex::getImaginaryPart() const
{
	return imaginary;
}

Complex::~Complex()
{
	cout << "I'm dead!";
}

Complex Complex::conjugate()
{
	imaginary = -imaginary;
	Complex conjugate;
	conjugate.setComplex(real, imaginary);
	return conjugate;
}

Complex Complex::operator+(const Complex& complex)
{
	return Complex(complex.getRealPart() + this->getRealPart(), complex.getImaginaryPart() + this->getImaginaryPart());
}

Complex Complex::operator-(const Complex& complex)
{
	return Complex(complex.getRealPart() - this->getRealPart(), complex.getImaginaryPart() - this->getImaginaryPart());
}

Complex Complex::operator-()
{
	return Complex(-(this->getRealPart()), -(this->getImaginaryPart()));
}

Complex Complex::operator*(const Complex& complex)
{
	return Complex(complex.getRealPart() * this->getRealPart() - complex.getImaginaryPart() * this->getImaginaryPart(), complex.getRealPart() * this->getImaginaryPart() + this->getRealPart() * complex.getImaginaryPart());
}

Complex Complex::operator/(const Complex& complex)
{
	double rFirst = complex.getRealPart(), rSecond = this->getRealPart(), cFirst = complex.getImaginaryPart(), cSecond = this->getImaginaryPart();
	return Complex((rFirst * rSecond + cFirst * cSecond) / (pow(rSecond, 2) + pow(cSecond, 2)), ((rSecond * cFirst - rFirst * cSecond) / (pow(rSecond, 2) + pow(cSecond, 2))));
}

ostream& operator<<(ostream& stream, const Complex& complex)
{
	if (complex.getRealPart() != 0 && complex.getImaginaryPart() > 0)
	{
		return stream << complex.getRealPart() << " + " << complex.getImaginaryPart() << "i" << endl;
	}
	if (complex.getRealPart() != 0 && complex.getImaginaryPart() < 0)
	{
		return stream << complex.getRealPart() << " - " << fabs(complex.getImaginaryPart()) << "i" << endl;
	}
	if (complex.getRealPart() == 0)
	{
		return stream << complex.getImaginaryPart() << "i" << endl;
	}
	if (complex.getImaginaryPart() == 0)
	{
		return stream << complex.getRealPart() << endl;
	}
	if (complex.getRealPart() == 0 && complex.getImaginaryPart() == 0)
	{
		return stream << 0;
	}
}

istream& operator>>(istream & stream, Complex& complex)
{
	cout << "Input real part: ";
	stream >> complex.real;
	cout << "Input imaginary part: ";
	stream >> complex.imaginary;
	return stream;
}