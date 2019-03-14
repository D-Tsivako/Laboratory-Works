//45 67 45 45 32 6 71 (7, 17) -->  71 67 45 32 6
//67 67 45 89 88 54 54 21 54 13 (4, 7) -->  89 88 67 54 45 21 13
//2 2 2 2 2 2 2 2 (5, 8) --> 2
//34 65 22 47 87 33 59 (11, 3) -->  87 65 59 47 34 33 22

#include <iostream>
#include "ArrayLibrary.h"

using namespace std;
using namespace ArrayExtension;

int main()
{
	int n = inputNumber();
	int* array = allocateMemory(n);

	cout << "Enter array" << endl;
	inputArray(array, n);
	displayArray(array, n);

	int m = 0;

	int *newArray = allocateMemory(n);
	inputArrayNew(array, newArray, n, m);
	if (m == 0)
	{
		cout << "There is no excess elements." << endl;
	}
	else
	{
		deleteElements(newArray, n, m);
		cout << "Array of shifters: ";
		displayArray(newArray, n - m - 1);
	}

	deleteElements(array, n, m);
	cout << "Array without excess elements: ";
	displayArray(array, n - m);

	int a, b;
	cout << "a: ";
	a = inputNumber();
	cout << "b: ";
	b = inputNumber();

	mergeSort(array, n - m, differenceOfRemainders);
	cout << "Sorted array: ";
	displayArray(array, n - m);

	system("pause");
	return 0;
}