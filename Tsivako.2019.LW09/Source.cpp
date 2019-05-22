#include<iostream>
#include<fstream>
#include"MatrixNotRectandular.h"

using namespace std;
using namespace Matrix;

int main()
{
	const int N = 100;
	char fileName[] = "C:/Users/Lenovo/Documents/vs/Not_rectangular_Matrix_files/test.txt";

	cout << "Enter the number of rows of the matrix: ";
	int rows = inputNumber();
	int* dimensions = inputDimensions(rows);
	int** matrix = allocateMemoryNotRectandular(rows, dimensions);

	inputNotRectandularMatrix(matrix, rows, dimensions);
	system("cls");
	displayNotRectandularMatrix(matrix, rows, dimensions, fileName);

	int* rowsToSort = InputRowsToSort(rows);

	int a, b;
	cout << "Enter the first dividor: ";
	a = inputNumber();
	cout << "Enter the second dividor: ";
	b = inputNumber();
	cout << endl;

	sortMatrix(matrix, rows, dimensions, rowsToSort);
	matrix = deleteElementsInMatrix(matrix, rows, dimensions, rowsToSort);
	displayNotRectandularMatrixAdd(matrix, rows, dimensions, fileName);

	system("pause");

	return 0;
}