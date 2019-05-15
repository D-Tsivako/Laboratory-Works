#define _CRT_SECURE_NO_WARNINGS
#include <io.h>
#include <fstream>
#include <iostream>
#include "Building.h"

using namespace std;

void InitFile(char*);
void DisplayFile(char*);
void AddToEndFile(char*);
void ChangeFile(char*);
void RemoveFromFile(char*);
void InitNumber(long&);
void SystemFun();
void InitNameFile(char*);
void SortingFile(char*);
int Menu();
int SortingMenu();

int main()
{
	char fileName[N] = "Building.bin";
	enum { Init = 1, Create, Display, Add, Change, Remove, Sort, Exit };
	while (true)
	{
		int key = Menu();
		if (key == Exit)
			return 0;
		system("cls");
		switch (key)
		{
		case Init:
			InitNameFile(fileName);
			SystemFun();
			break;
		case Create:
			InitFile(fileName);
			SystemFun();
			break;
		case Display:
			DisplayFile(fileName);
			SystemFun();
			break;
		case Add:
			AddToEndFile(fileName);
			SystemFun();
			break;
		case Change:
			ChangeFile(fileName);
			SystemFun();
			break;
		case Remove:
			RemoveFromFile(fileName);
			SystemFun();
			break;
		case Sort:
			SortingFile(fileName);
			SystemFun();
			break;
		default:
			cout << "\nIncorrect input! Try again!";
			SystemFun();
		}
	}
}

void InitFile(char* fileName)
{
	ofstream streamOut;
	streamOut.open(fileName, ios::binary);
	if (!streamOut.is_open())
	{
		cout << "\nCan't open file to write!";
		SystemFun();
		return;
	}
	int bufSize = sizeof(Building);
	Building house;
	char ok = 'y';
	while (ok == 'y')
	{
		house.EnterBuilding();
		streamOut.write((char*)&house, bufSize);
		cout << " If you want to continue, press 'y' :";
		cin >> ok;
	}
	streamOut.close();
}

void AddToEndFile(char* fileName)
{
	ofstream streamOut(fileName, ios::app | ios::binary);
	if (!streamOut.is_open())
	{
		cout << "Can't open file to write!";
		SystemFun();
		return;
	}
	int bufSize = sizeof(Building);
	Building house;
	char Ok = 'y';
	while (Ok == 'y')
	{
		house.EnterBuilding();
		streamOut.write((char*)&house, bufSize);
		cout << " If you want to continue, press 'y' : ";
		cin >> Ok;
	}
	streamOut.close();
}

void ChangeFile(char* fileName)
{
	fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
	if (!streamInOut)
	{
		cout << "Can't open file to read and write!";
		SystemFun();
		return;
	}
	int bufSize = sizeof(Building);
	Building house;
	long position;
	InitNumber(position);
	streamInOut.seekp((position - 1) * bufSize, ios::beg);
	house.EnterBuilding();
	streamInOut.write((char*)&house, bufSize);
	streamInOut.close();
}

void RemoveFromFile(char* fileName)
{
	fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
	if (!streamInOut.is_open())
	{
		cout << "Can't open file to read and write!";
		SystemFun();
		return;
	}
	streamInOut.seekp(0, ios::end);
	long n = streamInOut.tellp();
	int bufSize = sizeof(Building);
	Building house;
	long Position;
	InitNumber(Position);
	streamInOut.seekp(Position * bufSize, ios::beg);
	while (streamInOut.read((char*)&house, bufSize))
	{
		streamInOut.seekp(-2 * bufSize, ios::cur);
		streamInOut.write((char*)&house, bufSize);
		streamInOut.seekp(bufSize, ios::cur);
	}
	streamInOut.close();
	int diskriptorFile = _open(fileName, 2);
	_chsize(diskriptorFile, n - bufSize);
	_close(diskriptorFile);
}

