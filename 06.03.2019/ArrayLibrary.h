#pragma once

namespace ArrayExtension
{
	typedef int(*key)(int);
	typedef int(*Key)(int, int, int);
	typedef int(*keyD)(double);

	int* allocateMemory(int);
	
	double* allocateMemoryDouble(int);

	void inputArray(int *, int);

	void inputArray(double *, int);

	void randomArray(int *, int);

	void displayArray(int *, int);
	
	void displayArray(double *, int);

	void bubbleSort(int *, int);

	void bubbleSort(int*, int*, int);

	void bubbleSort(int*, int*, int, key);

	void bubbleSort(int*, int*, int, int*, int);

	void bubbleSort(int *, int, key);
	//void bubbleSort(int *, int, int(*key)(int));

	void swap(int&, int&);

	int* createKeys(int*, int);

	int* createKeys(int*, int, key);
	
	int* createKeys(double*, int, keyD);

	int countOfUnitInBinaryPresentation(int);

	int countOfZerosInBinaryPresentation(int);

	int sqr(int);

	int inputNumber();

	void deleteElements(int*, int, int&);

	void inputArrayNew(int*, int*, int, int&);

	int shifter(int);

	int differenceOfRemainders(int, int, int);

	void mergeSort(int*, int, Key);

	void merge(int*, int*, int*, int, int, Key);
}