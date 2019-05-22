#include<iostream>
#include"MatrixNotRectandular.h"

using namespace std;
using namespace Matrix;

int main()
{
	cout << "Enter the number of rows of the matrix: ";
	int rows = inputNumber();
	int* dimensions = inputDimensions(rows);
	int** matrix = allocateMemoryNotRectandular(rows, dimensions);
	
	inputNotRectandularMatrix(matrix, rows, dimensions);
	system("cls");
	cout << "Not rectandular matrix: " << endl;
	displayNotRectandularMatrix(matrix, rows, dimensions);
	
	int* rowsToSort = InputRowsToSort(rows);

	int a, b;
	cout << "Enter the first dividor: ";
	a = inputNumber();
	cout << "Enter the second dividor: ";
	b = inputNumber();
	cout << endl;
	
	sortMatrix(matrix, rows, dimensions, rowsToSort);
	matrix = deleteElementsInMatrix(matrix, rows, dimensions, rowsToSort);
	cout << "Sorted matrix without repeating elements: " << endl;
	displayNotRectandularMatrix(matrix, rows, dimensions);

	system("pause");

	return 0;
}