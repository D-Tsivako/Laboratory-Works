#include<iostream>
#include"Matrix.h"

using namespace std;
using namespace Matrix;


int main()
{
	cout << "Enter the columns and strings of the matrix: ";
	int n = enterNumber();
	system("cls");

	double** matrixA = allocateMemoryDouble(n, n);
	double** matrixB = allocateMemoryDouble(n, n);

	cout << "Enter the accuracy: ";
	double lim = enterAccuracy();
	system("cls");

	inputMatrix(matrixA, n, n, lim, ñosX);
	cout << "Taylor series: " << endl;
	displayMatrix(matrixA, n, n);

	inputMatrix(matrixB, n, n, formula);
	cout << "Inline functions: " << endl;
	displayMatrix(matrixB, n, n);

	cout << "The result of the matrix comparison: " << comparisonMatrix(matrixA, matrixB, n, n) << endl;

	system("pause");

	return 0;
}