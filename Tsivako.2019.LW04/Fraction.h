#pragma once
#include <iostream>

using namespace std;

class Fraction
{
public:
	Fraction()
	{
		intPart = 0;
		numerator = 0;
		denominator = 1;
		sign = 1;
	}

	Fraction(int, int, int, int);

	void setNumerator(int);
	void setDenominator(int);
	void setFraction(int, int);

	int getNumerator() const;
	int getDenominator() const;

	bool equalsTo(Fraction) const;
	int compareTo(Fraction);

	bool isProper() const;
	bool isReducible() const;

	double sumOfFractions(Fraction);
	double multiplicationOfFractions(Fraction);
	double quotientOfFractiobs(Fraction);

	void display() const;

private:
	int numerator;
	int denominator;
	int sign;

	int intPart;
	void GetMixedView();
	void Cancellation();
	void GetIntPart();
};