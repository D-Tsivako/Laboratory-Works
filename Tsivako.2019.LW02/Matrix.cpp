#include<iostream>
#include"Matrix.h"

using namespace std;

int** Matrix::allocateMemory(int n, int m)
{
	if (n <= 0)
	{
		throw invalid_argument("Count of array elements can not be less or equal 0.");
	}
	if (m <= 0)
	{
		throw invalid_argument("Count of array elements can not be less or equal 0.");
	}

	int** matrix = new int*[n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m];
	}

	return matrix;
}

double** Matrix::allocateMemoryDouble(int n, int m)
{
	if (n <= 0)
	{
		throw invalid_argument("Count of array elements can not be less or equal 0.");
	}

	if (m <= 0)
	{
		throw invalid_argument("Count of array elements can not be less or equal 0.");
	}

	double** matrix = new double*[n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new double[m];
	}

	return matrix;
}


void Matrix::inputMatrix(int** matrix, int n, int m)
{
	if (matrix == nullptr)
	{
		throw invalid_argument("Array can not be null.");
	}

	if (*matrix == nullptr)
	{
		throw invalid_argument("Array can not be null.");
	}

	if (n <= 0)
	{
		throw invalid_argument("Count of array elements can not be less or equal 0.");
	}

	if (m <= 0)
	{
		throw invalid_argument("Count of array elements can not be less or equal 0.");
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "a[" << i << "][" << j << "]= ";
			cin >> matrix[i][j];
		}
	}
}

void Matrix::inputMatrix(double** matrix, int n, int m, value arg)
{
	if (matrix == nullptr)
	{
		throw invalid_argument("Array can not be null.");
	}

	if (*matrix == nullptr)
	{
		throw invalid_argument("Array can not be null.");
	}

	if (n <= 0)
	{
		throw invalid_argument("Count of array elements can not be less or equal 0.");
	}

	if (m <= 0)
	{
		throw invalid_argument("Count of array elements can not be less or equal 0.");
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = arg(i, j);
		}
	}
}

void Matrix::inputMatrix(double** matrix, int n, int m, double lim, cosTaylor cos)
{
	if (matrix == nullptr)
	{
		throw invalid_argument("Array can not be null.");
	}

	if (*matrix == nullptr)
	{
		throw invalid_argument("Array can not be null.");
	}

	if (n <= 0)
	{
		throw invalid_argument("Count of array elements can not be less or equal 0.");
	}

	if (m <= 0)
	{
		throw invalid_argument("Count of array elements can not be less or equal 0.");
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i != j)
			{
				matrix[i][j] = (pow((i + j), 2) - cos((double)2 * i, lim) + cos((double)2 * j, lim)) / (cos((double)(i + j), lim) + (pow((1 + i), 2)));
			}
			else
			{
				matrix[i][j] = i + j;
			}
		}
	}
}

void Matrix::inputMatrix(double** matrix, int n, int m)
{
	if (matrix == nullptr)
	{
		throw invalid_argument("Array can not be null.");
	}

	if (*matrix == nullptr)
	{
		throw invalid_argument("Array can not be null.");
	}

	if (n <= 0)
	{
		throw invalid_argument("Count of array elements can not be less or equal 0.");
	}

	if (m <= 0)
	{
		throw invalid_argument("Count of array elements can not be less or equal 0.");
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "a[" << i << "][" << j << "]= ";
			cin >> matrix[i][j];
		}
	}
}

void Matrix::displayMatrix(int** matrix, int n, int m)
{
	if (matrix == nullptr)
	{
		throw invalid_argument("Array can not be null.");
	}

	if (*matrix == nullptr)
	{
		throw invalid_argument("Array can not be null.");
	}

	if (n <= 0)
	{
		throw invalid_argument("Count of array elements can not be less or equal 0.");
	}

	if (m <= 0)
	{
		throw invalid_argument("Count of array elements can not be less or equal 0.");
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << matrix[i][j] << ' ';
		}

		cout << endl;
	}
}

void Matrix::displayMatrix(double** matrix, int n, int m)
{
	if (matrix == nullptr)
	{
		throw invalid_argument("Array can not be null.");
	}

	if (*matrix == nullptr)
	{
		throw invalid_argument("Array can not be null.");
	}

	if (n <= 0)
	{
		throw invalid_argument("Count of array elements can not be less or equal 0.");
	}

	if (m <= 0)
	{
		throw invalid_argument("Count of array elements can not be less or equal 0.");
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << matrix[i][j] << ' ';
		}

		cout << endl;
	}
}

void Matrix::randomArray(int** matrix, int n, int m)
{
	if (matrix == nullptr)
	{
		throw invalid_argument("Array can not be null.");
	}

	if (*matrix == nullptr)
	{
		throw invalid_argument("Array can not be null.");
	}

	if (n <= 0)
	{
		throw invalid_argument("Count of array elements can not be less or equal 0.");
	}

	if (m <= 0)
	{
		throw invalid_argument("Count of array elements can not be less or equal 0.");
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = rand() % 100;
		}
	}
}

double Matrix::formula(int i, int j)
{
	double result;

	if (i != j)
	{
		result = (pow((i + j), 2) - cos((double)2 * i) + cos((double)2 * j)) / (cos((double)(i + j)) + (pow((1 + i), 2)));
	}
	else
	{
		result = i + j;
	}

	return result;
}

double Matrix::comparisonMatrix(double** matrixA, double** matrixB, int columns, int rows)
{
	if (matrixA == nullptr || matrixB == nullptr)
	{
		throw invalid_argument("Matrix can not be null.");
	}

	if (rows <= 0 || columns <= 0)
	{
		throw invalid_argument("Number of rows and columns in a matrix can not be less or equal to 0.");
	}

	double maxDifference = 0;
	for (int i = 0; i < columns; i++)
	{
		double difference = 0;
		for (int j = 0; j < rows; j++)
		{
			difference = *(*(matrixA + i) + j) - *(*(matrixB + i) + j);
			if (difference > maxDifference)
			{
				maxDifference = difference;
			}
		}
	}

	return maxDifference;
}



int Matrix::enterNumber()
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

double Matrix::enterAccuracy()
{
	double lim;
	while (true)
	{
		cout << "Enter accuracy > 0 : ";
		cin >> lim;

		if (lim > 0)
		{
			return lim;
		}
	}
}

double Matrix::ñosX(double x, double lim)
{
	if (lim < 0 || lim >1)
	{
		throw out_of_range("Accuracy can not be less than 0 or more than 1");
	}
	
	const double PI = 3.14159265358979323846;
	x = fmod(x, PI * 2);
	double sum = 0, term = 1;
	int i = 1;

	while (abs(term) > lim)
	{
		sum += term;
		term *= -x * x / (2 * i - 1) / (2 * i);
		i++;
	}
	
	return sum;
}