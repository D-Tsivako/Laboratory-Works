#pragma once

namespace Matrix
{
	typedef double(*value)(int, int);
	typedef double(*cosTaylor)(double, double);

	int** allocateMemory(int, int);

	double** allocateMemoryDouble(int, int);

	void inputMatrix(int**, int, int);

	void inputMatrix(double**, int, int);

	void inputMatrix(double**, int, int, value);

	void displayMatrix(int**, int, int);

	void displayMatrix(double**, int, int);

	void randomArray(int**, int, int);

	double formula(int, int);

	double comparisonMatrix(double**, double**, int, int);

	void inputMatrix(double**, int, int, double, cosTaylor);

	int enterNumber();
	
	double enterAccuracy();

	double ñosX(double, double);
}



