#pragma once

namespace Matrix
{
	typedef double(*value)(int, int);

	typedef int(*Key)(int, int, int);

	int* inputDimensions(int);

	int** allocateMemoryNotRectandular(int, int*);

	void inputNotRectandularMatrix(int**, int, int*);

	void displayNotRectandularMatrix(int** matrix, int rows, int* dimensions, char*);

	void displayArray(int*, int, char*);

	void displayNotRectandularMatrixAdd(int** matrix, int rows, int* dimensions, char*);

	int* InputRowsToSort(int rows);

	void sortMatrix(int**, int, int*, int*);

	int inputNumber();

	int differenceOfRemainders(int, int, int);

	void mergeSort(int*, int, Key);

	void merge(int*, int*, int*, int, int, Key);

	int* allocateMemory(int);

	int* deleteElementsInArray(int*, int&);

	int** deleteElementsInMatrix(int**, int, int*, int*);
}
