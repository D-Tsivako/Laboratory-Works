#include<iostream>
#include<fstream>
#include"Matrix.h"

using namespace std;

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

void Matrix::inputMatrix(char* fileName, double** matrix, int n, int m, value arg)
{
	ofstream streamOut(fileName, ios::app);

	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}

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

	streamOut << "\nInline functions: \n";

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = arg(i, j);
			streamOut.width(n);
			streamOut << " " << matrix[i][j];
		}
		streamOut << endl;
	}
	streamOut.close();
}

void Matrix::inputMatrix(char* fileName, double** matrix, int n, int m, double lim, cosTaylor cos)
{
	ofstream streamOut(fileName);

	if (!streamOut.is_open())
	{
		cout << "Cannot open file to write!" << endl;
		system("pause");
		exit(1);
	}

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

	streamOut << "\nTaylor series: \n";

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i != j)
			{
				matrix[i][j] = (pow((i + j), 2) - cos((double)2 * i, lim) + cos((double)2 * j, lim)) / (cos((double)(i + j), lim) + (pow((1 + i), 2)));
				streamOut.width(n);
				streamOut << " " << matrix[i][j];
			}
			else
			{
				matrix[i][j] = i + j;
				streamOut.width(n);
				streamOut << " " << matrix[i][j];
			}
		}
		streamOut << endl;
	}
	streamOut.close();
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

void Matrix::comparisonMatrix(char* fileName, double** matrixA, double** matrixB, int columns, int rows)
{
	ofstream streamOut(fileName, ios::app);

	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}

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
	streamOut << "\nThe result of the matrix comparison: \n";
	streamOut.width(10);
	streamOut << maxDifference;

	streamOut.close();
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

double Matrix::cosX(double x, double lim)
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