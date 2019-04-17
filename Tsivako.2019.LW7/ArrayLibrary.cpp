#include <iostream>
#include "ArrayLibrary.h"

using namespace std;

int* ArrayExtension::allocateMemory(int n)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Count of array elements can not be less or equal 0.");
	}

	int* array = new int[n];

	return array;
}

double* ArrayExtension::allocateMemoryDouble(int n)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Count of array elements can not be less or equal 0.");
	}

	double* array = new double[n];

	return array;
}

void ArrayExtension::inputArray(int * array, int n)
{
	if (array == nullptr)
	{
		throw std::invalid_argument("Array can not be null.");
	}

	if (n <= 0)
	{
		throw std::invalid_argument("Count of array elements can not be less or equal 0.");
	}

	for (int* p = array, i = 1; p < array + n; p++, i++)
	{
		std::cout << "a[" << i << "] = ";
		std::cin >> *p;
	}
}

void ArrayExtension::inputArray(double * array, int n)
{
	if (array == nullptr)
	{
		throw std::invalid_argument("Array can not be null.");
	}

	if (n <= 0)
	{
		throw std::invalid_argument("Count of array elements can not be less or equal 0.");
	}

	for (double* p = array, i = 1; p < array + n; p++, i++)
	{
		std::cout << "a[" << i << "] = ";
		std::cin >> *p;
	}
}

void ArrayExtension::randomArray(int * array, int n)
{
	if (array == nullptr)
	{
		throw std::invalid_argument("Array can not be null.");
	}

	if (n <= 0)
	{
		throw std::invalid_argument("Count of array elements can not be less or equal 0.");
	}

	for (int* p = array, i = 1; p < array + n; p++, i++)
	{
		*p = rand() % 20 - 9;
	}
}

void ArrayExtension::displayArray(int * array, int n)
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

	std::cout << std::endl;
}

void ArrayExtension::displayArray(double * array, int n)
{
	if (array == nullptr)
	{
		throw std::invalid_argument("Array can not be null.");
	}

	if (n <= 0)
	{
		throw std::invalid_argument("Count of array elements can not be less or equal 0.");
	}

	for (double* p = array; p < array + n; p++)
	{
		std::cout << *p << " ";
	}

	std::cout << std::endl;
}

int* ArrayExtension::createKeys(int* array, int n)
{
	int* keys = ArrayExtension::allocateMemory(n);

	for (int i = 0; i < n; i++)
	{
		keys[i] = ArrayExtension::sqr(array[i]);
	}

	return keys;
}

int * ArrayExtension::createKeys(int * array, int n, key key)
{
	int* keys = ArrayExtension::allocateMemory(n);

	for (int i = 0; i < n; i++)
	{
		keys[i] = key(array[i]);
	}

	return keys;
}

int * ArrayExtension::createKeys(double * array, int n, keyD key)
{
	int* keys = ArrayExtension::allocateMemory(n);

	for (int i = 0; i < n; i++)
	{
		keys[i] = key(array[i]);
	}

	return keys;
}

void ArrayExtension::swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

int ArrayExtension::countOfUnitInBinaryPresentation(int number)
{
	int k = 0;

	number = abs(number);

	while (number)
	{
		int rest = number % 2;

		if (rest == 1)
		{
			k++;
		}

		number /= 2;
	}

	return k;
}

int ArrayExtension::countOfZerosInBinaryPresentation(int number)
{
	int k = 0;

	number = abs(number);

	while (number)
	{
		int rest = number % 2;

		if (rest == 0)
		{
			k++;
		}

		number /= 2;
	}

	return k;
}

void ArrayExtension::bubbleSort(int* array, int n)
{
	bool swapped = true;

	int i = 1;

	while (swapped)
	{

		swapped = false;

		for (int j = n - 1; j >= i; j--)
		{
			if (array[j] < array[j - 1])
			{
				ArrayExtension::swap(array[j], array[j - 1]);
				swapped = true;
			}
		}

		i++;
	}
}

void ArrayExtension::bubbleSort(int* array, int* keys, int n)
{
	bool swapped = true;

	int i = 1;

	while (swapped)
	{

		swapped = false;

		for (int j = n - 1; j >= i; j--)
		{
			if (keys[j] < keys[j - 1])
			{
				ArrayExtension::swap(array[j], array[j - 1]);
				ArrayExtension::swap(keys[j], keys[j - 1]);
				swapped = true;
			}
		}

		i++;
	}
}

void ArrayExtension::bubbleSort(int* array, int* keys, int n, key key)
{
	bool swapped = true;

	int i = 1;

	while (swapped)
	{

		swapped = false;

		for (int j = n - 1; j >= i; j--)
		{
			if (key(keys[j]) < key(keys[j - 1]))
			{
				ArrayExtension::swap(array[j], array[j - 1]);
				ArrayExtension::swap(keys[j], keys[j - 1]);
				swapped = true;
			}
		}

		i++;
	}
}

void ArrayExtension::bubbleSort(int* array, int* keys, int n, int* indexes, int m)
{
	bool swapped = true;

	int i = 1;

	while (swapped)
	{

		swapped = false;

		for (int j = m - 1; j >= i; j--)
		{
			if (keys[indexes[j]] < keys[indexes[j - 1]])
			{
				ArrayExtension::swap(array[indexes[j]], array[indexes[j - 1]]);
				ArrayExtension::swap(keys[indexes[j]], keys[indexes[j - 1]]);
				swapped = true;
			}
		}

		i++;
	}
}

void ArrayExtension::bubbleSort(int* array, int n, key key)
{
	bool swapped = true;

	int i = 1;

	while (swapped)
	{
		swapped = false;

		for (int j = n - 1; j >= i; j--)
		{
			if (key(array[j]) < key(array[j - 1]))
			{
				ArrayExtension::swap(array[j], array[j - 1]);
				swapped = true;
			}
		}

		i++;
	}
}

int ArrayExtension::sqr(int number)
{
	return number * number;
}


int ArrayExtension::inputNumber()
{
	int n;
	cout << "Enter number: ";
	cin >> n;

	return n;
}

void ArrayExtension::deleteElements(int* array, int n, int& m)
{
	m = 0;

	for (int i = 0; i < n - 1 - m; i++)
	{
		for (int j = i + 1; j < n - m; j++)
		{
			if (array[i] == array[j])
			{
				for (int k = j; k < n - m; k++)
				{
					array[k] = array[k + 1];
				}

				i--;
				m++;
			}
		}

	}
}

void ArrayExtension::inputArrayNew(int* array, int* arrayNew, int n, int& m)
{
	m = 0;
	int k = 0;
	bool isMoved = false;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (array[i] == array[j] && isMoved == false)
			{
				arrayNew[k] = shifter(array[i]);
				isMoved = true;
				k++;
				m++;
			}
		}

		isMoved = false;
	}
}

int ArrayExtension::shifter(int number)
{
	int rem = 0;
	int newNumber = 0;
	int i = 0;
	int n = number;

	while (number)
	{
		rem = number % 10;
		number /= 10;
		i++;
	}
	rem = 0;

	for (int j = i; j > 0; j--)
	{
		rem = n % 10;
		newNumber = newNumber + rem * pow(10, j - 1);
		n /= 10;
	}

	return newNumber;
}

int ArrayExtension::differenceOfRemainders(int number, int a, int b)
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

void ArrayExtension::mergeSort(int* array, int n, Key key)
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

void ArrayExtension::merge(int* array, int* left, int* right, int p, int q, Key key)
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