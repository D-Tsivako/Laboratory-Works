#include <iostream>
#include <fstream>
#include "ArrayLibrary.h"

using namespace std;
using namespace ArrayExtension;

void CreateFile(char* fileName, int n);
int ContentsFile(char*);
int* InitArray(char*, int);
void BubbleSort(int*, int);
void AddFile(char*, int*, int);

int main()
{
	char fileName[] = "C:/Users/Lenovo/Documents/vs/17.04.2019/test.txt";

	int n = inputNumber();

	CreateFile(fileName, n);

	int count = ContentsFile(fileName);
	int* array = InitArray(fileName, count);

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
	}

	deleteElements(array, n, m);

	int a, b;
	cout << "a: ";
	a = inputNumber();
	cout << "b: ";
	b = inputNumber();

	mergeSort(array, n - m, differenceOfRemainders);
	AddFile(fileName, array, count - m);

	system("pause");
	return 0;
}

void CreateFile(char* fileName, int n)
{
	ofstream streamOut(fileName);

	if (!streamOut.is_open())
	{
		cout << "Cannot open file to write!" << endl;
		system("pause");
		exit(1);
	}

	for (int i = 1; i <= n; i++)
	{
		int temp;
		cout << "enter value # " << i << " : ";
		cin >> temp;
		streamOut.width(5);
		streamOut << temp;
	}

	streamOut.close();
}

int ContentsFile(char* fileName)
{
	ifstream streamIn(fileName);

	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}

	int count = 0, term;

	while (!streamIn.eof())
	{
		streamIn >> term;
		count++;
	}
	streamIn.close();
	return count;
}

int* InitArray(char* fileName, int n)
{
	ifstream streamIn(fileName);
	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		streamIn >> arr[i];
	streamIn.close();
	return arr;
}

void AddFile(char* fileName, int* arr, int n)
{
	ofstream streamOut(fileName, ios::app);

	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}
	streamOut << "\nSorted:\n";
	for (int i = 0; i < n; i++)
	{
		streamOut.width(5);
		streamOut << arr[i];
	}
	streamOut.close();
}