//Number of columns and rows = 10, accuracy = 0.001, difference = 3.32206
//Number of columns and rows = 20, accuracy = 0.00001, difference = 0.178096
//Number of columns and rows = 50, accuracy = 0.00000001, difference =  1177.46
//Anzhelika Ivanovna, this programm doesn't work correctly for big numbers, but I can't find the mistake. I promise that I find it and correct the mistake, but now I don't see it
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
