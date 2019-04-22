#include<iostream>
#include<fstream>
#include"Matrix.h"

using namespace std;
using namespace Matrix;

int main()
{
	const int N = 100;
	char fileName[] = "C:/Users/Lenovo/Documents/vs/Matrix with files/test.txt";

	cout << "Enter the columns and strings of the matrix: ";
	int n = enterNumber();
	system("cls");

	cout << "Enter the accuracy: ";
	double lim = enterAccuracy();
	system("cls");
	
	double** matrixA = allocateMemoryDouble(n, n);
	double** matrixB = allocateMemoryDouble(n, n);

	inputMatrix(fileName, matrixA, n, n, lim, cosX);
	inputMatrix(fileName, matrixB, n, n, formula);

	comparisonMatrix(fileName, matrixA, matrixB, n, n);

	system("pause");

	return 0;
}