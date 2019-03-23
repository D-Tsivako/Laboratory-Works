#include<iostream>
#include"MatrixNotRectandular.h"

using namespace std;

#pragma region allocate
int* Matrix::allocateMemory(int n)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Count of array elements can not be less or equal 0.");
	}

	int* array = new int[n];

	return array;
}

int** Matrix::allocateMemoryNotRectandular(int rows, int* dimensions)
{
	if (rows <= 0)
	{
		throw invalid_argument("Number of rows in a matrix can not be less or equal to 0.");
	}
	if (dimensions == nullptr)
	{
		throw std::invalid_argument("Dimension array can not be null.");
	}

	int** matrix = new int*[rows];

	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[dimensions[i]];
	}

	return matrix;
}
#pragma endregion

#pragma region inputs
int* Matrix::inputDimensions(int rows)
{
	if (rows <= 0)
	{
		throw invalid_argument("Number of rows in a matrix can not be less or equal to 0.");
	}

	int* dimensions = new int[rows];

	if (dimensions == nullptr)
	{
		throw invalid_argument("The dimension of an array can not be 0.");
	}

	cout << "Enter number of elements in a row..." << endl;

	for (int i = 0; i < rows; i++)
	{
		cout << "Row " << i + 1 << ": ";
		cin >> dimensions[i];

		if (dimensions[i] <= 0)
		{
			throw invalid_argument("Number of elements in a row can not be less than 0.");
		}
	}

	return dimensions;
}

void Matrix::inputNotRectandularMatrix(int** matrix, int rows, int* dimensions)
{
	for (int i = 0; i < rows; i++)
	{
		cout << "Enter " << i + 1 << " row: " << endl;

		for (int j = 0; j < dimensions[i]; j++)
		{
			cout << "a[" << j + 1 << "]= ";
			cin >> *(*(matrix + i) + j);
		}
	}
}

int* Matrix::InputRowsToSort(int rows)
{
	if (rows <= 0)
	{
		throw invalid_argument("Number of rows in a matrix can not be less or equal to 0.");
	}

	cout << "Enter number of the rows to sort: ";
	int numberOfRows;
	cin >> numberOfRows;

	if (numberOfRows <= 0)
	{
		throw invalid_argument("Number of rows in a matrix can not be less or equal to 0.");
	}

	int* rowsToSort = new int[numberOfRows];

	if (rowsToSort == nullptr)
	{
		throw std::invalid_argument("Array can not be null.");
	}

	cout << "Enter indexes of the rows to sort(beginning with 1)" << endl;

	for (int i = 0; i < numberOfRows; i++)
	{
		cout << "Inputting the " << i + 1 << " index: ";
		int currentIndex;
		cin >> currentIndex;

		if (currentIndex <= 0)
		{
			throw std::invalid_argument("Index can not be less than 1.");
		}

		rowsToSort[i] = currentIndex - 1;
	}

	return rowsToSort;
}

int Matrix::inputNumber()
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
#pragma endregion

#pragma region display

void Matrix::displayNotRectandularMatrix(int** matrix, int rows, int* dimensions)
{
	if (matrix == nullptr)
	{
		throw std::invalid_argument("Matrix can not be null.");
	}

	if (rows <= 0)
	{
		throw invalid_argument("Number of rows in a matrix can not be less or equal to 0.");
	}

	if (dimensions == nullptr)
	{
		throw std::invalid_argument("Dimension array can not be null.");
	}

	for (int i = 0; i < rows; i++)
	{
		displayArray(matrix[i], dimensions[i]);
	}
}

void Matrix::displayArray(int* array, int n)
{
	if (array == nullptr)
	{
		throw std::invalid_argument("Array can not be null.");
	}

	if (n <= 0)
	{
		throw std::invalid_argument("Count of array elements can not be less or equal 0.");
	}

	for (int* p = array; p < array + n; p++)
	{
		std::cout << *p << " ";
	}

	cout << endl;
}
#pragma endregion

