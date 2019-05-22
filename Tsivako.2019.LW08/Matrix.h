#pragma once

namespace Matrix
{
	typedef double(*value)(int, int);
	typedef double(*cosTaylor)(double, double);

	double** allocateMemoryDouble(int, int);

	void inputMatrix(char* ,double**, int, int, value);

	double formula(int, int);

	void comparisonMatrix(char*, double**, double**, int, int);

	void inputMatrix(char* , double**, int, int, double, cosTaylor);

	int enterNumber();

	double enterAccuracy();

	double cosX(double, double);
}