void SortingFile(char* fileName)
{
	bool flag = true;
	while (flag)
	{
		fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
		if (!streamInOut.is_open())
		{
			cout << "Can't open file to read and write!";
			SystemFun();
			return;
		}
		flag = false;
		Building houseOne, houseTwo;
		int bufSize = sizeof(Building);
		streamInOut.read((char*)&houseOne, bufSize);
		enum { Address = 1, Type, NumberOfFloors, NumberOfApartments, Lifetime, Exit };
		int key = SortingMenu();
		if (key == Exit)
		{
			return;
		}
		system("cls");
		switch (key)
		{
		case Address:
			while (streamInOut.read((char*)&houseTwo, bufSize))
			{
				if (houseTwo.GetAddress()[0] < houseOne.GetAddress()[0])
				{
					streamInOut.seekp(-2 * bufSize, ios::cur);
					streamInOut.write((char*)&houseTwo, bufSize);
					streamInOut.write((char*)&houseOne, bufSize);
					flag = true;
				}
				streamInOut.seekp(-bufSize, ios::cur);
				streamInOut.read((char*)&houseOne, bufSize);
			}
			break;
		case Type:
			while (streamInOut.read((char*)&houseTwo, bufSize))
			{
				if (houseTwo.GetType()[0] < houseOne.GetType()[0])
				{
					streamInOut.seekp(-2 * bufSize, ios::cur);
					streamInOut.write((char*)&houseTwo, bufSize);
					streamInOut.write((char*)&houseOne, bufSize);
					flag = true;
				}
				streamInOut.seekp(-bufSize, ios::cur);
				streamInOut.read((char*)&houseOne, bufSize);
			}
			break;
		case NumberOfFloors:
			while (streamInOut.read((char*)&houseTwo, bufSize))
			{
				if (houseTwo.GetNumberOfFloors()[0] < houseOne.GetNumberOfFloors()[0])
				{
					streamInOut.seekp(-2 * bufSize, ios::cur);
					streamInOut.write((char*)&houseTwo, bufSize);
					streamInOut.write((char*)&houseOne, bufSize);
					flag = true;
				}
				streamInOut.seekp(-bufSize, ios::cur);
				streamInOut.read((char*)&houseOne, bufSize);
			}
			break;
		case NumberOfApartments:
			while (streamInOut.read((char*)&houseTwo, bufSize))
			{
				if (houseTwo.GetNumberOfApartments()[0] < houseOne.GetNumberOfApartments()[0])
				{
					streamInOut.seekp(-2 * bufSize, ios::cur);
					streamInOut.write((char*)&houseTwo, bufSize);
					streamInOut.write((char*)&houseOne, bufSize);
					flag = true;
				}
				streamInOut.seekp(-bufSize, ios::cur);
				streamInOut.read((char*)&houseOne, bufSize);
			}
			break;
		case Lifetime:
			while (streamInOut.read((char*)&houseTwo, bufSize))
			{
				if (houseTwo.GetLifetime() < houseOne.GetLifetime())
				{
					streamInOut.seekp(-2 * bufSize, ios::cur);
					streamInOut.write((char*)&houseTwo, bufSize);
					streamInOut.write((char*)&houseOne, bufSize);
					flag = true;
				}
				streamInOut.seekp(-bufSize, ios::cur);
				streamInOut.read((char*)&houseOne, bufSize);
			}
			break;
		default:
			cout << "\nIncorrect input! Try again!";
			SystemFun();
		}
		streamInOut.close();
	}
}

void DisplayFile(char* fileName)
{
	ifstream streamIn(fileName, ios::binary);
	if (!streamIn.is_open())
	{
		cout << "Can't open file to read!";
		SystemFun();
		return;
	}
	int bufSize = sizeof(Building);
	Building* house = new Building;
	while (streamIn.read((char*)house, bufSize))
	{
		house->DisplayBuilding();
	}
	streamIn.close();
}

void InitNumber(long& n)
{
	cout << "Enter the number of record:" << endl;
	cin >> n;
	system("cls");
}

void SystemFun()
{
	cout << endl;
	system("pause");
	system("cls");
}

void InitNameFile(char* fileName)
{
	cout << "Enter the name of file: " << endl;
	cin.ignore();
	cin.getline(fileName, 256, '\n');
	system("cls");
}

int Menu()
{
	int k;
	cout << "\n Enter the number - the mode of operations with the file:"
		"\n 1 - INITIALIZE THE NAME OF THE FILE"
		"\n 2 - FORMATE OF THE FILE"
		"\n 3 - VIEW THE CONTENT OF THE FILE"
		"\n 4 - ADD AN ELEMENT TO THE FILE"
		"\n 5 - CHANGE AN ELEMENT IN THE FILE"
		"\n 6 - REMOVE AN ELEMENT IN THE FILE"
		"\n 7 - SORT AN ELEMENT IN THE FILE"
		"\n 8 - EXIT\n";
	cin >> k;
	return k;
}

int SortingMenu()
{
	int k;
	cout << "\n Enter the number of the characteristic:"
		"\n 1 - ADDRESS"
		"\n 2 - TYPE"
		"\n 3 - NUMBER OF FLOORS"
		"\n 4 - NUMBER OF APARTMENTS"
		"\n 5 - LIFETIME"
		"\n 6 - EXIT\n";
	cin >> k;
	return k;
}