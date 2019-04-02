#include <iostream>
#include "Fraction.h"

using namespace std;

typedef int(*Key)(Fraction);
typedef bool(*predicate)(int);

Fraction* allocateMemory(int);
void display(Fraction*, int);
void setArrayFraction(Fraction*, int);
int inputNumber();
bool isDenominatorOdd(int);
Fraction findFraction(Fraction*, int, predicate);
void quickSort(Fraction*, int, int, Key);
int partition(Fraction*, int, int, Key);
void swap(Fraction& x, Fraction& y);
int getKey(Fraction);

int main()
{
	cout << "Enter number of fractions: ";
	int n = inputNumber();

	Fraction* fraction = allocateMemory(n);
	setArrayFraction(fraction, n);
	cout << "There is a primary array of fractions: " << endl;
	display(fraction, n);

	quickSort(fraction, 0, n - 1, getKey);
	cout << "There is a sorted array of fractions:" << endl;
	display(fraction, n);

	system("pause");
	return 0;
}

Fraction* allocateMemory(int n)
{
	return new Fraction[n];
}

void display(Fraction* triangles, int n)
{
	for (int i = 0; i < n; i++)
	{
		triangles[i].display();
	}
}

void setArrayFraction(Fraction* fraction, int n)
{
	int numerator, denominator;

	for (int i = 0; i < n; i++)
	{
		cout << "Enter numerator and denominator of fraction as n m: ";
		cin >> numerator >> denominator;
		fraction[i].setFraction(numerator, denominator);
	}

	system("cls");
}

int inputNumber()
{
	int n;
	while (true)
	{
		cin >> n;

		if (n > 0)
		{
			return n;
		}
	}
}

bool isDenominatorOdd(int denominator)
{
	return denominator % 2 != 0 ? true : false;
}

Fraction findFraction(Fraction* fraction, int n, predicate predicate)
{
	for (int i = 0; i < n; i++)
	{
		if (predicate(fraction[i].getDenominator()))
		{
			return fraction[i];
		}
	}
}

void quickSort(Fraction* fraction, int left, int right, Key key)
{
	if (left < right)
	{
		int pivot = partition(fraction, left, right, key);
		quickSort(fraction, left, pivot - 1, key);
		quickSort(fraction, pivot + 1, right, key);
	}
}

int partition(Fraction* fraction, int low, int high, Key key)
{
	Fraction pivot = fraction[high];
	int i = low - 1;

	for (int j = low; j < high; j++)
	{
		if (key(fraction[j]) <= key(pivot))
		{
			i++;
			swap(fraction[i], fraction[j]);
		}
	}

	swap(fraction[i + 1], fraction[high]);

	return i + 1;
}

void swap(Fraction& x, Fraction& y)
{
	Fraction t = x;
	x = y;
	y = t;
}

int getKey(Fraction fraction)
{
	return (fraction.getDenominator() + fraction.getNumerator())/fraction.getNumerator();
}