#pragma region sorts
void Matrix::sortMatrix(int** matrix, int rows, int* dimensions, int* rowsToSort)
{
	if (rows <= 0)
	{
		throw invalid_argument("Number of rows in a matrix can not be less or equal to 0.");
	}

	if (matrix == nullptr)
	{
		throw std::invalid_argument("Matrix can not be null.");
	}
	if (dimensions == nullptr)
	{
		throw std::invalid_argument("Array can not be null.");
	}
	if (rowsToSort == nullptr)
	{
		throw std::invalid_argument("Array can not be null.");
	}

	for (int i = 0, j = 0; i < rows; i++)
	{
		if (i == rowsToSort[j])
		{
			mergeSort(matrix[i], dimensions[i], differenceOfRemainders);
			j++;
		}
	}
}

void Matrix::mergeSort(int* array, int n, Key key)
{
	if (n > 1)
	{
		int p = n / 2 + n % 2;
		int q = n / 2;

		int* left = allocateMemory(p);
		int* right = allocateMemory(q);

		for (int i = 0; i < p; i++)
		{
			left[i] = array[i];
		}
		for (int j = 0; j < q; j++)
		{
			right[j] = array[p + j];
		}
		mergeSort(left, p, key);
		mergeSort(right, q, key);
		merge(array, left, right, p, q, key);
	}
	else
	{
		return;
	}
}

void Matrix::merge(int* array, int* left, int* right, int p, int q, Key key)
{
	int j = 0, k = 0;

	for (int i = 0; i < p + q; i++)
	{
		if (j == p)
		{
			array[i] = right[k];
			k++;
		}
		else if (k == q)
		{
			array[i] = left[j];
			j++;
		}
		else if (Key(left[j]) > Key(right[k]))
		{
			array[i] = left[j];
			j++;
		}
		else
		{
			array[i] = right[k];
			k++;
		}
	}
}
#pragma endregion

int Matrix::differenceOfRemainders(int number, int a, int b)
{
	int remA, remB, dif;

	remA = number / a;
	remB = number / b;

	if (remA > remB)
	{
		dif = remA - remB;
	}
	else
	{
		dif = remB - remA;
	}

	return dif;
}

#pragma region deleteElements
int* Matrix::deleteElementsInArray(int* array, int& n)
{
	if (array == nullptr)
	{
		throw std::invalid_argument("Array can not be null.");
	}

	if (n <= 0)
	{
		throw std::invalid_argument("Count of array elements can not be less or equal 0.");
	}

	int length = 0;
	
	for (int i = 0; i < n - 1 - length; i++)
	{
		if (array[i] == array[i + 1])
		{
			for (int j = i+1; j < n - length; j++)
			{
				array[j] = array[j + 1];
			}

			i--;
			length++;
		}
	}

	int* newArray = allocateMemory(n - length);

	for (int i = 0; i < n - length; i++)
	{
		newArray[i] = array[i];
	}

	int number = n - length;
	n = number;

	return newArray;
}

int** Matrix::deleteElementsInMatrix(int** matrix, int rows, int* dimensions, int* rowsToSort)
{
	if (matrix == nullptr)
	{
		throw std::invalid_argument("Matrix can not be null.");
	}
	if (rows <= 0)
	{
		throw invalid_argument("Number of rows in a matrix can not be less or equal to 0.");
	}
	if (dimensions == nullptr)
	{
		throw std::invalid_argument("Dimension of an array can not be null.");
	}
	if (rowsToSort == nullptr)
	{
		throw std::invalid_argument("Dimension of an array can not be null.");
	}

	for (int i = 0, j = 0; i < rows; i++)
	{
		if (i == rowsToSort[j])
		{
			matrix[i] = deleteElementsInArray(matrix[i], dimensions[i]);
			j++;
		}
	}

	return matrix;
}
#pragma endregion
