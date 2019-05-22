#include "Fraction.h"

Fraction::Fraction(int n, int d, int i, int s)
{
	numerator = n;
	denominator = d;
	intPart = i;
	sign = s;
	GetMixedView();
}

#pragma region set
void Fraction::setFraction(int numerator, int denominator)
{
	setNumerator(numerator);
	setDenominator(denominator);
}

void Fraction::setNumerator(int n)
{
	numerator = n;
}

void Fraction::setDenominator(int d)
{
	if (d == 0)
	{
		throw invalid_argument("The denominator can't be equal 0");
	}

	denominator = d;
}
#pragma endregion

#pragma region get
int Fraction::getNumerator() const
{
	return numerator;
}

int Fraction::getDenominator() const
{
	return denominator;
}
#pragma endregion

#pragma region operations
double Fraction::sumOfFractions(Fraction other)
{
	if (getDenominator() == other.getDenominator())
	{
		return ((getNumerator() + other.getNumerator()) / getDenominator());
	}
	else
	{
		return (getNumerator() * other.getDenominator() + other.getNumerator()*getDenominator()) / (getDenominator()*other.getDenominator());
	}
}

double Fraction::multiplicationOfFractions(Fraction other)
{
	return (getNumerator() * other.getNumerator()) / (getDenominator() * other.getDenominator());
}

double Fraction::quotientOfFractiobs(Fraction other)
{
	return (numerator * other.getDenominator()) / (denominator * other.getNumerator());
}

bool Fraction::equalsTo(Fraction other) const
{
	return (getNumerator() == other.getNumerator() && getDenominator() == other.getDenominator()) ? true : false;
}

int Fraction::compareTo(Fraction other)
{
	return (getNumerator()*other.getDenominator() - other.getNumerator()*getDenominator()) < 0 ? -1 : 1;
}
#pragma endregion

#pragma region characteristics
bool Fraction::isProper() const
{
	return numerator < denominator ? true : false;
}

bool Fraction::isReducible() const
{
	int count = (numerator < denominator) ? numerator : denominator;
	int number;

	for (int i = 2; i <= count; i++)
	{
		if (!(numerator%i) && !(denominator%i))
		{
			number = i;
		}
		else
		{
			number = 1;
		}
	}

	return number == 1 ? true : false;
}
#pragma endregion

#pragma region getMixedFraction
void Fraction::GetMixedView()
{
	GetIntPart();
	Cancellation();
}

void Fraction::GetIntPart()
{
	if (numerator >= denominator)
	{
		intPart += (numerator / denominator);
		numerator %= denominator;
	}
}

void Fraction::Cancellation()
{
	if (numerator != 0)
	{
		int d = denominator,
			n = numerator,
			remainder = d % n;

		while (remainder != 0)
		{
			d = n; n = remainder;
			remainder = d % n;
		}

		int nod = n;

		if (nod != 1)
		{
			numerator /= nod; denominator /= nod;
		}
	}
}
#pragma endregion

void Fraction::display() const
{
	cout << getNumerator() <<"/"<< getDenominator() << endl;
}